//Bonus_speed.cpp
#include "Bonus_speed.h"

extern std::vector<Texture*>textureList;

Bonus_Speed::Bonus_Speed(int x, int y, Texture* texture = textureList[SPEEDUP])
{
    this->texture = new Texture();
    this->texture = texture;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = this->texture->w;
    bonusRect.h = this->texture->h;
    yVel = 3;
    bonus_type = SPEED_UP_B;
}

Bonus_Speed::~Bonus_Speed()
{
    delete this->texture;
}

void Bonus_Speed::move()
{
    bonusRect.y += yVel;
}

