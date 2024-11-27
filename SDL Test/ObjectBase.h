#pragma once
#include "SDL_rect.h"
class Image;
/*
* Base for the objects
* each object will need an update, render, start, end and a function to return its own name
* each class inherited from this will be its own object, like unity, each unique object will have its own class
* 
*/
class ObjectBase
{
public:
	ObjectBase();
	virtual void Update() = 0;
	void Render();
	virtual const char* GetName() = 0;
	void SetImage(const char* Path);
	bool CollisionEnabled;
	SDL_Rect* GetPosition();

protected:
	Image* m_img;
	SDL_Rect m_Position;
};

