#include <iostream>
#include "Engine.h"
#include "Player.h"
#include "Renderer.h"


class Object {};
int main(int argc, char* argv[])
{
	Engine e;
	e.Init();
	Player p;
	e.AddObject(&p);
	Renderer::Get();
	p.SetImage("Target.bmp");


	e.Start();
	while (e.IsGameRunning())
	{
		e.Update();
	}


	return 0;

}