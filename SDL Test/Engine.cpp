#include "Engine.h"

#include "Globals.h"
#include "Renderer.h"
#include "InputManager.h"
#include "ObjectBase.h"
#include <cmath>

#include "SDL.h"


void Engine::Update()
{
	InputManager::Get()->Update();
	SDL_RenderClear(SDLClasses::GetRenderer());
	// call update on each object
	for (ObjectBase* CurrObj : m_Objects)
	{
		CurrObj->Update();
		CurrObj->Render();
	}
	SDL_RenderPresent(SDLClasses::GetRenderer());
	// 1000 -> ms in seconds. 60 -> times a second
	SDL_Delay(1000/60);
}

const bool Engine::IsGameRunning() const
{
	return m_Running;
}

void Engine::Init()
{
	if (m_Running)
	{
		return;
	}
	SDL_Init(SDL_INIT_EVERYTHING);
	m_Objects.reserve(Globals::ESTIMATED_AMT_OF_OBJECTS);
	// creates classes if they dont already exist
	Renderer::Get();
	InputManager::Get();
}

// Run this after added all objects
void Engine::Start()
{
	m_Running = true;
}

void Engine::Uninit()
{
	SDLClasses::DeleteAll();

	SDL_Quit();
}

void Engine::AddObject(ObjectBase* obj)
{
	m_Objects.push_back(obj);
}

void Engine::DeleteObject(ObjectBase* obj)
{
	for (int i = 0; i < m_Objects.size(); ++i)
	{
		if (obj == m_Objects[i])
		{
			m_Objects.erase(m_Objects.begin() + i);
			break;
		}
	}
	delete obj;
}

std::vector<ObjectBase*> Engine::GetAllCollisionsWith(ObjectBase* Obj)
{
	std::vector<ObjectBase*> ReturnVector;
	for (ObjectBase* CurrObj : m_Objects)
	{
		if (CurrObj->CollisionEnabled)
		{
			if (IsColliding(Obj, CurrObj))
			{
				ReturnVector.push_back(CurrObj);
			}
		}
	}
	return ReturnVector;
}

bool Engine::IsColliding(ObjectBase* obj1, ObjectBase* obj2)
{
	if (!obj1->CollisionEnabled || !obj2->CollisionEnabled)
	{
		return false;
	}

	if (obj1 == obj2)
	{
		return false;
	}

	SDL_Rect* rect1 = obj1->GetPosition();
	SDL_Rect* rect2 = obj2->GetPosition();


	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = rect1->x;
	rightA = rect1->x + rect1->w;
	topA = rect1->y;
	bottomA = rect1->y + rect1->h;

	//Calculate the sides of rect B
	leftB = rect2->x;
	rightB = rect2->x + rect2->w;
	topB = rect2->y;
	bottomB = rect2->y + rect2->h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

ObjectBase* Engine::GetClosestObject(ObjectBase* obj)
{
	float closestDistance = INT_MAX;
	ObjectBase* closestObject = nullptr;
	for (ObjectBase* currObj : m_Objects)
	{
		if (obj != currObj)
		{
			int dX;
			int dY;
			dX = obj->rect.x - currObj->rect.x;
			dY = obj->rect.y - currObj->rect.y;

			float hyp;
			hyp = (dX * dX) + (dY * dY);
			hyp = std::sqrt(hyp);

			if (hyp < closestDistance)
			{
				closestObject = currObj;
			}
		}
	}

	return closestObject;
}

