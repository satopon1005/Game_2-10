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
	m_speed = 0;
	m_isUse = 0;
	m_isBound = 0;
}
Bullet::~Bullet()
{
	Fin();
}


void Bullet::Init(const char* handle_path, float speed, bool Switch)
{
	m_handle = LoadGraph(handle_path);
	m_pos = { 0 };
	m_vec = { 0 };
	m_speed = speed;
	m_angle = PI / 2;
	m_isUse = false;
	m_isBound = Switch;
}

void Bullet::Step(bool Switch)
{
	//égópíÜÇ»ÇÁ
	if (m_isUse) {
		//ìÆÇ´
		Move();

		//ç∂âEÇ…ìñÇΩÇÍÇŒíµÇÀï‘ÇÈ
		if (m_pos.x <= 0) {
			m_pos.x = 0;
			m_vec.x *= -1;

			m_angle = (double)AngleOf2Vector(VGet(1, 0, 0), m_vec);
			if (m_vec.y < 0)
				m_angle = PI * 2 - m_angle;
		}
		if (m_pos.x >= SCREEN_SIZE_X) {
			m_pos.x = SCREEN_SIZE_X;
			m_vec.x *= -1;

			m_angle = (double)AngleOf2Vector(VGet(1, 0, 0), m_vec);
			if (m_vec.y < 0)
				m_angle = PI * 2 - m_angle;
		}

		if (Switch) {
			//à¯êîÇ™trueÇæÇ∆è„Ç≈íµÇÀï‘Ç∑
			if (m_pos.y <= 0) {
				m_pos.y = 0;
				m_vec.y *= -1;

				m_angle = (double)AngleOf2Vector(VGet(1, 0, 0), m_vec);
				if (m_vec.y < 0)
					m_angle = PI * 2 - m_angle;
			}
			//â∫ÇæÇ∆è¡Ç∑
			if (m_pos.y >= SCREEN_SIZE_Y) {
				Death();
			}
		}
		else {
			//è„â∫ÇæÇ∆è¡Ç∑
			if (m_pos.y <= 0 ||
				m_pos.y >= SCREEN_SIZE_Y) {
				Death();
			}
		}
	}
}

void Bullet::Draw()
{
	if (m_isUse) {
		//DrawCircle((int)m_pos.x, (int)m_pos.y, BULLET_COLLISION_R, GetColor(0, 255, 0), false);
		DrawRotaGraph((int)m_pos.x, (int)m_pos.y, 1.0, m_angle, m_handle, true);
	}
}

void Bullet::Fin()
{
	DeleteGraph(m_handle);
}


void Bullet::Spawn(VECTOR pos, VECTOR vec, int rand_num, bool flag)
{
	int random_num = GetRand(rand_num);
	if (random_num != 0)
		return;

	if (!m_isUse) {
		m_pos = pos;
		m_vec = GetVector(vec, m_speed);
		m_angle = (double)AngleOf2Vector(VGet(1, 0, 0), m_vec);
		if (m_vec.y < 0)
			m_angle = PI * 2 - m_angle;
		m_isBound = flag;
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