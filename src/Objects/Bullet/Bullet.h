#pragma once

#define BULLET_HANDLE_PATH ("")

constexpr int BULLET_SPEED = 3;

enum BulletType
{
	ENEMY_TYPE,
	PLAYER_TYPE,
};

class Bullet
{
private:
	int m_handle;
	VECTOR m_pos;
	VECTOR m_vec;
	bool m_isUse;
	int m_type;

public:
	Bullet();
	~Bullet();

	void Init();
	void Step();
	void Draw();
	void Fin();

	void Spawn(VECTOR pos, VECTOR vec);
	void Death();
	void Move();
};