#ifndef STAGESELECT_H
#define STAGESELECT_H

# include "Use_scene.hpp"

//ステージセレクト

class StageSelect : public MyApp::Scene
{
public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : STAGESELECT_H