//BrickStrong.cpp
#include "BrickStrong.h"
#include "SDLUtils.h"

extern std::ofstream loger;
extern int stateID;
extern int nextState;

BrickStrong::BrickStrong()
{

//    brick_sprite = image_load("images/brick.bmp", 0xFF, 0, 0xFF);
//
//    if(brick_sprite == NULL)
//    {
//        log("ERROR: brick image not loaded!");
//        stateID = STATE_EXIT;
//    }
    type = STRONG_BRICK;
}

BrickStrong::~BrickStrong()
{
//    SDL_FreeSurface(brick_sprite);
//    brick_sprite = NULL;
}

void BrickStrong::set_up(int x, int y, SDL_Surface* sprite)
{
    brickStrong_sprite = sprite;
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = brickStrong_sprite->w/4;
    clip[0].h = brickStrong_sprite->h;

    clip[1].x = brickStrong_sprite->w/4;
    clip[1].y = 0;
    clip[1].w = brickStrong_sprite->w/4;
    clip[1].h = brickStrong_sprite->h;

    clip[2].x = brickStrong_sprite->w/2;
    clip[2].y = 0;
    clip[2].w = brickStrong_sprite->w/4;
    clip[2].h = brickStrong_sprite->h;

    clip[3].x = brickStrong_sprite->w/2 + brickStrong_sprite->w/4;
    clip[3].y = 0;
    clip[3].w = brickStrong_sprite->w/4;
    clip[3].h = brickStrong_sprite->h;

    this->box.x = x;
    this->box.y = y;
    this->box.w = brickStrong_sprite->w/3;
    this->box.h = brickStrong_sprite->h;

    set_life(3);
}

void BrickStrong::set_up(int x, int y)
{
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = brickStrong_sprite->w/4;
    clip[0].h = brickStrong_sprite->h;

    clip[1].x = brickStrong_sprite->w/4;
    clip[1].y = 0;
    clip[1].w = brickStrong_sprite->w/4;
    clip[1].h = brickStrong_sprite->h;

    clip[2].x = brickStrong_sprite->w/2;
    clip[2].y = 0;
    clip[2].w = brickStrong_sprite->w/4;
    clip[2].h = brickStrong_sprite->h;

    clip[3].x = brickStrong_sprite->w/2 + brickStrong_sprite->w/4;
    clip[3].y = 0;
    clip[3].w = brickStrong_sprite->w/4;
    clip[3].h = brickStrong_sprite->h;

    this->box.x = x;
    this->box.y = y;
    this->box.w = brickStrong_sprite->w/3;
    this->box.h = brickStrong_sprite->h;

    set_life(3);
}

int BrickStrong::get_life()
{
    return life;
}

void BrickStrong::set_life(int l)
{
    life = l;
}

void BrickStrong::show(SDL_Surface *screen)
{
    switch(life)
    {
    case 3:
        {
            //apply_surface(box.x+1,box.y+1,brickStrong_sprite,screen,&clip[0]);
            apply_surface(box.x,box.y,brickStrong_sprite,screen,&clip[0]);
            break;
        }
    case 2:
        {
            //apply_surface(box.x+1,box.y+1,brickStrong_sprite,screen,&clip[1]);
            apply_surface(box.x,box.y,brickStrong_sprite,screen,&clip[1]);
            break;
        }
    case 1:
        {
            //apply_surface(box.x+1,box.y+1,brickStrong_sprite,screen,&clip[2]);
            apply_surface(box.x,box.y,brickStrong_sprite,screen,&clip[2]);
            break;
        }
    case 0:
        {
            //apply_surface(box.x+1,box.y+1,brickStrong_sprite,screen,&clip[3]);
            apply_surface(box.x,box.y,brickStrong_sprite,screen,&clip[3]);
            break;
        }
    }
}
