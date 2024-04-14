#pragma once

constexpr char TITLE_BG_HANDLE_PATH[] = { "data/Scene/Title/Titlescreen.png" };

class SceneTitle
{
private:
	int bg_handle;

public:
	void Init();
	bool Step();
	void Draw();
	void Fin();
};