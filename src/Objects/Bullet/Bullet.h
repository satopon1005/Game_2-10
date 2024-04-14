#pragma once

constexpr int BULLET_COLLISION_R = 5;

class Bullet
{
private:
	int m_handle;
	VECTOR m_pos;
	VECTOR m_vec;
	float m_speed;
	double m_angle;
	bool m_isUse;
	bool m_isBound;

public:
	Bullet();
	~Bullet();

	void Init(const char* handle_path, float speed, bool Switch = false);
	void Step(bool Switch = false);
	void Draw();
	void Fin();

	void Spawn(VECTOR pos, VECTOR vec, int rand_num = 0);
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

	float GetSpeed() { return m_speed; }
};