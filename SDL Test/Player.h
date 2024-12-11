#pragma once
#include "ObjectBase.h"
class Player : public ObjectBase
{
public:
	Player();

	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
	void Render() override;
	void Damage(int dmg);
	const int GetCoins();
	void AddCoin();
	const bool GetWallStatus();
	const bool GetFarmStatus();

private:
	int m_Coins;
	bool m_isWallUp;
	bool m_isFarmUp;
};
