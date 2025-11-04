#include "Engine.h"
#include "Player.h"


class Object {};
int main(int argc, char* argv[])
{
	Engine* e = Engine::Get();
	e->Init();
	Player* p = new Player;

	e->AddObject(p);

	e->Start();
	while (e->IsGameRunning())
	{
		e->Update();
	}

	return 0;

}