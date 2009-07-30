//Bonus.cpp
#include "Bonus.h"

std::vector<Bonus*> Bonus::bonusList;
extern std::vector<Texture*>textureList;

Bonus::Bonus(int x, int y, Texture* texture,int type)
{
    this->texture = new Texture();
    this->texture = texture;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = this->texture->w;
    bonusRect.h = this->texture->h;
    yVel = 3;
    bonus_type = type;
}

Bonus::~Bonus()
{
    delete texture;
}

void Bonus::set_up(int x, int y, Texture *texture, int type)
{
    this->texture = texture;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = this->texture->w;
    bonusRect.h = this->texture->h;
    bonus_type = type;
}


void Bonus::show()
{
    this->texture->show(bonusRect.x, bonusRect.y);
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
