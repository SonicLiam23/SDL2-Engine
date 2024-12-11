#pragma once
#include "ObjectBase.h"

class Tower : public ObjectBase
{
public:
	Tower();

private:

	void Update() override;
	const char* GetName() override;
};

