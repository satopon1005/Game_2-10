#pragma once

#include "../../Objects/Player/Player.h"
#include "../../Objects/Enemy/Enemy.h"
#include "../../CountTime/CountTime.h"

constexpr int ENEMY_CHANGE_SPAWN_PROBABILITY_NUM = 2;

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

	void StartStepPlay();

	int GetEnemyAliveNum() { return enemy_alive_num; }
	PlayerInfo& GetPlayerInfo() { return player_info; }
};