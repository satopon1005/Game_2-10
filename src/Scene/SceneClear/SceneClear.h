#pragma once

constexpr char CLEAR_BG_HANDLE_PATH[] = { "data/Scene/Clear/gameclear.png" };

constexpr char SCORE_SAVE_FILE_PATH[] = { "data/save_data/score.txt" };

class SceneClear
{
private:
	int bg_handle;

	int m_font_handle = 0;

	int m_score = 0;
	int m_high_score = 0;

public:
	void Init(int score);
	bool Step();
	void Draw(int score);
	void Fin();

	void LoadFile();
};