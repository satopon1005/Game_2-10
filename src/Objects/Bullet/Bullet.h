#pragma once

#define BULLET_HANDLE_PATH ("data/Enemy/enemybullet.jpg")

constexpr float BULLET_SPEED = 3.0f / 30.0f;

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
	double m_angle;
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
	void MoveReflection(VECTOR pos);

	bool GetUseFlag() { return m_isUse; }
	VECTOR GetPos() { return m_pos; }
	VECTOR GetVec() { return m_vec; }
	void SetVec(VECTOR vec) { m_vec = vec; }

	int GetType() { return m_type; }
	void SetType(int type) { m_type = type; }
};