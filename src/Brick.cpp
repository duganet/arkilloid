//Brick.cpp
#include "Brick.h"
#include "SDLUtils.h"
#include <sstream>
//extern std::ofstream loger;
extern int stateID;
extern int nextState;



Brick::Brick()
{
    type = BRICK;
    texture = new Texture();
}

Brick::~Brick()
{
    //clean_up();
}

void Brick::clean_up()
{
}

void Brick::set_up(int x, int y, Texture* texture)
{
    this->texture = texture;
    this->box.x = x;
    this->box.y = y;
    this->box.w = this->texture->w;
    this->box.h = this->texture->h;
}

//void Brick::set_up(int x, int y)
//{
//    box.x = x;
//    box.y = y;
//    box.w = this->texture->w;
//    box.h = this->texture->h;
//}

void Brick::show()
{
    //this->texture->show(box.x, box.y);
    textureList[BRICK]->show(box.x,box.y);
}

void Brick::Collision_check()
{

}

unsigned int Brick::get_pg() {
	return 0;
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

int Brick::get_x()
{
	return this->box.x;
}

int Brick::get_y()
{
	return this->box.y;
}

void Brick::set_collision_type(int type)
{
    collision_type = type;
    timer.Start();
}

void Brick::set_life(int i)
{}
