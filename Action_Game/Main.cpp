
# include "Use_Main.hpp"

void Main()
{
	//各シーンの宣言
	MyApp manager;
	manager.add<Title>(SceneName::Title);
	manager.add<MainMenu>(SceneName::MainMenu);
	manager.add<Config>(SceneName::Config);
	manager.add<WorldSelect>(SceneName::WorldSelect);
	manager.add<StageSelect>(SceneName::StageSelect);
	manager.add<Game>(SceneName::Game);
	manager.add<Result>(SceneName::Result);
	manager.add<GameOver>(SceneName::GameOver);

	Window::Resize(1280, 720);

	Font font(30);

	while (System::Update())
	{

		font(Profiler::FPS(), L"fps").draw();
		manager.updateAndDraw();
	}
}
