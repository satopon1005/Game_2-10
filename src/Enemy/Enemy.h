#pragma once

#define ENEMY_PATH "-1"

class Enemy
{
private:
	int m_handle;			// �n���h��
	float m_posX, m_posY;	// ���W
	int m_hp;				// �̗�
	bool m_flg;				// �����t���O
	int m_turn;				// �ړ������ύX

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};