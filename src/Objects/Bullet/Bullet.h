#pragma once

#define BULLET_HANDLE_PATH ("data/Enemy/enemybullet.png")

constexpr float BULLET_SPEED = 5.0f / 30;

constexpr int BULLET_COLLISION_R = 5;

class Bullet
{
private:
	int m_handle;
	VECTOR m_pos;
	VECTOR m_vec;
	double m_angle;
	bool m_isUse;
	bool m_isBound;

public:
	Bullet();
	~Bullet();

	void Init();
	void Step(bool Switch = false);
	void Draw();
	void Fin();

	void Spawn(VECTOR pos, VECTOR vec);
	void Death();
	void Move();

	bool GetUseFlag() { return m_isUse; }
	VECTOR GetPos() { return m_pos; }
	VECTOR GetVec() { return m_vec; }
	void SetVec(VECTOR vec) { m_vec = vec; }

	bool GetIsBound() { return m_isBound; }
	void SetIsBound(bool bound) { m_isBound = bound; }

	double GetAngle() { return m_angle; }
	void SetAngle(double angle) { m_angle = angle; }
};