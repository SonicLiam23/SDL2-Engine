#pragma once

#include <vector>
class ObjectBase;



/*
* Engine class should include:
* Array of objects
* spawn objects
* run "start" on objects
* Call update and render on each object
* handle collisions
*
*/
#include "SDLClasses.h"


class Engine
{
private:
	bool m_Running;
	std::vector<ObjectBase*> m_Objects;

public:
	void Update();
	const bool IsGameRunning() const;
	void Init();
	void Start();
	void Uninit();
	void AddObject(ObjectBase* obj);
	void DeleteObject(ObjectBase* obj);

	// Returns every object that is colliding with it as a vector
	std::vector<ObjectBase*> GetAllCollisionsWith(ObjectBase* Obj);
	// returns true if the 2 objects are colliding
	bool IsColliding(ObjectBase* obj1, ObjectBase* obj2);

	// Gets the closest Object to the object passed in
	ObjectBase* GetClosestObject(ObjectBase* obj);
};


