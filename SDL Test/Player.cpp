#include "Player.h"
#include <iostream>
#include "InputManager.h"
#include "Renderer.h"

Player::Player()
{
    SetImage("Player.bmp");
}

void Player::Update()
{
    if (InputManager::Get()->GetKeyHeld('d'))
    {
        rect.x += 3;
    }
    if (InputManager::Get()->GetKeyHeld('a'))
    {
        rect.x -= 3;
    }
}

const char* Player::GetName()
{
    return "Player";
}


