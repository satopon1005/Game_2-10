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

//������ς�����Bullel.h�̈ꕔ��ς���
constexpr int ENEMY_NUM_X = 7;
constexpr int ENEMY_NUM_Y = 5;

constexpr float ENEMY_COLLISION_R = 30;
constexpr float ENEMY_SIZE_X = ENEMY_COLLISION_R * 3 / 2;
constexpr float ENEMY_SIZE_Y = ENEMY_COLLISION_R;

constexpr int ENEMY_BULLET_NUM = 30;

constexpr float ENEMY_SPEED = 2.0f;

//�G�̒e�̔��˂̏����m��
constexpr int ENEMY_BULLET_SPAWN_PROBABILITY = 20;

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
	static int m_bullet_spawn_probability;

public:
	void Init(int index_x, int index_y, int type_index);
	void Step();
	void Draw();
	void Fin();

	void Move();
	void Death();

	void BulletShot(VECTOR pos);	//�e�̔��ˏ���
	void BulletMove();				//�e�̈ړ�

	VECTOR GetPos() { return m_pos; };	//���W�擾
	Bullet& GetRefeBulletInfo(int index) { return bullet_info[index]; }

	void SetPosX(float x) { m_pos.x = x; };	// X���W�ݒ�
	void SetPosY(float y) { m_pos.y = y; };	// Y���W�ݒ�

	bool GetUseFlag() { return m_flg; }

	//�X�|�[���̊m��
	int GetBulletSpawnProbability() { return m_bullet_spawn_probability; }
	void SetBulletSpawnProbability(int num) { m_bullet_spawn_probability = num; }
	//�X�|�[���̊m���ϓ�
	void ChangeSpawnProbability(int num);
};