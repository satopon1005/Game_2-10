#include "play.h"
#include "DxLib.h"




int bgPlay;
bool isNextPlay = false;


void PlayerInfo::Init() {

	bgPlay = LoadGraph(PLAYER_PATH);

	handle = LoadGraph(PLAYER_PATH);
	posX = 500;
	posY = 200;
	speedX = 2.0f;
	isUse = true;

}

void PlayerInfo::Step() {

	//ç∂à⁄ìÆëÄçÏ
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		posX -= speedX;
	}
	//âEà⁄ìÆëÄçÏ
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		posX += speedX;
	}

}


void PlayerInfo::Draw() {

	
	// ï`âÊ
	DrawGraph(posX, posX, handle, true);
}


void PlayerInfo::Fin() {

	posX = 100.0f;
	posY = 100.0f;
	isUse = true;
}


void PlayerInfo::SetPosX(float x) {
	posX = x;
}
