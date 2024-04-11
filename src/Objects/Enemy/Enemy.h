#pragma once

#include "DxLib.h"

constexpr char ENEMY_PATH[5][128] = {
	{"data/Enemy/enemy1.png"},
	{"data/Enemy/enemy2.png"},
	{"data/Enemy/enemy3.png"},
	{"data/Enemy/enemy4.png"},
	{"data/Enemy/enemy5.png"},
};

constexpr int ENEMY_NUM_X = 7;
constexpr int ENEMY_NUM_Y = 5;

constexpr float ENEMY_COLLISION_R = 20;

constexpr float ENEMY_SPEED = 5.0f;

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

public:
	void Init(int index_x, int index_y, int type_index);
	void Step();
	void Draw();
	void Fin();

	void Move();
	void Death();

	float GetPosX() { return m_pos.x; };	// X座標取得
	float GetPosY() { return m_pos.y; };	// Y座標取得

	void SetPosX(float x) { m_pos.x = x; };	// X座標設定
	void SetPosY(float y) { m_pos.y = y; };	// Y座標設定

};