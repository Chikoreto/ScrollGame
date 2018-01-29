#include "WorldSelect.hpp"

void WorldSelect::init()
{

}

void WorldSelect::update()
{
	//決定でステージセレクト
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::StageSelect);
	}

	//キャンセルでメインメニュー
	if (m_data->key_input.is_cancel_key_press())
	{
		changeScene(SceneName::MainMenu);
	}
}

void WorldSelect::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"WORLD SELECT").drawCenter(Window::Center());
	m_data->font(L"決定ボタンでステージセレクトへ\nキャンセルでメインメニュー").draw();
}