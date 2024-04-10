#include "DxLib.h"
#include "../Common.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_current_scene_ID = 0;
}
SceneManager::~SceneManager()
{

}

void SceneManager::InitGame()
{
	m_current_scene_ID = INIT_PLAY;
}

void SceneManager::Main()
{
	switch (m_current_scene_ID) {
	case INIT_TITLE: {

		break;
	}
	case LOOP_TITLE: {

		break;
	}
	case FIN_TITLE: {

		break;
	}
	//=======================================================================================
	case INIT_PLAY: {

		break;
	}
	case LOOP_PLAY: {

		break;
	}
	case FIN_PLAY: {

		break;
	}
	//=======================================================================================
	case INIT_GAMEOVER: {

		break;
	}
	case LOOP_GAMEOVER: {

		break;
	}
	case FIN_GAMEOVER: {

		break;
	}
	//=======================================================================================
	case INIT_CLEAR: {

		break;
	}
	case LOOP_CLEAR: {

		break;
	}
	case FIN_CLEAR: {

		break;
	}
	}
}