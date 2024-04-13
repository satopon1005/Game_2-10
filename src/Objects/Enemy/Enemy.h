#pragma once

#include "DxLib.h"
#include "../Bullet/Bullet.h"

constexpr char ENEMY_PATH[5][128] = {
	{"data/Enemy/enemy1.png"},
	{"data/Enemy/enemy2.png"},
	{"data/Enemy/enemy3.png"},
	{"data/Enemy/enemy4.png"},
	{"data/Enemy/enemy5.png"},
};

//ここを変えたらBullel.hの一部を変える
constexpr int ENEMY_NUM_X = 7;
constexpr int ENEMY_NUM_Y = 5;

constexpr float ENEMY_COLLISION_R = 30;
constexpr float ENEMY_SIZE_X = ENEMY_COLLISION_R * 3 / 2;
constexpr float ENEMY_SIZE_Y = ENEMY_COLLISION_R;

constexpr int ENEMY_BULLET_NUM = 30;

constexpr float ENEMY_SPEED = 2.0f;

//敵の弾の発射の初期確率
constexpr int ENEMY_BULLET_SPAWN_PROBABILITY = 20;

class Enemy
{
private:
	int m_handle;			// ハンドル
	VECTOR m_pos;			// 座標
	float m_speed;			// 移動速度
	int m_hp;				// 体力
	bool m_flg;				// 生存フラグ
	int m_turn;				// 移動方向変更

	int type;
	int m_enemy_index_x;
	int m_enemy_index_y;

	static Bullet bullet_info[ENEMY_BULLET_NUM];
	static int m_bullet_spawn_probability;

public:
	void Init(int index_x, int index_y, int type_index);
	void Step();
	void Draw();
	void Fin();

	void Move();
	void Death();

	void BulletShot(VECTOR pos);	//弾の発射処理
	void BulletMove();				//弾の移動

	VECTOR GetPos() { return m_pos; };	//座標取得
	Bullet& GetRefeBulletInfo(int index) { return bullet_info[index]; }

	void SetPosX(float x) { m_pos.x = x; };	// X座標設定
	void SetPosY(float y) { m_pos.y = y; };	// Y座標設定

	bool GetUseFlag() { return m_flg; }

	//スポーンの確率
	int GetBulletSpawnProbability() { return m_bullet_spawn_probability; }
	void SetBulletSpawnProbability(int num) { m_bullet_spawn_probability = num; }
	//スポーンの確率変動
	void ChangeSpawnProbability(int num);
};