#pragma once

#define ENEMY_PATH "-1"

class Enemy
{
private:
	int m_handle;			// �n���h��
	VECTOR m_pos;			// ���W
	float m_speedX;			// �ړ����x
	int m_hp;				// �̗�
	bool m_flg;				// �����t���O
	int m_turn;				// �ړ������ύX

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	float GetPosX() { return m_pos.x; };	// X���W�擾
	float GetPosY() { return m_pos.y; };	// Y���W�擾

	void SetPosX(float x) { m_pos.x = x; };	// X���W�ݒ�
	void SetPosY(float y) { m_pos.y = y; };	// Y���W�ݒ�

};