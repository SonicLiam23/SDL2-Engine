#pragma once
#include "ObjectBase.h"

enum Buttons
{
	NUM_ONE,
	NUM_TWO,
	NUM_THREE,
	NUM_FOUR,

};


class Player : public ObjectBase
{
public:
	Player();

	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
};
