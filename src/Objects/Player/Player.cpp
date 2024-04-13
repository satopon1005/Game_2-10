#include "Player.h"
#include "DxLib.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../../MyMath/MyMath.h"

void PlayerInfo::Init() {

	m_handle = LoadGraph(PLAYER_PATH);
	m_bullet_handle = LoadGraph(PLAYER_BULLET_PATH);
	m_bullet_vec_handle = LoadGraph(PLAYER_BULLET_VEC_PATH);
	m_pos.x = 500.0f;
	m_pos.y = 700.0f;
	m_speedX = PLAYER_SPEED;
	m_isUse = true;

	bullet_info.Init();
	bullet_start_vec = PI / 2 * 3;
	bullet_shot_flag = false;
}

void PlayerInfo::Step() {

	Move();
}


void PlayerInfo::Draw() {
	// �`��
	if (!bullet_shot_flag) {
		DrawRotaGraph2(m_pos.x, m_pos.y, 0, 100, 0.3, bullet_start_vec, m_bullet_vec_handle, true);
	}

	DrawExtendGraph((int)(m_pos.x - PLAYER_COLLISION_X / 2),
		(int)(m_pos.y - PLAYER_COLLISION_Y / 2),
		(int)(m_pos.x + PLAYER_COLLISION_X / 2),
		(int)(m_pos.y + PLAYER_COLLISION_Y / 2),
		m_handle,
		true);
}


void PlayerInfo::Fin() {

	DeleteGraph(m_handle);
	DeleteGraph(m_bullet_handle);
	DeleteGraph(m_bullet_vec_handle);
}

void PlayerInfo::Move()
{
	//���ړ�����
	if (Input::IsKeyDown(KEY_INPUT_LEFT))
	{
		m_pos.x -= m_speedX;
	}
	//�E�ړ�����
	if (Input::IsKeyDown(KEY_INPUT_RIGHT))
	{
		m_pos.x += m_speedX;
	}
	if (m_pos.x <= PLAYER_COLLISION_X / 2)
		m_pos.x = PLAYER_COLLISION_X / 2;
	if (m_pos.x >= SCREEN_SIZE_X - PLAYER_COLLISION_X / 2)
		m_pos.x = SCREEN_SIZE_X - PLAYER_COLLISION_X / 2;
}

void PlayerInfo::VecMove()
{
	//����]
	if (Input::IsKeyDown(KEY_INPUT_LEFT))
	{
		bullet_start_vec -= 0.1f;
	}
	//�E��]
	if (Input::IsKeyDown(KEY_INPUT_RIGHT))
	{
		bullet_start_vec += 0.1f;
	}
	if (bullet_start_vec <= PI + 0.2)
		bullet_start_vec = PI + 0.2;
	if (bullet_start_vec >= PI * 2 - 0.2)
		bullet_start_vec = PI * 2 - 0.2;
}