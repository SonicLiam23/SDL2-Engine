#pragma once
#include "ObjectBase.h"
class Player;
class Enemy :
    public ObjectBase
{
public:
    Enemy(ObjectBase* Target);
    Enemy(SDL_Rect* Target);
private:
    // Inherited via ObjectBase
    void Update() override;
    const char* GetName() override;
    void init();

    int speed;
    SDL_Rect* m_Target;
};

