#include "StageSelect.hpp"

void StageSelect::init()
{

}

void StageSelect::update()
{
	//決定でゲーム本体
	if (m_data->key_input.is_decide_key_press())
	{
		changeScene(SceneName::Game);
	}

	//キャンセルでワールドセレクト
	if (m_data->key_input.is_cancel_key_press())
	{
		changeScene(SceneName::WorldSelect);
	}

}

void StageSelect::draw() const
{
	Window::ClientRect().draw(Palette::Green);
	m_data->font(L"STAGE SELECT").drawCenter(Window::Center());
	m_data->font(L"決定ボタンでゲーム本体へ\nキャンセルでワールド選択").draw();

}