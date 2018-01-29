#include "Map.hpp"

//�R���X�g���N�^
Map::Map():block_size(32),moved_position(640,352)
{
	//�Ƃ肠�����u���b�N�T�C�Y�̏������̂�
}

//�}�b�v�f�[�^�̃��[�h(csv)
int Map::Map_Load(int world, int field)
{
	map_scene = 1;		//�Ƃ肠�������1�̂�
						//�ォ���ʂ͍ŏ��ɑS���ǂݍ��ނ悤�ɂ���
	fail_name = Format(L"DATA/stage_deta/world",world,L"_field", field,L"_",map_scene,L".csv");

	
	//csv�ǂݍ���

	map_data_csv.open(fail_name);
	//map_data_csv = CSVReader(fail_name);

	//�ǂݍ��ݎ��s�Ȃ�G���[��Ԃ�
	if (!map_data_csv)
	{	return -1;	}

	fail_name = Format(L"DATA/block.png");

	//�u���b�N�摜�ǂݍ���
	block_image = Image(fail_name);

	//���s�Ȃ�G���[
	if (!block_image)
	{	return -1;}

	//1�s��  ���[���h�A�X�e�[�W�A��ʐ��Ȃ̂łƂ肠��������
	//2�s��  �g�p����u���b�N(�e�N�X�`��)�̐�
	//3�s��  �g�p����u���b�N�̎��
	//4�s��  �}�b�v�T�C�Y�Aw,h�̏�
	//5�s��  �ȍ~���}�b�v�̃u���b�N�z�u

	//�u���b�N���ǂݍ���
	texture_num = map_data_csv.get<int32>(1, 0);

	//�}�b�v���ǂݎ��
	//w,h���ǂݍ���
	w_max = map_data_csv.get<int32>(3, 0);
	h_max = map_data_csv.get<int32>(3, 1);

	//�g�p�e�N�X�`��ID����
	for (int i = 0; i < texture_num; i++)
	{
		use_texture_num.push_back(map_data_csv.get<int32>(2, i));
	}

	//�摜�𕪊�����1�u���b�N���̃e�N�X�`���ɕύX
	//�S�e�N�X�`�����񂵁AID�Ɠ����ꏊ�̂Ƃ��̂ݓǂݍ��ނ悤�ɂ���
	//�\�[�g����Ă��邱�ƑO��
	//���̂��Ƃ͂Ƃ肠�����l���Ȃ�(�\��ł͔���3��10X�������Ȋ����ɂ���\��Ȃ̂�)

	block_num_temp = 0;		//���݂̃u���b�NID�̈ʒu

	for (int i = 0; i < 100; i++)
	{
		if (use_texture_num[block_num_temp] == i)
		{

			//�摜����
			//                                                  x                   y           w              h
			image.push_back(block_image.clipped((block_size*(i % 10)), (block_size*(i / 10)), block_size, block_size));
			block_texture.push_back(Texture(image[i]));

			//ID�z���1���炷
			block_num_temp++;

		}
	}


	//�u���b�N�̐ݒ�
	//�u���b�N�^�C�vID�A�e�N�X�`���A���W���w�肷��
	//�}�X�����[�v
	for (int i = 0; i < w_max * h_max; i++)
	{
		int a, b;

		int count_temp = 0;

		//�}�b�v�ɗL��u���b�N��IID�����(���ォ��E����)
		map_block_num = map_data_csv.get<int32>((i / w_max) + 4, i % w_max);


		//ID 0(�u���b�N�Ȃ�)�ȊO��������u���b�N�쐬
		if (map_block_num > 0)
		{
			//�u���b�N�쐬
			//blocks.push_back(Block(map_block_num, block_texture[map_block_num], (i % w_max)*block_size, (i / h_max)*block_size));

			blocks.push_back(Block(map_block_num, image[map_block_num-1], (i % w_max), (i / w_max),block_size));


		}

	}


	map_data_csv.close();
	block_image.clear();

	return 0;
}


//�}�b�v�`��
void Map::Map_draw() const
{
	//�u���b�N�������[�v
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].draw();
	}

}

void Map::update()
{

	block_hit_box.clear();

	//�u���b�N�����蔻������Z�b�g
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].update();
		block_hit_box.push_back(blocks[i].get_hit_box());

		//�v���C���[���W���Z�b�g
		
		blocks[i].set_moved_position(moved_position);
	}
	
}

Array<Rect> Map::get_block_hit_box()
{
	return block_hit_box;
}

void Map::set_moved_position(Vec2 position)
{
	moved_position = position;

}

