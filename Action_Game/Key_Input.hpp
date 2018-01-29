#ifndef KEY_INPUT_H
#define KEY_INPUT_H

# include <Siv3D.hpp>
#include"constant_num.hpp"

//入力に関するクラス
//Inputのラッパー
//Scene共有に宣言するためSceneないなら使える
//実際の入力検知はsiv3dクラスInputが行う
//このクラスはその判定用(キーコンフィグ対応予定)

class Key_Input
{
private:


	
	//決定キー1,2,3
	wchar decide_key_1, decide_key_2, decide_key_3;
	//キャンセルキー1,2,3
	wchar cancel_key_1, cancel_key_2, cancel_key_3;
	//移動(左右下)キー
	wchar move_left, move_right, move_down,move_up;
	//ジャンプキー
	wchar jump_key;

	Key decide_1, decide_2, decide_3;
	Key cancel_1, cancel_2, cancel_3;
	Key move_l, move_r, move_d, move_u;
	Key jump;

public:
	//初期化
	void init();
	//決定キーを押したかの判定
	bool is_decide_key_press();
	//cancelキーを押したのかの判定
	bool is_cancel_key_press();

	//どの移動ボタンを押したかの判定
	unsigned short move_key_press();

	//ジャンプが押されたかの判定
	bool is_jump_key_press();

};

#endif  //include guard : KEY_INPUT_H

