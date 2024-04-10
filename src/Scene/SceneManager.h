#pragma once

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
public:
	SceneManager();
	~SceneManager();

	void InitGame();
	void Main();
};