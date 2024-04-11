#include "DxLib.h"
#include "Bullet.h"
#include "../../Common.h"
#include "../../MyMath/MyMath.h"

Bullet::Bullet()
{
	m_handle = 0;
	m_pos = { 0 };
	m_vec = { 0 };
	m_angle = 0;
	m_isUse = 0;
	m_type = 0;
}
Bullet::~Bullet()
{
	Fin();
}


void Bullet::Init()
{
	m_handle = LoadGraph(BULLET_HANDLE_PATH);
	m_pos = { 0 };
	m_vec = { 0 };
	m_angle = 0.0;
	m_isUse = false;
	m_type = ENEMY_TYPE;
}

void Bullet::Step()
{
	//égópíÜÇ»ÇÁ
	if (m_isUse) {
		//ìÆÇ´
		Move();

		//ç∂âEÇ…ìñÇΩÇÍÇŒíµÇÀï‘ÇÈ
		if (m_pos.x <= 0) {
			m_pos.x = 0;
			m_vec.x *= -1;
		}
		if (m_pos.x >= SCREEN_SIZE_X) {
			m_pos.x = SCREEN_SIZE_X;
			m_vec.x *= -1;
		}
		//è„â∫ÇæÇ∆è¡Ç∑
		if (m_pos.y <= 0 ||
			m_pos.y >= SCREEN_SIZE_Y) {
			Death();
		}
	}
}

void Bullet::Draw()
{
	if (m_isUse) {
		DrawRotaGraph((int)m_pos.x, (int)m_pos.y, 1.0, m_angle, m_handle, false);

		DrawCircle((int)m_pos.x, (int)m_pos.y, 3, GetColor(0, 255, 0), true);
	}
}

void Bullet::Fin()
{
	DeleteGraph(m_handle);
}


void Bullet::Spawn(VECTOR pos, VECTOR vec)
{
	int random_num = GetRand(10);
	if (random_num != 0)
		return;

	if (!m_isUse) {
		m_pos = pos;
		m_vec = GetVector(vec, BULLET_SPEED);
		m_angle = (double)AngleOf2Vector(VGet(1, 0, 0), m_vec);
		if (m_vec.y < 0)
			m_angle = PI * 2 - m_angle;
		m_type = ENEMY_TYPE;
		m_isUse = true;
	}
}

void Bullet::Death()
{
	m_isUse = false;
}

void Bullet::Move()
{
	m_pos.x += m_vec.x;
	m_pos.y += m_vec.y;
}

void Bullet::MoveReflection(VECTOR pos)
{
	m_vec = GetVector(pos, m_pos, BULLET_SPEED);
}