#ifndef GAMEOVER_H
#define GAMEOVER_H

# include "Use_scene.hpp"

//ゲームオーバー

class GameOver : public MyApp::Scene
{
public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : GAMEOVER_H