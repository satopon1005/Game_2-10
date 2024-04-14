#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"
#include "../../GameCollision/GameCollision.h"

void ScenePlay::InitPlay()
{
	player_info.Init();
	for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
			enemy_info[y_index][x_index].Init(x_index, y_index, ENEMY_TYPE[y_index][x_index]);
		}
	}
	count_time.InitCountTime();
	count_time.StartCountTime();
}

void ScenePlay::StepPlay()
{
	pre_enemy_alive_num = enemy_alive_num;
	enemy_alive_num = 0;

	player_info.Step();
	player_info.BulletMove();

	//ƒvƒŒƒCƒ„[‚ÆƒvƒŒƒCƒ„[‚Ì’e‚Ì“–‚½‚è”»’è
	CollisionPlayerToBullet(player_info.GetPos(), player_info.GetBulletInfo());

	for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
			enemy_info[y_index][x_index].Step();

			for (int bullet_index = 0; bullet_index < ENEMY_BULLET_NUM; bullet_index++) {
				Bullet& hypothetical_bullet = enemy_info[y_index][x_index].GetRefeBulletInfo(bullet_index);
				
				//ƒvƒŒƒCƒ„[‚Æ’e‚Ì“–‚½‚è”»’è
				CollisionPlayerToBullet(player_info.GetPos(), hypothetical_bullet);
				
				//“G‚Æ’e‚Ì“–‚½‚è”»’è
				CollisionEnemyToBullet(enemy_info[y_index][x_index], hypothetical_bullet);
			}

			//“G‚ÆƒvƒŒƒCƒ„[‚Ì’e‚Ì“–‚½‚è”»’è
			CollisionEnemyToBullet(enemy_info[y_index][x_index], player_info.GetBulletInfo(),true);

			//“G‚ÌŽc‚è‚Ì”‚ðŽæ“¾
			if (enemy_info[y_index][x_index].GetUseFlag())
				enemy_alive_num++;
		}
	}

	//“G‚ÌƒXƒ|[ƒ“Šm—¦•Ï“®
	if (enemy_alive_num != pre_enemy_alive_num && enemy_alive_num % ENEMY_CHANGE_SPAWN_PROBABILITY_NUM == 0) {
		enemy_info[0][0].ChangeSpawnProbability(enemy_info[0][0].GetBulletSpawnProbability() - 1);
	}
	int probability = enemy_info[0][0].GetBulletSpawnProbability();
	
	if (count_time.StepCountTimeUp()) {
		for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
			for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
				//“G‚Ì’e‚Ì”­ŽËˆ—
				if(enemy_info[y_index][x_index].GetUseFlag())
					enemy_info[y_index][x_index].BulletShot(enemy_info[y_index][x_index].GetPos());
				
			}
		}
	}
}

void ScenePlay::StartStepPlay()
{
	player_info.VecMove();
	player_info.BulletShot();
}

void ScenePlay::DrawPlay()
{
	for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
			if (enemy_info[y_index][x_index].GetUseFlag())
				enemy_info[y_index][x_index].Draw();
			for (int bullet_index = 0; bullet_index < ENEMY_BULLET_NUM; bullet_index++) {
				enemy_info[y_index][x_index].GetRefeBulletInfo(bullet_index).Draw();
			}
		}
	}
	player_info.Draw();
}

void ScenePlay::FinPlay()
{
	player_info.Fin();
	for (int y_index = 0; y_index < ENEMY_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < ENEMY_NUM_X; x_index++) {
			enemy_info[y_index][x_index].Fin();
		}
	}
}