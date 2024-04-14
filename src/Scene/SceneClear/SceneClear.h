#pragma once

constexpr char CLEAR_BG_HANDLE_PATH[] = { "data/Scene/Clear/gameclear.png" };

class SceneClear
{
private:
	int bg_handle;

public:
	void Init();
	bool Step();
	void Draw();
	void Fin();
};