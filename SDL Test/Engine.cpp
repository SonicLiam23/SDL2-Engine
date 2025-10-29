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

bool Engine::IsColliding(SDL_Rect* obj1, SDL_Rect* obj2)
{
	return SDL_HasIntersection(obj1, obj2);
}

bool Engine::IsColliding(ObjectBase* obj1, SDL_Rect* obj2)
{
	return IsColliding(obj1->GetPosition(), obj2);
}

bool Engine::IsColliding(ObjectBase* obj1, ObjectBase* obj2)
{
	return IsColliding(obj1->GetPosition(), obj2->GetPosition());
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

