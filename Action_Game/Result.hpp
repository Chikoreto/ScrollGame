#ifndef RESULT_H
#define RESULT_H

# include "Use_scene.hpp"

//���U���g

class Result : public MyApp::Scene
{
public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : RESULT_H