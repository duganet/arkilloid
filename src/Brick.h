//Birck.h
#ifndef BRICK_H
#define BIRCK_H
#include "SDLUtils.h"
#include <vector>
#include "Texture.h"

extern std::vector<Texture*>textureList;

class Brick
{
public:

    Brick();
    virtual~Brick();
    virtual void set_up(int x, int y, Texture*texture = textureList[BRICK]);
    //virtual void set_up(int x, int y);
    virtual void show();
    void Collision_check();
    SDL_Rect get_rect();
    Point get_center();
    void set_position(int x, int y);
    void clean_up();
    int get_type();
    virtual int get_life();
    virtual void set_life(int);
    virtual void set_collision_type(int){};
protected:
    SDL_Rect box;
    int type;
private:
    Texture *texture;
};

#endif
