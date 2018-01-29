#include "Game.hpp"



void Game::init()
{
	map.Map_Load(1,1);
	player = Player(&m_data->key_input);
	//player.ini();
}

void Game::update()
{


	player.set_block_hit_bocks(map.get_block_hit_box());

	player.update();

	map.set_moved_position(player.get_player_position());

	map.update();


	//決定でリザルト
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::Result);
	}

	//キャンセルでステージセレクト
	if (m_data->key_input.is_cancel_key_press())
	{
		changeScene(SceneName::StageSelect);
	}
}

void Game::draw() const
{

	const static Texture texture = Texture(L"DATA/backImage.png");


	texture.draw();
	map.Map_draw();
	player.draw();

#if 0
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"GAME").drawCenter(Window::Center());
	m_data->font(L"決定ボタンでリザルト\nキャンセルでステージ選択へ").draw();
#endif
}
