#ifndef KEY_INPUT_H
#define KEY_INPUT_H

# include <Siv3D.hpp>
#include"constant_num.hpp"

//���͂Ɋւ���N���X
//Input�̃��b�p�[
//Scene���L�ɐ錾���邽��Scene�Ȃ��Ȃ�g����
//���ۂ̓��͌��m��siv3d�N���XInput���s��
//���̃N���X�͂��̔���p(�L�[�R���t�B�O�Ή��\��)

class Key_Input
{
private:


	
	//����L�[1,2,3
	wchar decide_key_1, decide_key_2, decide_key_3;
	//�L�����Z���L�[1,2,3
	wchar cancel_key_1, cancel_key_2, cancel_key_3;
	//�ړ�(���E��)�L�[
	wchar move_left, move_right, move_down,move_up;
	//�W�����v�L�[
	wchar jump_key;

	Key decide_1, decide_2, decide_3;
	Key cancel_1, cancel_2, cancel_3;
	Key move_l, move_r, move_d, move_u;
	Key jump;

public:
	//������
	void init();
	//����L�[�����������̔���
	bool is_decide_key_press();
	//cancel�L�[���������̂��̔���
	bool is_cancel_key_press();

	//�ǂ̈ړ��{�^�������������̔���
	unsigned short move_key_press();

	//�W�����v�������ꂽ���̔���
	bool is_jump_key_press();

};

#endif  //include guard : KEY_INPUT_H

