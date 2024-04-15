#include "DxLib.h"
#include "../../Common.h"
#include "SceneClear.h"
#include "../../Input/Input.h"

void SceneClear::Init(int score)
{
	bg_handle = LoadGraph(CLEAR_BG_HANDLE_PATH);

	m_font_handle = CreateFontToHandle("美咲ゴシック", 35, 3);

	m_score = score;
	LoadFile();
}

bool SceneClear::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		return true;
	}
	return false;
}

void SceneClear::Draw(int score)
{
	DrawGraph(0, 0, bg_handle, true);

	DrawFormatStringToHandle(460, 315, GetColor(255, 255, 255),
		m_font_handle,"%d", m_high_score);
	DrawFormatStringToHandle(460, 385, GetColor(255, 255, 255),
		m_font_handle, "%d", m_score);

}

void SceneClear::Fin()
{
	DeleteGraph(bg_handle);
	DeleteFontToHandle(m_font_handle);
}

void SceneClear::LoadFile()
{
	//ファイル読み込み

	FILE* fp;
	errno_t err;
	char work[10] = { 0 };
	string str;

	err = fopen_s(&fp, SCORE_SAVE_FILE_PATH, "r");

	if (err != NULL) {
		return;
	}

	fgets(work, 10, fp);

	str = work;

	m_high_score = atoi(str.c_str());

	fclose(fp);

	//ファイル書き込み

	if (m_score > m_high_score) {
		
		err = fopen_s(&fp, SCORE_SAVE_FILE_PATH, "w");

		if (err != NULL) {
			return;
		}

		fprintf_s(fp, "%d", m_score);

		m_high_score = m_score;

		fclose(fp);
	}
}