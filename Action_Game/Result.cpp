#include "Result.hpp"

void Result::init()
{

}

void Result::update()
{
	//����Ń��C�����j���[
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::MainMenu);
	}

}

void Result::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"���U���g").drawCenter(Window::Center());
	m_data->font(L"����{�^���Ń��C�����j���[��").draw();
}