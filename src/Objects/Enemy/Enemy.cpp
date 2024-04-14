#include "Enemy.h"
#include "Dxlib.h"
#include "../../Common.h"

Bullet Enemy::bullet_info[ENEMY_BULLET_NUM];
//確率
//未完成
int Enemy::m_bullet_spawn_probability;

Enemy::Enemy()
{
	m_handle = 0;			// ハンドル
	m_pos = { 0 };			// 座標
	m_speed = 0;			// 移動速度
	m_hp = 0;				// 体力
	m_flg = 0;				// 生存フラグ
	m_turn = 0;				// 移動方向変更

	type = 0;
	m_enemy_index_x = 0;
	m_enemy_index_y = 0;
}
Enemy::~Enemy()
{

}

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
		bullet_info[i].Init(BULLET_HANDLE_PATH, ENEMY_BULLET_SPEED);

	m_bullet_spawn_probability = ENEMY_BULLET_SPAWN_PROBABILITY;
}

void Enemy::Step() {
	Move();
	BulletMove();
}

void Enemy::Draw() {

	// test用
	//DrawCircle(m_pos.x, m_pos.y, ENEMY_COLLISION_R, GetColor(0, 255, 0), false);

	// 描画
	DrawExtendGraph((int)(m_pos.x - ENEMY_SIZE_X / 2),
		(int)(m_pos.y - ENEMY_SIZE_Y / 2),
		(int)(m_pos.x + ENEMY_SIZE_X / 2),
		(int)(m_pos.y + ENEMY_SIZE_Y / 2),
		m_handle,
		true);
}

void Enemy::Fin() {

	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_hp = 1;
	m_flg = true;
}

//敵の移動処理
void Enemy::Move()
{
	if (m_flg) {
		if (m_pos.x >= SCREEN_SIZE_X - ((ENEMY_NUM_X - m_enemy_index_x - 1) * 2 + 1) * ENEMY_COLLISION_R) {
			//画面右側についたら切り替えす
			m_speed *= -1;
			m_pos.y += 10.0f;
		}
		else if (m_pos.x <= (m_enemy_index_x * 2 + 1) * ENEMY_COLLISION_R) {
			//画面左側についたら切り替えす
			m_speed *= -1;
			m_pos.y += 10.0f;
		}
		m_pos.x += m_speed;
	}
}

//弾の発射処理
void Enemy::BulletShot(VECTOR pos)
{
	for (int i = 0; i < ENEMY_BULLET_NUM; i++){
		if (!bullet_info[i].GetUseFlag()) {
			bullet_info[i].Spawn(pos, VGet(0, 1.0f, 0), m_bullet_spawn_probability);
			return;
		}
	}
}

//弾の移動処理
void Enemy::BulletMove()
{
	for (int i = 0; i < ENEMY_BULLET_NUM; i++){
		if (bullet_info[i].GetUseFlag()) {
			bullet_info[i].Step();
		}
	}
}

//敵の死亡処理
void Enemy::Death()
{
	m_flg = false;
}

//敵のスポーン確率変動
void Enemy::ChangeSpawnProbability(int num)
{
	m_bullet_spawn_probability = num;
}