
#include"Block.hpp"

Block::Block() {}

Block::Block(int type, Image image, int x, int y,int block_size) :block_type(type),image(Image(image)),x(x), y(y), block_size(block_size),
/*moved_position(0,0),*/texture(Texture(image)), w(x*block_size),h(y*block_size), hit_box(Rect(w, h, block_size))
{

}

//������
void Block::ini()
{

}

//�u���b�N�X�V
void Block::update()
{
	//hit_box.moveBy(w, h);
}

//�`������Ȃ�
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

//�u���b�N�ړ��p���W(�v���C���[���W)�擾
void Block::set_moved_position(Vec2 position)
{
	moved_position = position;

}

