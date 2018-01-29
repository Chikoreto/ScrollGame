#include "Config.hpp"

void Config::init()
{

}

void Config::update()
{
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::MainMenu);
	}
}

void Config::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"CONFIG").drawCenter(Window::Center());
	m_data->font(L"決定ボタンでメインメニューへ").draw();
}