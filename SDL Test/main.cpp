#include <iostream>
#include "Engine.h"
#include "Player.h"
#include "Renderer.h"
#include "InputManager.h"


class Object {};
int main(int argc, char* argv[])
{
	Engine e;
	e.Init();
	Player p;
	Renderer::Get();


	e.Start();
	while (e.IsGameRunning())
	{
		e.Update();
	}

	return 0;

}