#include "Player.h"
#include "DxLib.h"

void PlayerInfo::Init() {

	m_handle = LoadGraph(PLAYER_PATH);
	m_pos.x = 500.0f;
	m_pos.y = 700.0f;
	m_speedX = 2.0f;
	m_isUse = true;

}

void PlayerInfo::Step() {

	//ç∂à⁄ìÆëÄçÏ
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_pos.x -= m_speedX;
	}
	//âEà⁄ìÆëÄçÏ
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_pos.x += m_speedX;
	}

}


void PlayerInfo::Draw() {
	// ï`âÊ
	DrawExtendGraph(m_pos.x - PLAYER_COLLISION_X / 2,
		m_pos.y - PLAYER_COLLISION_Y / 2,
		m_pos.x + PLAYER_COLLISION_X / 2,
		m_pos.y + PLAYER_COLLISION_Y / 2,
		m_handle,
		true);
}


void PlayerInfo::Fin() {

	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_isUse = true;
}