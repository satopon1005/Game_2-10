#include "DxLib.h"
#include "GameCollision.h"
#include "../MyMath/MyMath.h"
#include "../Collision/Collision.h"

void CollisionPlayerToBullet(VECTOR player_pos, Bullet& bullet_info)
{
	if (Collision::IsHitRectCircle(bullet_info.GetPos().x,
									bullet_info.GetPos().y,
									ENEMY_COLLISION_R,
									player_pos.x - PLAYER_COLLISION_X / 2,
									player_pos.y - PLAYER_COLLISION_Y / 2,
									PLAYER_COLLISION_X,
									PLAYER_COLLISION_Y)) {
		VECTOR player_to_bullet_vec = GetVector(player_pos, bullet_info.GetPos(), BULLET_SPEED);

		bullet_info.SetVec(player_to_bullet_vec);

		bullet_info.SetType(PLAYER_TYPE);
	}
}

void CollisionEnemyToBullet(Enemy& enemy_info, Bullet& bullet_info)
{
	if (bullet_info.GetType() == ENEMY_TYPE)
		return;

	if (!enemy_info.GetUseFlag() || !bullet_info.GetUseFlag())
		return;

	if (Collision::IsHitCircle(enemy_info.GetPos().x,
								enemy_info.GetPos().y,
								ENEMY_COLLISION_R,
								bullet_info.GetPos().x,
								bullet_info.GetPos().y,
								ENEMY_COLLISION_R)) {
		enemy_info.Death();
		bullet_info.Death();
	}
}