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
	m_isBound = 0;
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
	m_angle = PI / 2;
	m_isUse = false;
	m_isBound = false;
}

void Bullet::Step(bool Switch)
{
	//�g�p���Ȃ�
	if (m_isUse) {
		//����
		Move();

		//���E�ɓ�����Β��˕Ԃ�
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
		if(Switch)
			//������true���Ə�Œ��˕Ԃ�
			if (m_pos.y <= 0) {
				m_pos.y = 0;
				m_vec.y *= -1;

				m_angle = (double)AngleOf2Vector(VGet(1, 0, 0), m_vec);
				if (m_vec.y < 0)
					m_angle = PI * 2 - m_angle;
			}
		else
			//�㉺���Ə���
			if (m_pos.y <= 0 ||
				m_pos.y >= SCREEN_SIZE_Y) {
				Death();
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
		m_isBound = false;
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