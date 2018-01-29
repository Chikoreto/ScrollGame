#include "WorldSelect.hpp"

void WorldSelect::init()
{

}

void WorldSelect::update()
{
	//����ŃX�e�[�W�Z���N�g
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::StageSelect);
	}

	//�L�����Z���Ń��C�����j���[
	if (m_data->key_input.is_cancel_key_press())
	{
		changeScene(SceneName::MainMenu);
	}
}

void WorldSelect::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"WORLD SELECT").drawCenter(Window::Center());
	m_data->font(L"����{�^���ŃX�e�[�W�Z���N�g��\n�L�����Z���Ń��C�����j���[").draw();
}