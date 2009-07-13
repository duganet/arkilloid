//BrickBeton.cpp
#include "BrickBeton.h"

BrickBeton::BrickBeton()
{
    type = BRICK_BETON;
}

BrickBeton::~BrickBeton()
{

}

void BrickBeton::set_up(int x, int y, SDL_Surface *sprite)
{
    brickBeton_sprite = sprite;
    this->box.x = x;
    this->box.y = y;
    this->box.w = brickBeton_sprite->w;
    this->box.h = brickBeton_sprite->h;
}

void BrickBeton::show(SDL_Surface* screen)
{
    apply_surface(box.x, box.y, brickBeton_sprite, screen);
}
