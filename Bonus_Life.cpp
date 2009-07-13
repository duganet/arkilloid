//Bonus_Life.cpp
#include "Bonus_Life.h"

Bonus_Life::Bonus_Life(int x, int y, SDL_Surface *sprite)
{
    bonus_sprite = sprite;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = sprite->w;
    bonusRect.h = sprite->h;
    yVel = 3;
    bonus_type = LIFE;
}

Bonus_Life::~Bonus_Life()
{
}

void Bonus_Life::move()
{
    bonusRect.y += yVel;
}

