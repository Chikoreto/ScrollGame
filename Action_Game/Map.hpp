#ifndef MAP_H
#define MAP_H

#include <Siv3D.hpp>
#include "Block.hpp"

class Map
{
private:
	Array<Block> blocks;					//�}�b�v�̑S�u���b�N
	Array<Texture> block_texture;			//�g�p����u���b�N�̃e�N�X�`��
	Array<int> use_texture_num;				//�g�p����e�N�X�`����ID
	Array<Rect> block_hit_box;				//�u���b�N�̓����蔻��i�[

	CSVReader map_data_csv;					//�}�b�v�f�[�^�ǂݍ���
	int w_max, h_max;						//�}�b�v�̍ő�}�X��
	int texture_num;						//�ǂݍ��ރe�N�X�`���̐�
	int map_scene;							//�}�b�v�̏��
	FilePath fail_name;						//�ǂݍ��݃t�@�C���̖��O
	Image block_image;						//�S�����b�N�摜�ǂݍ��ݐ؂����ăe�N�X�`���ɓ����
	const int block_size;					//�u���b�N�̃T�C�Y(32�Œ�)
	int block_num_temp;						//�u���b�NID�ϐ����Ɍ��݂̃u���b�N����\��
	int map_block_num;						//csv�t�@�C������ǂݍ��񂾂��̃}�b�v�Ŏg���P�u���b�N��ID�u���b�N�̏������ɂ����g��Ȃ����ߎg���܂킷

	Vec2 moved_position;					//�u���b�N�̈ړ������v�Z�p���W(�v���C���[�̍��W)

	Array<Image> image;

public:
	Map::Map();								//�R���X�g���N�^
	int Map_Load(int world,int field);		//�}�b�v�f�[�^�̃��[�h
	void update();							//�X�V

	void Map_draw() const;						//map�`��
	Array<Rect> get_block_hit_box();

	void set_moved_position(Vec2 position);
};


#endif     //include guard : MAP_H