//Brick.h
#ifndef BRICK_H
#define BRICK_H
#include "SDLUtils.h"
#include <vector>
#include "Texture.h"
#include "Timer.h"

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
    int collision_type;
    SDL_Rect get_rect();
    Point get_center();
    void set_position(int x, int y);
    void clean_up();
    int get_type();
    virtual int get_life();
    virtual unsigned int get_pg();
	virtual int get_x();
	virtual int get_y();
    virtual void set_life(int);
    void set_collision_type(int type);
    Timer timer;
	//virtual void set_pg(unsigned int group);
protected:
    SDL_Rect box;
    int type;
private:
    Texture *texture;
};

#endif
