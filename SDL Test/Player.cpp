#include "Player.h"
#include <iostream>
#include "InputManager.h"
#include "Renderer.h"

Player::Player()
{
    // CHANGE THIS WHEN NEEDED
    CameraOffset = -160;
    m_Coins = 0;
    m_isFarmUp = false;
    m_isWallUp = false;
}

void Player::Update()
{
    if (InputManager::Get()->GetKeyHeld(SDLK_d))
    {
        rect.x += 3;
    }
    if (InputManager::Get()->GetKeyHeld(SDLK_a))
    {
        rect.x -= 3;
    }
    if (InputManager::Get()->GetKeyHeld(SDLK_j))
    {
        m_isWallUp = true;
    }
    if (InputManager::Get()->GetKeyHeld(SDLK_l))
    {
        m_isFarmUp = true;
    }
}

const char* Player::GetName()
{
    return "Player";
}

void Player::Render()
{
    if (m_img != nullptr)
    {
        Renderer::Get()->DrawImage(m_img, &rect, CameraOffset);
    }
}

void Player::Damage(int dmg)
{
    m_Coins -= dmg;
}

const int Player::GetCoins()
{
    return m_Coins;
}

void Player::AddCoin()
{
    m_Coins += 1;
}

const bool Player::GetWallStatus()
{
    return m_isWallUp;
}

const bool Player::GetFarmStatus()
{
    return m_isFarmUp;
}


