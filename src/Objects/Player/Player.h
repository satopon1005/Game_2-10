#pragma once


#define PLAYER_PATH "Data/Player/player.png"

class PlayerInfo
{
private:
	int handle;		//�n���h��
	int posX,posY;	//���W
	float speedX;	//�ړ����x
	bool isUse;     //�g�p���t���O

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void SetPosX(float x);	// X���W�ݒ�
	

};

