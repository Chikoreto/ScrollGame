#include "Result.hpp"

void Result::init()
{

}

void Result::update()
{
	//決定でメインメニュー
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::MainMenu);
	}

}

void Result::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"リザルト").drawCenter(Window::Center());
	m_data->font(L"決定ボタンでメインメニューへ").draw();
}