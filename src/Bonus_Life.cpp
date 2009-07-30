//Bonus_Life.cpp
#include "Bonus_Life.h"

extern std::vector<Texture*>textureList;

Bonus_Life::Bonus_Life(int x, int y, Texture* texture = textureList[LIFE])
{
    this->texture = new Texture();
    this->texture = texture;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = this->texture->w;
    bonusRect.h = this->texture->h;
    yVel = 3;
    bonus_type = LIFE;
}

Bonus_Life::~Bonus_Life()
{
    delete this->texture;
}

void Bonus_Life::move()
{
    bonusRect.y += yVel;
}

