#include "DxLib.h"
#include "../../Common.h"
#include "SceneClear.h"
#include "../../Input/Input.h"

void SceneClear::Init()
{
	bg_handle = LoadGraph(CLEAR_BG_HANDLE_PATH);
}

bool SceneClear::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		return true;
	}
	return false;
}

void SceneClear::Draw()
{
	DrawGraph(0, 0, bg_handle, true);
}

void SceneClear::Fin()
{
	DeleteGraph(bg_handle);
}