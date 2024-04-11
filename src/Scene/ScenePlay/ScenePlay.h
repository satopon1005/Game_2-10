#pragma once

#include "../../Objects/Player/Player.h"
#include "../../Objects/Enemy/Enemy.h"

constexpr int ENEMY_TYPE[ENEMY_NUM_Y][ENEMY_NUM_X] = {
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
};

class ScenePlay
{
private:
	PlayerInfo player_info;
	Enemy enemy_info[ENEMY_NUM_Y][ENEMY_NUM_X];

public:
	void InitPlay();
	void StepPlay();
	void DrawPlay();
	void FinPlay();
};