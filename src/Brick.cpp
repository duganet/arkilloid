//Brick.cpp
#include "Brick.h"
#include "SDLUtils.h"
#include <sstream>
extern std::ofstream loger;
extern int stateID;
extern int nextState;



Brick::Brick()
{
    type = BRICK;
}

Brick::~Brick()
{
    //clean_up();
}

void Brick::clean_up()
{
    if(brick_sprite)
    {
        SDL_FreeSurface(brick_sprite);
    }
    brick_sprite = NULL;
}

void Brick::set_up(int x, int y, SDL_Surface *sprite)
{
    brick_sprite = sprite;
    this->box.x = x;
    this->box.y = y;
    this->box.w = brick_sprite->w;
    this->box.h = brick_sprite->h;
}

void Brick::set_up(int x, int y)
{
    box.x = x;
    box.y = y;
    box.w = brick_sprite->w;
    box.h = brick_sprite->h;
}

void Brick::show(SDL_Surface *screen)
{
    //apply_surface(box.x+1, box.y+1, brick_sprite, screen);
    apply_surface(box.x, box.y, brick_sprite, screen);
}

void Brick::Collision_check()
{

}

SDL_Rect Brick::get_rect()
{
    return box;
}

void Brick::set_position(int x, int y)
{
    box.x = x;
    box.y = y;
}

//SDL_Surface* Brick::get_sprite()
//{
//    return brick_sprite;
//}

Point Brick::get_center()
{
    Point p;
    p.x = box.x + box.w/2;
    p.y = box.y + box.h/2;
    return p;
}

int Brick::get_type()
{
    return type;
}

int Brick::get_life()
{
    return 0;
}

void Brick::set_life(int i)
{}
