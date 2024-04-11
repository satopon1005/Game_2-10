#include "Enemy.h"
#include "Dxlib.h"
#include "../../Common.h"

Bullet Enemy::bullet_info[ENEMY_BULLET_NUM];

void Enemy::Init(int index_x, int index_y,int type_index)
{
	type = type_index;

	m_enemy_index_x = index_x;
	m_enemy_index_y = index_y;

	m_handle = LoadGraph(ENEMY_PATH[type]);
	m_pos.x = 100.0f + ENEMY_COLLISION_R * 2 * m_enemy_index_x;
	m_pos.y = 100.0f + ENEMY_COLLISION_R * 2 * m_enemy_index_y;
	m_speed = ENEMY_SPEED;
	m_hp = 1;
	m_flg = true;

	for (int i = 0; i < ENEMY_BULLET_NUM; i++)
		bullet_info[i].Init();
}

void Enemy::Step() {
	Move();
	BulletMove();
}

void Enemy::Draw() {

	// test—p
	//DrawCircle(m_pos.x, m_pos.y, 10, GetColor(0, 255, 0), true);

	// •`‰æ
	DrawExtendGraph((int)m_pos.x - 15,
		(int)m_pos.y - 10,
		(int)m_pos.x + 15,
		(int)m_pos.y + 10,
		m_handle,
		true);
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
		if (m_pos.x >= SCREEN_SIZE_X - ((ENEMY_NUM_X - m_enemy_index_x - 1) * 2 + 1) * ENEMY_COLLISION_R) {
			m_speed *= -1;
			m_pos.y += 10.0f;
		}
		else if (m_pos.x <= (m_enemy_index_x * 2 + 1) * ENEMY_COLLISION_R) {
			m_speed *= -1;
			m_pos.y += 10.0f;
		}
		m_pos.x += m_speed;
	}
}

void Enemy::BulletShot(VECTOR pos)
{
	for (int i = 0; i < ENEMY_BULLET_NUM; i++){
		if (!bullet_info[i].GetUseFlag()) {
			bullet_info[i].Spawn(pos, VGet(0, BULLET_SPEED, 0));
			return;
		}
	}
}

void Enemy::BulletMove()
{
	for (int i = 0; i < ENEMY_BULLET_NUM; i++){
		if (bullet_info[i].GetUseFlag()) {
			bullet_info[i].Step();
		}
	}
}

void Enemy::Death()
{
	m_flg = false;
}