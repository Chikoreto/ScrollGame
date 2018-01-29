#include "Key_Input.hpp"

//������������
//�{���̓t�@�C���ǂݍ��݂Ƃ����邯�Ǎ��͔�΂������Ŏw�肵�Ă���
void Key_Input::init()
{
	//����L�[1,2,3
	decide_key_1 = 0x90;		//space
	decide_key_2 = 0x0D;		//enter
	decide_key_3 = 0x5A;		//z
	//�L�����Z���L�[1,2,3
	cancel_key_1 = 0x08;		//Backspace
	cancel_key_2 = 0x58;		//x
	cancel_key_3 = 0x51;		//q
	//�ړ��L�[
	move_left = 0x41;			//a
	move_right = 0x44;			//d
	move_down = 0x53;			//s
	move_up = 0x57;				//w

	//�W�����v�L�[
	jump_key = 0x20;				//space


	//����L�[
	decide_1 = Key(decide_key_1,Key::VirtualKeyCode{});
	decide_2 = Key(decide_key_2, Key::VirtualKeyCode{});
	decide_3 = Key(decide_key_3, Key::VirtualKeyCode{});

	//�L�����Z���L�[
	cancel_1 = Key(cancel_key_1, Key::VirtualKeyCode{});
	cancel_2 = Key(cancel_key_2, Key::VirtualKeyCode{});
	cancel_3 = Key(cancel_key_3, Key::VirtualKeyCode{});

	//�ړ��L�[
	move_l = Key(move_left, Key::VirtualKeyCode{});
	move_r = Key(move_right, Key::VirtualKeyCode{});
	move_d = Key(move_down, Key::VirtualKeyCode{});
	move_u = Key(move_up, Key::VirtualKeyCode{});

	//�W�����v
	jump = Key(jump_key, Key::VirtualKeyCode{});


}

//����������ꂽ������
bool Key_Input::is_decide_key_press()
{
	if(decide_1.pressed || decide_2.pressed || decide_3.pressed)
	{
		return true;
	}

	return false;
}

//�L�����Z���������ꂽ���̔���
bool Key_Input::is_cancel_key_press()
{
	if (cancel_1.pressed || cancel_2.pressed || cancel_3.pressed)
	{
		return true;
	}

	return false;
}

//�ǂ̈ړ��L�[�������ꂽ���̔���
unsigned short Key_Input::move_key_press()
{

	if(move_l.pressed)
	{ 
		return US_MOVE_L;
	}
	if (move_r.pressed)
	{
		return US_MOVE_R;
	}
	if (move_d.pressed)
	{
		return US_MOVE_D;
	}
	if (move_u.pressed)
	{
		return US_MOVE_U;
	}
	return US_NO_MOVE;
}


//�ǂ̈ړ��L�[�������ꂽ���̔���
bool Key_Input::is_jump_key_press()
{
	if (jump.pressed)
	{
		return true;
	}
	return false;
}


