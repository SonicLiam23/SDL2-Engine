#pragma once
#include "Rect.h"
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
	ObjectBase(Rect pos = { 0, 0, 320, 320 });
	virtual void Update() {}
	virtual void Render();
	virtual const char* GetName() = 0;
	virtual void OnClick() {}
	void SetImage(const char* Path);
	bool CollisionEnabled;
	Rect* GetPosition();
	Rect rect;

protected:
	int CameraOffset;
	Image* m_img;
	
};

