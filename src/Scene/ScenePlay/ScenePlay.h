#pragma once

#include "../../Objects/Player/Player.h"
#include "../../Objects/Enemy/Enemy.h"
#include "../../CountTime/CountTime.h"

constexpr int ENEMY_CHANGE_SPAWN_PROBABILITY_NUM = 3;

constexpr int ENEMY_TYPE[ENEMY_NUM_Y][ENEMY_NUM_X] = {
	{0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2},
	{3,3,3,3,3,3,3},
	{4,4,4,4,4,4,4},
};

class ScenePlay
{
private:
	PlayerInfo player_info;
	Enemy enemy_info[ENEMY_NUM_Y][ENEMY_NUM_X];
	CountTime count_time;

	int enemy_alive_num = 0;
	int pre_enemy_alive_num = 0;

public:
	void InitPlay();
	void StepPlay();
	void DrawPlay();
	void FinPlay();
};