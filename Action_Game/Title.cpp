#include "Titleh.hpp"

void Title::init()
{
	//m_data->font(30);
	m_data->key_input.init();

}

void Title::update()
{
	if (m_data->key_input.is_decide_key_press())
	{

		changeScene(SceneName::Game);

//		changeScene(SceneName::MainMenu);
	}


}

void Title::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"TITLE").drawCenter(Window::Center());
	m_data->font(L"決定ボタンでメインメニュー").draw();
}