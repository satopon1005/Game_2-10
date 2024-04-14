#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"

void SceneTitle::Init()
{
	bg_handle = LoadGraph(TITLE_BG_HANDLE_PATH);
	Enterhandle = LoadGraph(ENTER_HANDLE_PATH);
}

bool SceneTitle::Step()
{

	DrawGraph(0, 0, Titlehandle, true);

	//100‰ñ‚Ì‚¤‚¿20‰ñ•\¦‚·‚é(“_–Åˆ—)
	static int count = 0;
	count = (count + 1) % 100;
	if (count < 20) {

		//•\¦
		DrawGraph(0, 100, Enterhandle, true);
	}

	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		return true;
	}
	return false;
}

void SceneTitle::Draw()
{
	DrawGraph(0, 0, bg_handle, true);
	DrawGraph(0, 0, Enterhandle, true);
}

void SceneTitle::Fin()
{
	DeleteGraph(bg_handle);
	DeleteGraph(Enterhandle);
}