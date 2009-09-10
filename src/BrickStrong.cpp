//BrickStrong.cpp
#include "BrickStrong.h"
#include "SDLUtils.h"

extern std::ofstream loger;
extern int stateID;
extern int nextState;


BrickStrong::BrickStrong()
{
    texture = new Texture();
    type = STRONG_BRICK_T;
}

BrickStrong::~BrickStrong()
{
    //delete texture;
}

void BrickStrong::set_up(int x, int y, Texture* texture)
{
    this->texture = texture;
    textureList[BRICK_STRONG]->num_hclip = 4;
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = textureList[BRICK_STRONG]->w/4;
    clip[0].h = textureList[BRICK_STRONG]->h;

    clip[1].x = textureList[BRICK_STRONG]->w/4;
    clip[1].y = 0;
    clip[1].w = textureList[BRICK_STRONG]->w/2;
    clip[1].h = textureList[BRICK_STRONG]->h;

    clip[2].x = textureList[BRICK_STRONG]->w/2;
    clip[2].y = 0;
    clip[2].w = textureList[BRICK_STRONG]->w/2 + textureList[BRICK_STRONG]->w/4;
    clip[2].h = textureList[BRICK_STRONG]->h;

    clip[3].x = textureList[BRICK_STRONG]->w/2 + textureList[BRICK_STRONG]->w/4;
    clip[3].y = 0;
    clip[3].w = textureList[BRICK_STRONG]->w;
    clip[3].h = textureList[BRICK_STRONG]->h;

    this->box.x = x;
    this->box.y = y;
    this->box.w = textureList[BRICK_STRONG]->w/4;
    this->box.h = textureList[BRICK_STRONG]->h;

    set_life(3);
}

//void BrickStrong::set_up(int x, int y)
//{
//    clip[0].x = 0;
//    clip[0].y = 0;
//    clip[0].w = this->texture->w/4;
//    clip[0].h = this->texture->h;
//
//    clip[1].x = this->texture->w/4;
//    clip[1].y = 0;
//    clip[1].w = this->texture->w/4;
//    clip[1].h = this->texture->h;
//
//    clip[2].x = this->texture->w/2;
//    clip[2].y = 0;
//    clip[2].w = this->texture->w/4;
//    clip[2].h = this->texture->h;
//
//    clip[3].x = brickStrong_sprite->w/2 + brickStrong_sprite->w/4;
//    clip[3].y = 0;
//    clip[3].w = brickStrong_sprite->w/4;
//    clip[3].h = brickStrong_sprite->h;
//
//    this->box.x = x;
//    this->box.y = y;
//    this->box.w = brickStrong_sprite->w/3;
//    this->box.h = brickStrong_sprite->h;
//
//    set_life(3);
//}

int BrickStrong::get_life()
{
    return life;
}

void BrickStrong::set_life(int l)
{
    life = l;
}

void BrickStrong::show()
{
    SDL_Rect clips;
    switch(life)
    {
    case 3:
        {
            clips = clip[0];
            break;
        }
    case 2:
        {
            clips = clip[1];
            break;
        }
    case 1:
        {
            clips = clip[2];
            break;
        }
    case 0:
        {
            clips = clip[3];
            break;
        }
    }
    textureList[BRICK_STRONG]->show(box.x,box.y,clips);
}
