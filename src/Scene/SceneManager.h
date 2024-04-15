#pragma once

#include "SceneTitle/SceneTitle.h"
#include "ScenePlay/ScenePlay.h"
#include "SceneClear/SceneClear.h"
#include "SceneGameOver/SceneGameOver.h"

enum SCENE_TYPE
{
	INIT_TITLE,
	LOOP_TITLE,
	FIN_TITLE,

	INIT_PLAY,
	LOOP_PLAY,
	FIN_PLAY,

	INIT_GAMEOVER,
	LOOP_GAMEOVER,
	FIN_GAMEOVER,

	INIT_CLEAR,
	LOOP_CLEAR,
	FIN_CLEAR,
};

class SceneManager
{
private:
	int m_current_scene_ID;

	int score;

	SceneTitle scene_title;
	ScenePlay scene_play;
	SceneClear scene_clear;
	SceneGameOver scene_gameover;

public:
	SceneManager();
	~SceneManager();

	void InitGame();
	void Main();
};