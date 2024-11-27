#include "Player.h"
#include <iostream>
#include "InputManager.h"

void Player::Update()
{
    if (InputManager::Get()->GetKeyHeld(SDLK_ESCAPE))
    {
        m_Position.x += 1;
    }
}

const char* Player::GetName()
{
    return nullptr;
}
