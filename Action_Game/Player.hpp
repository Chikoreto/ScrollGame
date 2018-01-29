#ifndef PLAYER_H
#define PLAYER_H

#include "Object.hpp"
#include"Key_Input.hpp"

class Player :public Object
{
private:

	//プレイヤーがどこ方向の物とぶつかったかを判別するためのフラグ
	typedef struct collision_type_flag {
		bool over, down, right, left;
	}c_type_flag;

	c_type_flag c_t_flag;
	bool is_jump;					//プレイヤーがジャンプ中か
	int x, y;						//座標(マス)
	int player_w, player_h;			//Player画像の幅、高さ
	int jump_frame;					//何フレーム上昇するか
	double xv, yv;					//x,yの移動量
	double fall_speed;					//落下速度
	unsigned short move_res;					//どの方向に移動するかを入れる(左右下)

	int32 draw_pos_x, draw_pos_y;	//描画時のプレイヤの座標(画面の中心)

	unsigned int player_state;				//プレイヤーの状態を示す

	Vec2 position;					//実座標
	Vec2 next_position;				//移動後の座標
	Rect hit_box;					//当たり判定用
	Key_Input *m_key;				//key_Inputのポインタ
	Image image;					//Player画像
	Array<Texture> texture;			//playerテクスチャ
	FilePath faile_name;				//画像ファイル名
	Array<Rect> block_hit_bocks;	//全部ロックの当たり判定格納

	Vec2 re_position_temp;			//ブロックに渡す用(画面中央の座標を足す)

	double temp;
	double y_prev;

public:
	Player();				//コンストラクタ
	Player(Key_Input *key);
	
	void ini();
	void update();
	void draw() const;

	void set_block_hit_bocks(Array<Rect> b_hit_bocks);

	//移動処理
	void move();
	//ジャンプ
	void jump();
	//衝突判定
	void collision();

	//プレイヤー座標を取得
	Vec2 get_player_position();

};

#endif  //include guard : PLAYER_H