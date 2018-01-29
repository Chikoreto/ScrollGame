#include "StageSelect.hpp"

void StageSelect::init()
{

}

void StageSelect::update()
{
	//����ŃQ�[���{��
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::Game);
	}

	//�L�����Z���Ń��[���h�Z���N�g
	if (m_data->key_input.is_cancel_key_press())
	{
		changeScene(SceneName::WorldSelect);
	}

}

void StageSelect::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"STAGE SELECT").drawCenter(Window::Center());
	m_data->font(L"����{�^���ŃQ�[���{�̂�\n�L�����Z���Ń��[���h�I��").draw();

}