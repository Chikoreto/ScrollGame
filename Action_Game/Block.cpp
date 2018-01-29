
#include"Block.hpp"

Block::Block() {}

Block::Block(int type, Image image, int x, int y,int block_size) :block_type(type),image(Image(image)),x(x), y(y), block_size(block_size),
/*moved_position(0,0),*/texture(Texture(image)), w(x*block_size),h(y*block_size), hit_box(Rect(w, h, block_size))
{

}

//初期化
void Block::ini()
{

}

//ブロック更新
void Block::update()
{
	//hit_box.moveBy(w, h);
}

//描画引数なし
void Block::draw() const
{
	texture.draw(w+moved_position.x,h+moved_position.y);
//	hit_box.draw(Palette::Blue);


}



int Block::get_block_type()
{
	return block_type;
}

int Block::get_x()
{
	return x;
}

int Block::get_y()
{
	return y;
}

Rect Block::get_hit_box()
{
	return hit_box;
}

//ブロック移動用座標(プレイヤー座標)取得
void Block::set_moved_position(Vec2 position)
{
	moved_position = position;

}

