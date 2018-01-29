#include "Player.hpp"
#include <math.h>

//�f�t�H���g�R���X�g���N�^�@�g��Ȃ�
Player::Player()
{
}

//�v���C���[�R���X�g���N�^(�L�[���͎擾�|�C���^����)
Player::Player(Key_Input *key)
	:m_key(key),x(0),y(0),xv(0),yv(0),player_w(32),player_h(32),fall_speed(8),
	player_state(0),draw_pos_x(Window::Width()/2),draw_pos_y(Window::Height()/2),re_position_temp(0,0)
{
	
	//�摜�t�@�C���A�h���X�ݒ�
	faile_name = Format(L"DATA/player.png");

	//�摜���[�h
	image = Image(faile_name);

	//�摜���e�N�X�`���ɕϊ����Ĕz��ɃZ�b�g
	texture.push_back(Texture(image));

	//�v���C���[�̈ʒu�ݒ�
	position = Vec2(x, y);
	//�q�b�g�{�b�N�X���v���C���[�Ɠ����ꏊ�ɍ쐬
	hit_box = Rect(position.x, position.y, player_w);

}


//������
void Player::ini()
{
#if 0
	//�v���C���[�̈ʒu�ݒ�
	position = Vec2(x, y);
	//�q�b�g�{�b�N�X���v���C���[�Ɠ����ꏊ�ɍ쐬
	hit_box = Rect(position.x,position.y,player_w);
#endif
}

void Player::update()
{
	
	//�v���C���[�̈ړ�����
	move();


	//�W�����v
	jump();



	//���̍��W���Z�b�g����
	next_position.x = (int) position.x + xv;
	next_position.y = (int) position.y + fall_speed + yv;

	//�����蔻��
	//�u���b�N�ƂԂ���������W���X�V���Ȃ�
	collision();

	
	if (position.y > 720+draw_pos_y)
	{
		position.x = 0;
		position.y = 0;
	}


}

void Player::draw() const 
{

//	texture[0].draw(position);
	texture[0].draw(draw_pos_x,draw_pos_y);
//	hit_box.draw(Palette::Green);
}


void Player::set_block_hit_bocks(Array<Rect>  b_hit_bocks)
{
	block_hit_bocks = b_hit_bocks;
}


void Player::move()
{
	//�ǂ̈ړ��L�[��������Ă��邩�擾
	move_res = m_key->move_key_press();

	//�ǂ̕����Ɉړ����邩
	switch (move_res)
	{
		//��
	case US_MOVE_L:
		xv = -2;
		break;

		//�E
	case US_MOVE_R:
		xv = 2;
		break;

		//��
	case US_MOVE_D:
		break;

		//��
	case US_MOVE_U:
		break;

		//����ȊO
	default:
		xv = 0;
		break;
	}


}

//�W�����v����
void Player::jump()
{
	//�W�����v����

	//�W�����v�L�[�����ꂽ��
	is_jump = m_key->is_jump_key_press();

	//�W�����v�L�[�������ꂽ���A�W�����v������Ȃ�
	if (is_jump && player_state != IS_JUMP)
	{
		//�W�����v�t���[�����Z�b�g����
		jump_frame = 50;
		//�v���C���[�̃X�e�[�^�X���W�����v���ɕύX
		player_state = IS_JUMP;
		//�㏸���x��ݒ�
		yv = -16;

	}

	//�㏸����
	if (jump_frame > 0 && player_state == IS_JUMP)
	{
		//�㏸���Ԃ��f�N�������g
		jump_frame--;

		if (jump_frame > 30)
		{
			yv = -16;
		}
		else
		{
			yv -=  yv / 20;
		}

		//�㏸���Ԃ��I�������
		if (jump_frame <= 0)
		{
			//player_state = NO_IS_JUMP;
			yv = 0;
		}

	}
}


void Player::collision()
{
	c_t_flag.down = false;
	c_t_flag.over = false;
	c_t_flag.left = false;
	c_t_flag.right = false;

	//y�����ړ���u���b�N�ɓ����邩
	hit_box.setPos(position.x, next_position.y);

	for (int i = 0; i < block_hit_bocks.size(); i++)
	{
		//�u���b�N�ƏՓ˂��邩
		if (hit_box.intersects(block_hit_bocks[i]))
		{
			//���݂Ǝ��̍��W�����ď㉺�ǂ���̃u���b�N�ɓ�������������
			if (next_position.y > position.y)
			{
				//�v���C���[�̉��ӂ�������
				c_t_flag.down = true;
				//�W�����v�t���O�I�t
				player_state = NO_IS_JUMP;
			}
			else {
				//�v���C���[�̏�ӂ�������
				c_t_flag.over = true;
			}

			//�u���b�N�ƏՓ˂�����A�Փ˂��Ȃ��Ƃ���܂Œl�������߂��čX�V����
			while (hit_box.intersects(block_hit_bocks[i]))
			{
				next_position.y--;
				hit_box.setPos(position.x, next_position.y);

			}
//			next_position.y = position.y;
			break;
		}
	}

	//x�����ړ���u���b�N�ɓ����邩
	hit_box.setPos(next_position.x, position.y);

	for (int i = 0; i < block_hit_bocks.size(); i++)
	{

		if (hit_box.intersects(block_hit_bocks[i]))
		{
			next_position.x = position.x;
			break;
		}
	}

	position = next_position;
	hit_box.setPos(position.x, position.y);
}


Vec2 Player::get_player_position()
{

	re_position_temp.x =  draw_pos_x - position.x;
	re_position_temp.y =  draw_pos_y - position.y;

	return re_position_temp;
}

