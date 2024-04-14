#pragma once

constexpr char TITLE_BG_HANDLE_PATH[] = { "data/Scene/Title/Titlescreen.png" };
constexpr char ENTER_HANDLE_PATH = {"data/Scene/Title/Enter.png"};

class SceneTitle
{
private:
	int bg_handle;
	int Enterhandle;
public:
	void Init();
	bool Step();
	void Draw();
	void Fin();
};