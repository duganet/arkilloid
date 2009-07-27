//Birck.h
#ifndef BRICK_H
#define BIRCK_H
#include "SDLUtils.h"
#include <vector>

class Brick
{
public:

    Brick();
    virtual~Brick();
    virtual void set_up(int x, int y, SDL_Surface* sprite);
    virtual void set_up(int x, int y);
    virtual void show(SDL_Surface *screen);
    void Collision_check();
    SDL_Rect get_rect();
    Point get_center();
    void set_position(int x, int y);
    void clean_up();
    int get_type();
    virtual int get_life();
    virtual void set_life(int);
    virtual void set_collision_type(int){};
    //SDL_Surface* Brick::get_sprite();
protected:
    SDL_Rect box;
    int type;
private:
    SDL_Surface *brick_sprite;
};

#endif
