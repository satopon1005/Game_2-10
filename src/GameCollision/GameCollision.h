#pragma once

#include "../Objects/Bullet/Bullet.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Player/Player.h"

bool CollisionPlayerToBullet(VECTOR player_pos, Bullet& bullet_info);

bool CollisionEnemyToBullet(Enemy& enemy_info, Bullet& bullet_info, bool Switch = false);