#ifndef WORLDSELECT_H
#define WORLDSELECT_H

# include "Use_scene.hpp"

//���[���h�Z���N�g

class WorldSelect : public MyApp::Scene
{
public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : WORLDSELECT_H