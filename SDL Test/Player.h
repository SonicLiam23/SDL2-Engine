#pragma once
#include "ObjectBase.h"
class Player : 
	public ObjectBase
{
	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
};

