//Bonus.cpp
#include "Bonus.h"

std::vector<Bonus*> Bonus::bonusList;

Bonus::Bonus(int x, int y, SDL_Surface *sprite,int type)
{
    bonus_sprite = sprite;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = bonus_sprite->w;
    bonusRect.h = bonus_sprite->h;
    yVel = 3;
    bonus_type = type;
}

Bonus::~Bonus()
{
    bonus_sprite = NULL;
}

void Bonus::set_up(int x, int y, SDL_Surface *sprite, int type)
{
    bonus_sprite = sprite;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = bonus_sprite->w;
    bonusRect.h = bonus_sprite->h;
    bonus_type = type;
}


void Bonus::show(SDL_Surface *screen)
{
    apply_surface(bonusRect.x, bonusRect.y, bonus_sprite, screen);
}

SDL_Rect Bonus::get_rect()
{
    return bonusRect;
}

int Bonus::get_type()
{
    return bonus_type;
}

void Bonus::move()
{
    bonusRect.y += yVel;
}
