#pragma once

#define ENEMY_PATH "-1"

class Enemy
{
private:
	int m_handle;			// ハンドル
	VECTOR m_pos;			// 座標
	float m_speedX;			// 移動速度
	int m_hp;				// 体力
	bool m_flg;				// 生存フラグ
	int m_turn;				// 移動方向変更

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	float GetPosX() { return m_pos.x; };	// X座標取得
	float GetPosY() { return m_pos.y; };	// Y座標取得

	void SetPosX(float x) { m_pos.x = x; };	// X座標設定
	void SetPosY(float y) { m_pos.y = y; };	// Y座標設定

};