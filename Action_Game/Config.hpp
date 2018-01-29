#ifndef CONFIG_H
#define CONFIG_H

# include "Use_scene.hpp"

//コンフィグ画面

class Config : public MyApp::Scene
{
public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : CONFIG_H