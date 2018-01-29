#ifndef GAME_H
#define GAME_H

# include "Use_scene.hpp"
#include "Map.hpp"
#include "Player.hpp"

//ÉQÅ[ÉÄñ{ëÃ

class Game : public MyApp::Scene
{
private:
	Map map;
	Player player;


public:
	void init() override;
	void update() override;
	void draw() const override;

};
#endif  //include guard : GAME_H