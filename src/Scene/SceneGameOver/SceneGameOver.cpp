#include "DxLib.h"
#include "../../Common.h"
#include "SceneGameOver.h"
#include "../../Input/Input.h"

void SceneGameOver::Init()
{
	bg_handle = LoadGraph(GAMEOVER_BG_HANDLE_PATH);
}

bool SceneGameOver::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		return true;
	}
	return false;
}

void SceneGameOver::Draw()
{
	DrawGraph(0, 0, bg_handle, true);
}

void SceneGameOver::Fin()
{
	DeleteGraph(bg_handle);
}