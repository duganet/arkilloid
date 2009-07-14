//BrickBeton.cpp
#include "BrickBeton.h"
#include "Constants.h"

BrickBeton::BrickBeton()
{
    collision_type = NO_COLLISION;
    type = BRICK_BETON;
}

BrickBeton::~BrickBeton()
{

}

void BrickBeton::set_up(int x, int y, SDL_Surface *sprite)
{
    brickBeton_sprite = sprite;

    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = brickBeton_sprite->w/5;
    clip[0].h = brickBeton_sprite->h;

    clip[1].x = brickBeton_sprite->w/5;
    clip[1].y = 0;
    clip[1].w = brickBeton_sprite->w/5;
    clip[1].h = brickBeton_sprite->h;

    clip[2].x = brickBeton_sprite->w/5 * 2;
    clip[2].y = 0;
    clip[2].w = brickBeton_sprite->w/5;
    clip[2].h = brickBeton_sprite->h;

    clip[3].x = brickBeton_sprite->w/5 * 3;
    clip[3].y = 0;
    clip[3].w = brickBeton_sprite->w/5;
    clip[3].h = brickBeton_sprite->h;

    clip[4].x = brickBeton_sprite->w/5 * 4;
    clip[4].y = 0;
    clip[4].w = brickBeton_sprite->w/5;
    clip[4].h = brickBeton_sprite->h;

    this->box.x = x;
    this->box.y = y;
    this->box.w = brickBeton_sprite->w/5;
    this->box.h = brickBeton_sprite->h;
}

void BrickBeton::show(SDL_Surface* screen)
{
    if(timer.Get_Ticks() >= 200)
    {
        timer.Stop();
        collision_type = 0;
    }
    switch(collision_type)
    {
    case NO_COLLISION:
        apply_surface(box.x, box.y, brickBeton_sprite, screen, &clip[0]);
        break;
    case COLLISION_BOTTOM:
        apply_surface(box.x, box.y, brickBeton_sprite, screen, &clip[1]);
        break;
    case COLLISION_TOP:
        apply_surface(box.x, box.y, brickBeton_sprite, screen, &clip[2]);
        break;
    case COLLISION_RIGHT:
        apply_surface(box.x, box.y, brickBeton_sprite, screen, &clip[3]);
        break;
    case COLLISION_LEFT:
        apply_surface(box.x, box.y, brickBeton_sprite, screen, &clip[4]);
        break;
    }
}

void BrickBeton::set_collision_type(int type)
{
    collision_type = type;
    timer.Start();
}
