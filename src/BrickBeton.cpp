//BrickBeton.cpp
#include "BrickBeton.h"
#include "Constants.h"


BrickBeton::BrickBeton()
{
    texture = new Texture();
    collision_type = NO_COLLISION;
    type = BRICK_BETON_T;
}

BrickBeton::~BrickBeton()
{
}

void BrickBeton::set_up(int x, int y, Texture *texture)
{
    this->texture = new Texture();
    this->texture = texture;
    textureList[BRICK_BETON]->num_hclip = 5;

    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = textureList[BRICK_BETON]->w/5;
    clip[0].h = textureList[BRICK_BETON]->h;

    clip[1].x = textureList[BRICK_BETON]->w/5;
    clip[1].y = 0;
    clip[1].w = textureList[BRICK_BETON]->w/5 * 2;
    clip[1].h = textureList[BRICK_BETON]->h;

    clip[2].x = textureList[BRICK_BETON]->w/5 * 2;
    clip[2].y = 0;
    clip[2].w = textureList[BRICK_BETON]->w/5 * 3;
    clip[2].h = textureList[BRICK_BETON]->h;

    clip[3].x = textureList[BRICK_BETON]->w/5 * 3;
    clip[3].y = 0;
    clip[3].w = textureList[BRICK_BETON]->w/5 * 4;
    clip[3].h = textureList[BRICK_BETON]->h;

    clip[4].x = textureList[BRICK_BETON]->w/5 * 4;
    clip[4].y = 0;
    clip[4].w = textureList[BRICK_BETON]->w;
    clip[4].h = textureList[BRICK_BETON]->h;

    this->box.x = x;
    this->box.y = y;
    this->box.w = textureList[BRICK_BETON]->w/5;
    this->box.h = textureList[BRICK_BETON]->h;
}

void BrickBeton::show()
{
    SDL_Rect clips;
    if(timer.Get_Ticks() >= 200)
    {
        timer.Stop();
        collision_type = 0;
    }
    switch(collision_type)
    {
    case NO_COLLISION:
        clips = clip[0];
        break;
    case COLLISION_BOTTOM:
        clips = clip[1];
        break;
    case COLLISION_TOP:
        clips = clip[2];
        break;
    case COLLISION_RIGHT:
        clips = clip[3];
        break;
    case COLLISION_LEFT:
        clips = clip[4];
        break;
    }
    textureList[BRICK_BETON]->show(box.x,box.y,clips);
}

void BrickBeton::set_collision_type(int type)
{
    collision_type = type;
    timer.Start();
}
