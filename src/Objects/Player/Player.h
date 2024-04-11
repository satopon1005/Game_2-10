#pragma once

#include "DxLib.h"

#define PLAYER_PATH "Data/Player/player.png"

constexpr int PLAYER_COLLISION_X = 100;
constexpr int PLAYER_COLLISION_Y = 15;

constexpr float PLAYER_SPEED = 5;

class PlayerInfo
{
private:
	int m_handle;		//ハンドル
	VECTOR m_pos;	//座標
	float m_speedX;	//移動速度
	bool m_isUse;     //使用中フラグ

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void SetPosX(float x) { m_pos.x = x; };	// X座標設定
	

};

