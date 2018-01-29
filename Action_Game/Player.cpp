#include "Player.hpp"
#include <math.h>

//デフォルトコンストラクタ　使わない
Player::Player()
{
}

//プレイヤーコンストラクタ(キー入力取得ポインタあり)
Player::Player(Key_Input *key)
	:m_key(key),x(0),y(0),xv(0),yv(0),player_w(32),player_h(32),fall_speed(8),
	player_state(0),draw_pos_x(Window::Width()/2),draw_pos_y(Window::Height()/2),re_position_temp(0,0)
{
	
	//画像ファイルアドレス設定
	faile_name = Format(L"DATA/player.png");

	//画像ロード
	image = Image(faile_name);

	//画像をテクスチャに変換して配列にセット
	texture.push_back(Texture(image));

	//プレイヤーの位置設定
	position = Vec2(x, y);
	//ヒットボックスをプレイヤーと同じ場所に作成
	hit_box = Rect(position.x, position.y, player_w);

}


//初期化
void Player::ini()
{
#if 0
	//プレイヤーの位置設定
	position = Vec2(x, y);
	//ヒットボックスをプレイヤーと同じ場所に作成
	hit_box = Rect(position.x,position.y,player_w);
#endif
}

void Player::update()
{
	
	//プレイヤーの移動処理
	move();


	//ジャンプ
	jump();



	//次の座標をセットする
	next_position.x = (int) position.x + xv;
	next_position.y = (int) position.y + fall_speed + yv;

	//当たり判定
	//ブロックとぶつかったら座標を更新しない
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
	//どの移動キーが押されているか取得
	move_res = m_key->move_key_press();

	//どの方向に移動するか
	switch (move_res)
	{
		//左
	case US_MOVE_L:
		xv = -2;
		break;

		//右
	case US_MOVE_R:
		xv = 2;
		break;

		//下
	case US_MOVE_D:
		break;

		//上
	case US_MOVE_U:
		break;

		//それ以外
	default:
		xv = 0;
		break;
	}


}

//ジャンプ処理
void Player::jump()
{
	//ジャンプ処理

	//ジャンプキー押されたか
	is_jump = m_key->is_jump_key_press();

	//ジャンプキーが押されたかつ、ジャンプ中じゃない
	if (is_jump && player_state != IS_JUMP)
	{
		//ジャンプフレームをセットする
		jump_frame = 50;
		//プレイヤーのステータスをジャンプ中に変更
		player_state = IS_JUMP;
		//上昇速度を設定
		yv = -16;

	}

	//上昇処理
	if (jump_frame > 0 && player_state == IS_JUMP)
	{
		//上昇時間をデクリメント
		jump_frame--;

		if (jump_frame > 30)
		{
			yv = -16;
		}
		else
		{
			yv -=  yv / 20;
		}

		//上昇時間が終わったら
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

	//y軸が移動後ブロックに当たるか
	hit_box.setPos(position.x, next_position.y);

	for (int i = 0; i < block_hit_bocks.size(); i++)
	{
		//ブロックと衝突するか
		if (hit_box.intersects(block_hit_bocks[i]))
		{
			//現在と次の座標を見て上下どちらのブロックに当たったか判定
			if (next_position.y > position.y)
			{
				//プレイヤーの下辺が当たる
				c_t_flag.down = true;
				//ジャンプフラグオフ
				player_state = NO_IS_JUMP;
			}
			else {
				//プレイヤーの上辺が当たる
				c_t_flag.over = true;
			}

			//ブロックと衝突したら、衝突しないところまで値を引き戻して更新する
			while (hit_box.intersects(block_hit_bocks[i]))
			{
				next_position.y--;
				hit_box.setPos(position.x, next_position.y);

			}
//			next_position.y = position.y;
			break;
		}
	}

	//x軸が移動後ブロックに当たるか
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

