#pragma once

constexpr char GAMEOVER_BG_HANDLE_PATH[] = { "data/Scene/GameOver/gameover.png" };

class SceneGameOver
{
private:
	int bg_handle;

public:
	void Init();
	bool Step();
	void Draw();
	void Fin();
};