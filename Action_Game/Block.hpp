#ifndef BLOCK_H
#define BLOCK_H

#include"Object.hpp"

class Block : public Object
{
private:
	int block_type;							//�u���b�N�̎��
	int x, y;								//�u���b�N�̍��W(�ԍ�)
	double w, h ;							//�u���b�N�̍��W(�����W)
	int block_size;							//�u���b�N�̑傫��
	Texture texture;						//�g�p����e�N�X�`��
	Image image;
	Rect hit_box;							//�����蔻��p
	Vec2 moved_position;					//�u���b�N�̈ړ������v�Z�p���W(�v���C���[�̍��W)

public:
	Block();
	Block(int type, Image image, int xx, int y,int block_size);
	void ini();			//������
	void update();		//�X�V
	void draw() const;		//�`������Ȃ�

	int get_x();
	int get_y();

	int get_block_type();			//�u���b�N�^�C�v�擾
	Rect get_hit_box();				//�����蔻��p��n���B
	void set_moved_position(Vec2 position);		//�u���b�N�ړ��p���W(�v���C���[���W)�擾
};


#endif     //include guard : BLOCK_H
