#include "Player.h"
#include "DxLib.h"

void PlayerInfo::Init() {

	m_handle = LoadGraph(PLAYER_PATH);
	m_pos.x = 500;
	m_pos.y = 200;
	m_speedX = 2.0f;
	m_isUse = true;

}

void PlayerInfo::Step() {

	//¶ˆÚ“®‘€ì
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_pos.x -= m_speedX;
	}
	//‰EˆÚ“®‘€ì
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_pos.x += m_speedX;
	}

}


void PlayerInfo::Draw() {
	// •`‰æ
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}


void PlayerInfo::Fin() {

	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_isUse = true;
}