//Bonus_Die.cpp
#include "Bonus_Die.h"

extern std::vector<Texture*>textureList;

Bonus_Die::Bonus_Die(int x, int y, Texture *texture = textureList[DIE])
{
    this->texture = new Texture();
    this->texture = texture;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = this->texture->w;
    bonusRect.h = this->texture->h;
    yVel = 3;
    bonus_type = DIE;
}

Bonus_Die::~Bonus_Die()
{
    delete this->texture;
}

void Bonus_Die::move()
{
    bonusRect.y += yVel;
}
