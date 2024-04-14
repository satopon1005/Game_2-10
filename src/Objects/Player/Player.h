#pragma once

#include "DxLib.h"
#include "../Bullet/Bullet.h"

#define PLAYER_PATH "Data/Player/player.png"
#define PLAYER_BULLET_PATH "Data/Player/player_bullet.png"
#define PLAYER_BULLET_VEC_PATH "Data/Player/player_bullet_vec.png"

constexpr int PLAYER_COLLISION_X = 100;
constexpr int PLAYER_COLLISION_Y = 15;

constexpr float PLAYER_SPEED = 5;
constexpr float PLAYER_BULLET_SPEED = 5.0f;

class PlayerInfo
{
private:
	int m_handle;					//�n���h��
	int m_bullet_vec_handle;		//�n���h��

	VECTOR m_pos;	//���W
	float m_speedX;	//�ړ����x
	bool m_isUse;     //�g�p���t���O

	Bullet bullet_info;
	VECTOR bullet_vec;
	float bullet_start_angle;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void Move();
	void VecMove();

	VECTOR GetPos() { return m_pos; }
	void SetPos(VECTOR vec) { m_pos = vec; };	//���W�ݒ�

	Bullet& GetBulletInfo() { return bullet_info; }
	void BulletShot();
	void BulletMove();
};

