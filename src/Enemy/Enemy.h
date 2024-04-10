#pragma once

#define ENEMY_PATH "-1"

class Enemy
{
private:
	int m_handle;			// �n���h��
	float m_posX, m_posY;	// ���W
	float m_speedX;			// �ړ����x
	int m_hp;				// �̗�
	bool m_flg;				// �����t���O
	int m_turn;				// �ړ������ύX

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	float GetPosX() { return m_posX; };	// X���W�擾
	float GetPosY() { return m_posY; };	// Y���W�擾

	void SetPosX(float x);				// X���W�ݒ�
	void SetPosY(float y);				// Y���W�ݒ�

};