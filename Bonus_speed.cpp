//Bonus_speed.cpp
#include "Bonus_speed.h"

Bonus_Speed::Bonus_Speed(int x, int y, SDL_Surface *sprite)
{
    bonus_sprite = sprite;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = sprite->w;
    bonusRect.h = sprite->h;
    yVel = 3;
    bonus_type = SPEED_UP;
}

Bonus_Speed::~Bonus_Speed()
{
}

void Bonus_Speed::move()
{
    bonusRect.y += yVel;
}

