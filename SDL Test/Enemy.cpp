#include "Enemy.h"

Enemy::Enemy(ObjectBase* Target) : m_Target(Target->GetPosition())
{
    init();
}

Enemy::Enemy(SDL_Rect* Target) : m_Target(Target)
{
    init();
}

void Enemy::Update()
{
    // enemies should just chase the player for now
    int dir = m_Target->x - rect.x;
    if (dir != 0)
    {
        dir = (dir > 0 ? 1 : -1);
        
        rect.x += dir * speed;
    }
}

const char* Enemy::GetName()
{
    return "Enemy";
}

void Enemy::init()
{
    speed = 2;
}
