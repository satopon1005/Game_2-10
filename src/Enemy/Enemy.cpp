#include "Enemy.h"
#include "Dxlib.h"
#include "../Common.h"

void Enemy::Init() {

	m_handle = LoadGraph(ENEMY_PATH);
	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_speedX = 10.0f;
	m_hp = 1;
	m_flg = true;
	m_turn = 1;

}


void Enemy::Step() {

	if (m_pos.x >= SCREEN_SIZE_X) {
		m_turn *= -1;
		m_pos.y += 10.0f;
	}
	else if (m_pos.x <= 0) {
		m_turn *= -1;
		m_pos.y += 10.0f;
	}
	m_pos.x += m_speedX * m_turn;

}


void Enemy::Draw() {

	// test—p
	DrawCircle(m_pos.x, m_pos.y, 5, GetColor(0, 255, 0), true);

	// •`‰æ
	//DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}


void Enemy::Fin() {

	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_hp = 1;
	m_flg = true;
}