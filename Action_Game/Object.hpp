#ifndef OBJECT_H
#define OBJECT_H

#include <Siv3D.hpp>

class Object
{
private:
	Vec3 m_position;		//Object�̍��W
	Texture m_texture;		//�摜�n���h��

public:
	virtual void ini() = 0;				//������
	virtual void update() = 0;			//�X�V
	virtual void draw() const = 0;			//�`��
//	virtual void draw(Texture texture,int number) = 0;			//�`��(�e�N�X�`����n���ꍇ) 
};


#endif  //include guard : OBJECT_H
