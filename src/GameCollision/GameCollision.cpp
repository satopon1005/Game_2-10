#include "DxLib.h"
#include "GameCollision.h"
#include "../MyMath/MyMath.h"
#include "../Collision/Collision.h"

bool CollisionPlayerToBullet(VECTOR player_pos, Bullet& bullet_info)
{
	if (Collision::IsHitRectCircle(bullet_info.GetPos().x,
									bullet_info.GetPos().y,
									BULLET_COLLISION_R,
									player_pos.x - PLAYER_COLLISION_X / 2,
									player_pos.y - PLAYER_COLLISION_Y / 2,
									PLAYER_COLLISION_X,
									PLAYER_COLLISION_Y)) {
		//�v���C���[����e�ւ̃x�N�g��
		VECTOR player_to_bullet_vec = GetVector(VGet(player_pos.x,
													player_pos.y + 10,
													player_pos.z),
												bullet_info.GetPos(),
												bullet_info.GetSpeed());

		bullet_info.SetVec(player_to_bullet_vec);

		bullet_info.SetIsBound(true);

		double angle=AngleOf2Vector(VGet(1, 0, 0), player_to_bullet_vec);
		//�p�x��180�x�ȏ�̂Ƃ�
		if (player_to_bullet_vec.y < 0)
			angle = PI * 2 - angle;

		bullet_info.SetAngle(angle);

		return true;
	}

	return false;
}

bool CollisionEnemyToBullet(Enemy& enemy_info, Bullet& bullet_info, bool Switch)
{

	if (!bullet_info.GetIsBound())
		return false;

	if (!enemy_info.GetUseFlag() || !bullet_info.GetUseFlag())
		return false;

	if (Collision::IsHitCircle(enemy_info.GetPos().x,
								enemy_info.GetPos().y,
								ENEMY_COLLISION_R,
								bullet_info.GetPos().x,
								bullet_info.GetPos().y,
								BULLET_COLLISION_R)) {
		enemy_info.Death();
		if (!Switch)
			bullet_info.Death();
		else {
			//�G����e�ւ̃x�N�g��
			VECTOR enemy_to_bullet_vec = GetVector(enemy_info.GetPos(), bullet_info.GetPos(), bullet_info.GetSpeed());

			bullet_info.SetVec(enemy_to_bullet_vec);

			bullet_info.SetIsBound(true);

			double angle = AngleOf2Vector(VGet(1, 0, 0), enemy_to_bullet_vec);
			//�p�x��180�x�ȏ�̂Ƃ�
			if (enemy_to_bullet_vec.y < 0)
				angle = PI * 2 - angle;

			bullet_info.SetAngle(angle);
		}

		return true;
	}
	return false;
}