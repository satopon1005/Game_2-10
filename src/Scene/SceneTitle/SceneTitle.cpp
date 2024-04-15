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
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		return true;
	}
	return false;
}

void SceneTitle::Draw()
{
	DrawGraph(0, 0, bg_handle, true);

	//100âÒÇÃÇ§Çø20âÒï\é¶Ç∑ÇÈ(ì_ñ≈èàóù)
	static int count = 0;
	count = (count + 1) % 60;
	if (count < 30) {

		//ï\é¶
		DrawGraph(0, 100, Enterhandle, true);
	}
}

void SceneTitle::Fin()
{
	DeleteGraph(bg_handle);
	DeleteGraph(Enterhandle);
}