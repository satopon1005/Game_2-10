#include "Enemy.h"
#include "Dxlib.h"
#include "../Common.h"

Enemy m_enemy;

void Enemy::Init() {

	m_handle = LoadGraph(ENEMY_PATH);
	m_posX = 100.0f;
	m_posY = 100.0f;
	m_speedX = 10.0f;
	m_hp = 1;
	m_flg = true;
	m_turn = 1;

}


void Enemy::Step() {

	if (m_posX > SCREEN_SIZE_X) {
		m_turn *= -1;
		m_posY += 10.0f;
	}
	else if (m_posX < 0) {
		m_turn *= -1;
		m_posY += 10.0f;
	}
	m_posX += m_speedX * m_turn;

}


void Enemy::Draw() {

	// test—p
	DrawPixel(m_posX, m_posY, GetColor(0, 255, 0));

	// •`‰æ
	//DrawGraph(m_posX, m_posY, m_handle, true);
}


void Enemy::Fin() {

	m_posX = 100.0f;
	m_posY = 100.0f;
	m_hp = 1;
	m_flg = true;
}


void Enemy::SetPosX(float x) {
	m_posX = x;
}

void Enemy::SetPosY(float y) {
	m_posY = y;
}