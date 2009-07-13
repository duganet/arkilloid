//Bonus_Die.cpp
#include "Bonus_Die.h"


Bonus_Die::Bonus_Die(int x, int y, SDL_Surface *sprite)
{
    bonus_sprite = sprite;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = sprite->w;
    bonusRect.h = sprite->h;
    yVel = 3;
    bonus_type = DIE;
}

Bonus_Die::~Bonus_Die()
{
}

void Bonus_Die::move()
{
    bonusRect.y += yVel;
}
