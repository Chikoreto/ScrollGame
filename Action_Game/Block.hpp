#ifndef BLOCK_H
#define BLOCK_H

#include"Object.hpp"

class Block : public Object
{
private:
	int block_type;							//ブロックの種類
	int x, y;								//ブロックの座標(番号)
	double w, h ;							//ブロックの座標(実座標)
	int block_size;							//ブロックの大きさ
	Texture texture;						//使用するテクスチャ
	Image image;
	Rect hit_box;							//当たり判定用
	Vec2 moved_position;					//ブロックの移動距離計算用座標(プレイヤーの座標)

public:
	Block();
	Block(int type, Image image, int xx, int y,int block_size);
	void ini();			//初期化
	void update();		//更新
	void draw() const;		//描画引数なし

	int get_x();
	int get_y();

	int get_block_type();			//ブロックタイプ取得
	Rect get_hit_box();				//当たり判定用を渡す。
	void set_moved_position(Vec2 position);		//ブロック移動用座標(プレイヤー座標)取得
};


#endif     //include guard : BLOCK_H
