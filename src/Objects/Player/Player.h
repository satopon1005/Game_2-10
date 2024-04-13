#pragma once

#include "DxLib.h"
#include "../Bullet/Bullet.h"

#define PLAYER_PATH "Data/Player/player.png"
#define PLAYER_BULLET_PATH "Data/Player/player_bullet.png"
#define PLAYER_BULLET_VEC_PATH "Data/Player/player_bullet_vec.png"

constexpr int PLAYER_COLLISION_X = 100;
constexpr int PLAYER_COLLISION_Y = 15;

constexpr float PLAYER_SPEED = 5;

class PlayerInfo
{
private:
	int m_handle;					//ハンドル
	int m_bullet_handle;			//ハンドル
	int m_bullet_vec_handle;		//ハンドル

	VECTOR m_pos;	//座標
	float m_speedX;	//移動速度
	bool m_isUse;     //使用中フラグ

	Bullet bullet_info;
	float bullet_start_vec;
	bool bullet_shot_flag;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void Move();
	void VecMove();

	VECTOR GetPos() { return m_pos; }
	void SetPos(VECTOR vec) { m_pos = vec; };	//座標設定

	bool GetBulletShotFlag() { return bullet_shot_flag; }
};

