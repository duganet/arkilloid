//Bonus_speedDown.cpp
#include "Bonus_speedDown.h"

extern std::vector<Texture*>textureList;

Bonus_SpeedDown::Bonus_SpeedDown(int x, int y, Texture* texture = textureList[SPEEDDOWN])
{
    this->texture = new Texture();
    this->texture = texture;
    bonusRect.x = x;
    bonusRect.y = y;
    bonusRect.w = this->texture->w;
    bonusRect.h = this->texture->h;
    yVel = 3;
    bonus_type = SPEED_DOWN_B;
}

Bonus_SpeedDown::~Bonus_SpeedDown()
{
    delete this->texture;
}

void Bonus_SpeedDown::move()
{
    bonusRect.y += yVel;
}
