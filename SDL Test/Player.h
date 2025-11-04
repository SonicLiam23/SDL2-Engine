#pragma once
#include "ImageObject.h"

enum Buttons
{
	NUM_ONE,
	NUM_TWO,
	NUM_THREE,
	NUM_FOUR,

};


class Player : public ImageObject
{
public:
	Player();

	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
	void OnClick() override;
};
