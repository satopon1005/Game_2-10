#pragma once

#define ENEMY_PATH "-1"

class Enemy
{
private:
	int m_handle;			// ハンドル
	float m_posX, m_posY;	// 座標
	int m_hp;				// 体力
	bool m_flg;				// 生存フラグ
	int m_turn;				// 移動方向変更

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};