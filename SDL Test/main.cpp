#include "Engine.h"
#include "Player.h"
#include "Objects.h"
//#include "SDL_ttf.h"


class Object {};
int main(int argc, char* argv[])
{
	Engine* e = Engine::Get();
	e->Init();
	Player* p = new Player;

	TextObject* to = new TextObject("Kenney Pixel.ttf", 64);
	to->SetText("1 2 3 4 5 6 7 8 9");

	e->AddObject(to);
	e->AddObject(p);

	e->Start();
	while (e->IsGameRunning())
	{
		e->Update();
	}

	return 0;

}