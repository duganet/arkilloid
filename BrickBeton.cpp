//BrickBeton.cpp
#include "BrickBeton.h"
#include "Constants.h"
#include <map>

extern std::vector<SDL_Surface*> imageList;

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
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = imageList[BRICK_BETON_SPR]->w/5;
    clip[0].h = imageList[BRICK_BETON_SPR]->h;

    clip[1].x = imageList[BRICK_BETON_SPR]->w/5;
    clip[1].y = 0;
    clip[1].w = imageList[BRICK_BETON_SPR]->w/5;
    clip[1].h = imageList[BRICK_BETON_SPR]->h;

    clip[2].x = imageList[BRICK_BETON_SPR]->w/5 * 2;
    clip[2].y = 0;
    clip[2].w = imageList[BRICK_BETON_SPR]->w/5;
    clip[2].h = imageList[BRICK_BETON_SPR]->h;

    clip[3].x = imageList[BRICK_BETON_SPR]->w/5 * 3;
    clip[3].y = 0;
    clip[3].w = imageList[BRICK_BETON_SPR]->w/5;
    clip[3].h = imageList[BRICK_BETON_SPR]->h;

    clip[4].x = imageList[BRICK_BETON_SPR]->w/5 * 4;
    clip[4].y = 0;
    clip[4].w = imageList[BRICK_BETON_SPR]->w/5;
    clip[4].h = imageList[BRICK_BETON_SPR]->h;

    this->box.x = x;
    this->box.y = y;
    this->box.w = imageList[BRICK_BETON_SPR]->w/5;
    this->box.h = imageList[BRICK_BETON_SPR]->h;
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
        apply_surface(box.x, box.y, imageList[BRICK_BETON_SPR], screen, &clip[0]);
        break;
    case COLLISION_BOTTOM:
        apply_surface(box.x, box.y, imageList[BRICK_BETON_SPR], screen, &clip[1]);
        break;
    case COLLISION_TOP:
        apply_surface(box.x, box.y, imageList[BRICK_BETON_SPR], screen, &clip[2]);
        break;
    case COLLISION_RIGHT:
        apply_surface(box.x, box.y, imageList[BRICK_BETON_SPR], screen, &clip[3]);
        break;
    case COLLISION_LEFT:
        apply_surface(box.x, box.y, imageList[BRICK_BETON_SPR], screen, &clip[4]);
        break;
    }
}

void BrickBeton::set_collision_type(int type)
{
    collision_type = type;
    timer.Start();
}
