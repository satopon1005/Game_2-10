#include "DxLib.h"
#include "../Common.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_current_scene_ID = 0;

	scene_title.Init();
	scene_play.InitPlay();
	scene_clear.Init();
	scene_gameover.Init();
}
SceneManager::~SceneManager()
{

}

void SceneManager::InitGame()
{
	m_current_scene_ID = INIT_TITLE;
}

void SceneManager::Main()
{
	switch (m_current_scene_ID) {
	case INIT_TITLE: {
		scene_title.Init();

		m_current_scene_ID = LOOP_TITLE;
		break;
	}
	case LOOP_TITLE: {
		if(scene_title.Step())
			m_current_scene_ID = FIN_TITLE;

		scene_title.Draw();
		break;
	}
	case FIN_TITLE: {
		scene_title.Fin();

		m_current_scene_ID = INIT_PLAY;
		break;
	}
	//=======================================================================================
	case INIT_PLAY: {
		scene_play.InitPlay();
		m_current_scene_ID = LOOP_PLAY;
		break;
	}
	case LOOP_PLAY: {
		if (scene_play.GetPlayerInfo().GetBulletInfo().GetUseFlag()) {
			scene_play.StepPlay();

			if (!scene_play.GetPlayerInfo().GetBulletInfo().GetUseFlag()) {
				m_current_scene_ID = INIT_GAMEOVER;
			}
			if (scene_play.GetEnemyAliveNum() == 0) {
				m_current_scene_ID = INIT_CLEAR;
			}
		}
		else {
			scene_play.StartStepPlay();

			scene_play.GetPlayerInfo().DrawAllow();
		}

		scene_play.DrawPlay();
		break;
	}
	case FIN_PLAY: {
		scene_play.FinPlay();
		break;
	}
	//=======================================================================================
	case INIT_GAMEOVER: {
		scene_gameover.Init();

		m_current_scene_ID = LOOP_GAMEOVER;
		break;
	}
	case LOOP_GAMEOVER: {
		if (scene_gameover.Step())
			m_current_scene_ID = FIN_GAMEOVER;

		scene_gameover.Draw();
		break;
	}
	case FIN_GAMEOVER: {
		scene_gameover.Fin();

		m_current_scene_ID = INIT_TITLE;
		break;
	}
	//=======================================================================================
	case INIT_CLEAR: {
		scene_clear.Init();

		m_current_scene_ID = LOOP_CLEAR;
		break;
	}
	case LOOP_CLEAR: {
		if (scene_clear.Step())
			m_current_scene_ID = FIN_CLEAR;

		scene_clear.Draw();
		break;
	}
	case FIN_CLEAR: {
		scene_clear.Fin();

		m_current_scene_ID = INIT_TITLE;
		break;
	}
	}
}