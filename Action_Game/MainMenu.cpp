#include "MainMenu.hpp"

void MainMenu::init()
{

}

void MainMenu::update()
{
	//決定でワールドセレクト
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::WorldSelect);
	}

	//キャンセルでタイトル
	if (m_data->key_input.is_cancel_key_press())
	{
		changeScene(SceneName::Title);
	}
}

void MainMenu::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"Main_Menu").drawCenter(Window::Center());
	m_data->font(L"決定ボタンでワールドセレクトへ\nキャンセルでタイトルへ").draw();
}