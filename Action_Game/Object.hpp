#ifndef OBJECT_H
#define OBJECT_H

#include <Siv3D.hpp>

class Object
{
private:
	Vec3 m_position;		//Objectの座標
	Texture m_texture;		//画像ハンドル

public:
	virtual void ini() = 0;				//初期化
	virtual void update() = 0;			//更新
	virtual void draw() const = 0;			//描画
//	virtual void draw(Texture texture,int number) = 0;			//描画(テクスチャを渡す場合) 
};


#endif  //include guard : OBJECT_H
