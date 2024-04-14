#include "Player.h"
#include "DxLib.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../../MyMath/MyMath.h"

PlayerInfo::PlayerInfo()
{
	m_handle = 0;					//ハンドル
	m_bullet_vec_handle = 0;		//ハンドル

	m_pos = { 0 };					//座標
	m_speedX = 0;					//移動速度
	m_isUse = 0;					//使用中フラグ

	bullet_vec = { 0 };
	bullet_start_angle = 0;
}
PlayerInfo::~PlayerInfo()
{
	Fin();
}

void PlayerInfo::Init() {

	m_handle = LoadGraph(PLAYER_PATH);
	m_bullet_vec_handle = LoadGraph(PLAYER_BULLET_VEC_PATH);
	m_pos.x = 500.0f;
	m_pos.y = 700.0f;
	m_speedX = PLAYER_SPEED;
	m_isUse = true;

	bullet_info.Init(PLAYER_BULLET_PATH, PLAYER_BULLET_SPEED, true);
	bullet_vec = { 0 };
	bullet_start_angle = (float)(PI / 2 * 3);
}

void PlayerInfo::Step() {

	Move();
}


void PlayerInfo::Draw() {
	// 描画
	bullet_info.Draw();

	DrawExtendGraph((int)(m_pos.x - PLAYER_COLLISION_X / 2),
		(int)(m_pos.y - PLAYER_COLLISION_Y / 2),
		(int)(m_pos.x + PLAYER_COLLISION_X / 2),
		(int)(m_pos.y + PLAYER_COLLISION_Y / 2),
		m_handle,
		true);
}

void PlayerInfo::DrawAllow()
{
	if (!bullet_info.GetUseFlag()) {
		DrawRotaGraph2((int)(m_pos.x), (int)(m_pos.y - 10), 0, 100, 0.3, bullet_start_angle, m_bullet_vec_handle, true);
	}
}


void PlayerInfo::Fin() {

	DeleteGraph(m_handle);
	DeleteGraph(m_bullet_vec_handle);
}

void PlayerInfo::Move()
{
	//左移動操作
	if (Input::IsKeyDown(KEY_INPUT_LEFT))
	{
		m_pos.x -= m_speedX;
	}
	//右移動操作
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
	//左回転
	if (Input::IsKeyDown(KEY_INPUT_LEFT))
	{
		bullet_start_angle -= 0.1f;
	}
	//右回転
	if (Input::IsKeyDown(KEY_INPUT_RIGHT))
	{
		bullet_start_angle += 0.1f;
	}
	if (bullet_start_angle <= PI + 0.2)
		bullet_start_angle = (float)(PI + 0.2);
	if (bullet_start_angle >= PI * 2 - 0.2)
		bullet_start_angle = (float)(PI * 2 - 0.2);
}

void PlayerInfo::BulletShot()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
	{
		bullet_info.Spawn(VGet(m_pos.x, m_pos.y - 10, m_pos.z), GetVecFromAngle2D(bullet_start_angle), 0, true);
	}
}
void PlayerInfo::BulletMove()
{
	bullet_info.Step(true);
}