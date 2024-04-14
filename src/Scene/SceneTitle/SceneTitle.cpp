#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"

void SceneTitle::Init()
{
	bg_handle = LoadGraph(TITLE_BG_HANDLE_PATH);
}

bool SceneTitle::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		return true;
	}
	return false;
}

void SceneTitle::Draw()
{
	DrawGraph(0, 0, bg_handle, true);
}

void SceneTitle::Fin()
{
	DeleteGraph(bg_handle);
}