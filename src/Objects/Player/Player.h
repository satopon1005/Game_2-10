#pragma once


#define PLAYER_PATH "Data/Player/player.png"

class PlayerInfo
{
private:
	int m_handle;		//�n���h��
	VECTOR m_pos;	//���W
	float m_speedX;	//�ړ����x
	bool m_isUse;     //�g�p���t���O

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void SetPosX(float x) { m_pos.x = x; };	// X���W�ݒ�
	

};

