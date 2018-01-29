#ifndef PLAYER_H
#define PLAYER_H

#include "Object.hpp"
#include"Key_Input.hpp"

class Player :public Object
{
private:

	//�v���C���[���ǂ������̕��ƂԂ��������𔻕ʂ��邽�߂̃t���O
	typedef struct collision_type_flag {
		bool over, down, right, left;
	}c_type_flag;

	c_type_flag c_t_flag;
	bool is_jump;					//�v���C���[���W�����v����
	int x, y;						//���W(�}�X)
	int player_w, player_h;			//Player�摜�̕��A����
	int jump_frame;					//���t���[���㏸���邩
	double xv, yv;					//x,y�̈ړ���
	double fall_speed;					//�������x
	unsigned short move_res;					//�ǂ̕����Ɉړ����邩������(���E��)

	int32 draw_pos_x, draw_pos_y;	//�`�掞�̃v���C���̍��W(��ʂ̒��S)

	unsigned int player_state;				//�v���C���[�̏�Ԃ�����

	Vec2 position;					//�����W
	Vec2 next_position;				//�ړ���̍��W
	Rect hit_box;					//�����蔻��p
	Key_Input *m_key;				//key_Input�̃|�C���^
	Image image;					//Player�摜
	Array<Texture> texture;			//player�e�N�X�`��
	FilePath faile_name;				//�摜�t�@�C����
	Array<Rect> block_hit_bocks;	//�S�����b�N�̓����蔻��i�[

	Vec2 re_position_temp;			//�u���b�N�ɓn���p(��ʒ����̍��W�𑫂�)

	double temp;
	double y_prev;

public:
	Player();				//�R���X�g���N�^
	Player(Key_Input *key);
	
	void ini();
	void update();
	void draw() const;

	void set_block_hit_bocks(Array<Rect> b_hit_bocks);

	//�ړ�����
	void move();
	//�W�����v
	void jump();
	//�Փ˔���
	void collision();

	//�v���C���[���W���擾
	Vec2 get_player_position();

};

#endif  //include guard : PLAYER_H