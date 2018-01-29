#ifndef TITLE_H
#define TITLE_H

# include "Use_scene.hpp"

//ゲームタイトル

class Title : public MyApp::Scene
{
private:

public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : TITLE_H