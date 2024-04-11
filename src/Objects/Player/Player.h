#pragma once


#define PLAYER_PATH "Data/Player/player.png"

class PlayerInfo
{
private:
	int handle;		//ハンドル
	int posX,posY;	//座標
	float speedX;	//移動速度
	bool isUse;     //使用中フラグ

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void SetPosX(float x);	// X座標設定
	

};

