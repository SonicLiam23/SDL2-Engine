#include <iostream>
#include "Engine.h"
#include "Player.h"
#include "entity.h"
#include "img.h"
#include "Enemy.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Tower.h"


class Object {};
int main(int argc, char* argv[])
{
	Engine e;
	e.Init();
	Player p;
	Renderer::Get();
	p.SetImage("Target.bmp");

	img background;
	background.SetImage("BG.bmp");
	background.rect.w = 640 * 8;
	background.rect.h = 144 * 8;
	background.rect.y -= 185;  
	
	
	

	Enemy* en = new Enemy(&p);
	en->SetImage("noise.bmp");
	en->rect.x += 1000;


	
	

	// ADD BACKGROUND FIRST
	e.AddObject(&background);

	// ADD OTHER OBJECTS HERE
	e.AddObject(en);

	// ADD PLAYER LAST
	e.AddObject(&p);
	

	Renderer::Get()->SetCamera(&p);


	e.Start();
	while (e.IsGameRunning())
	{
		int coins = p.GetCoins();
		e.Update();
		for (ObjectBase* OB : e.GetAllCollisionsWith(&p))
		{
			if (OB->GetName() == "Enemy")
			{
				e.DeleteObject(OB);
				p.Damage(1);
				if (p.GetCoins() < 0)
				{
					//e.Uninit();
				}
			}
		}

		if (InputManager::Get()->GetKeyDown(SDLK_t))
		{
			Tower* t;
			t = new Tower();
			t->SetImage("Target.bmp");
			e.AddObject(t);
			t->rect.x = p.rect.x;
		}
	}

	return 0;

}