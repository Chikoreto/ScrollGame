#ifndef MAINMENU_H
#define MAINMENU_H

# include "Use_scene.hpp"

//メインメニュー

class MainMenu : public MyApp::Scene
{
private:

public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : MAINMENU_H