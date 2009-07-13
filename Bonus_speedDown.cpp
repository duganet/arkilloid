//Bonus_speedDown.cpp
#include "Bonus_speedDown.h"

Bonus_SpeedDown::Bonus_SpeedDown(int x, int y, SDL_Surface *sprite)
{
    bonus_sprite = sprite;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = sprite->w;
    bonusRect.h = sprite->h;
    yVel = 3;
    bonus_type = SPEED_DOWN;
}

Bonus_SpeedDown::~Bonus_SpeedDown()
{
}

void Bonus_SpeedDown::move()
{
    bonusRect.y += yVel;
}
