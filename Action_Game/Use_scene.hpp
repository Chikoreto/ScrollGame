#ifndef USE_SCENE_H
#define USE_SCENE_H

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "common.hpp"

//シーン遷移に使用する変数の名称定義
//定数の定義を行う

enum class SceneName
{
	Title,
	MainMenu,
	Config,
	WorldSelect,
	StageSelect,
	Game,
	Result,
	GameOver,
};

using MyApp = SceneManager<SceneName,Common_Data_Scene>;


#endif  //include guard : USE_SCENE_H