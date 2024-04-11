#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"

void ScenePlay::InitPlay()
{
	player_info.Init();
	for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
			enemy_info[y_index][x_index].Init(x_index, y_index, ENEMY_TYPE[y_index][x_index]);
		}
	}
}

void ScenePlay::LoopPlay()
{
	for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
			enemy_info[y_index][x_index].Draw();
		}
	}
	player_info.Draw();
}

void ScenePlay::FinPlay()
{
	player_info.Fin();
	for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
			enemy_info[y_index][x_index].Fin();
		}
	}
}