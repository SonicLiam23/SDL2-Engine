#include "Engine.h"

#include "Globals.h"
#include "Renderer.h"
#include "InputManager.h"
#include "ObjectBase.h"
#include <cmath>
#include "Rect.h"
#include "SDL.h"

Engine* Engine::s_Instance = nullptr;
Engine* Engine::Get()
{
	return (s_Instance != nullptr) ? s_Instance : s_Instance = new Engine();
}

Engine::Engine() : m_Running(false)
{

}

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

void Engine::ClickAt(Rect* pos)
{
	for (ObjectBase* CurrObj : m_Objects)
	{
		if (CurrObj->CollisionEnabled)
		{
			if (IsColliding(CurrObj, pos))
			{
				CurrObj->OnClick();
			}
		}
	}
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

bool Engine::IsColliding(Rect* obj1, Rect* obj2)
{
	SDL_Rect rect1 = obj1->TryParse<SDL_Rect>();
	SDL_Rect rect2 = obj2->TryParse<SDL_Rect>();
	return SDL_HasIntersection(&rect1, &rect2);
}

bool Engine::IsColliding(ObjectBase* obj1, Rect* obj2)
{
	return obj1->CollisionEnabled && IsColliding(obj1->GetPosition(), obj2);
}

bool Engine::IsColliding(ObjectBase* obj1, ObjectBase* obj2)
{
	return obj1->CollisionEnabled && obj2->CollisionEnabled && IsColliding(obj1->GetPosition(), obj2->GetPosition());
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

