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

constexpr int ENEMY_NUM_X = 7;
constexpr int ENEMY_NUM_Y = 5;

constexpr float ENEMY_COLLISION_R = 20;

constexpr int ENEMY_BULLET_NUM = 30;

constexpr float ENEMY_SPEED = 5.0f;

class Enemy
{
private:
	int m_handle;			// �n���h��
	VECTOR m_pos;			// ���W
	float m_speed;			// �ړ����x
	int m_hp;				// �̗�
	bool m_flg;				// �����t���O
	int m_turn;				// �ړ������ύX

	int type;
	int m_enemy_index_x;
	int m_enemy_index_y;

	static Bullet bullet_info[ENEMY_BULLET_NUM];

public:
	void Init(int index_x, int index_y, int type_index);
	void Step();
	void Draw();
	void Fin();

	void Move();
	void Death();

	void BulletShot(VECTOR pos);
	void BulletMove();

	VECTOR GetPos() { return m_pos; };	//���W�擾
	Bullet GetBulletInfo(int index) { return bullet_info[index]; }
	Bullet& GeRefeBulletInfo(int index) { return bullet_info[index]; }

	void SetPosX(float x) { m_pos.x = x; };	// X���W�ݒ�
	void SetPosY(float y) { m_pos.y = y; };	// Y���W�ݒ�

	bool GetUseFlag() { return m_flg; }
};