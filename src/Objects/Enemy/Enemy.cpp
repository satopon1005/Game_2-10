#include "Enemy.h"
#include "Dxlib.h"
#include "../../Common.h"

void Enemy::Init(int index_x, int index_y,int type_index)
{
	type = type_index;

	m_enemy_index_x = index_x;
	m_enemy_index_y = index_y;

	m_handle = LoadGraph(ENEMY_PATH);
	m_pos.x = 100.0f + ENEMY_COLLISION_R * 2 * m_enemy_index_x;
	m_pos.y = 100.0f + ENEMY_COLLISION_R * 2 * m_enemy_index_y;
	m_speed = 10.0f;
	m_hp = 1;
	m_flg = true;
}

void Enemy::Step() {
	Move();
}

void Enemy::Draw() {

	// test—p
	DrawCircle(m_pos.x, m_pos.y, 10, GetColor(0, 255, 0), true);

	// •`‰æ
	//DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}

void Enemy::Fin() {

	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_hp = 1;
	m_flg = true;
}


void Enemy::Move()
{
	if (m_flg) {
		if (m_pos.x >= SCREEN_SIZE_X - (ENEMY_NUM_X - m_enemy_index_x) * ENEMY_COLLISION_R) {
			m_speed *= -1;
			m_pos.y += 10.0f;
		}
		else if (m_pos.x <= 0) {
			m_speed *= -1;
			m_pos.y += 10.0f;
		}
		m_pos.x += m_speed;
	}
}

void Enemy::Death()
{
	m_flg = false;
}