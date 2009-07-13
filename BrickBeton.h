//BrickBeton.h
#ifndef BRICK_BETON_H
#define BRICK_BETON_H
#include "BrickStrong.h"
#include "Timer.h"

class BrickBeton : public Brick
{
public:
    BrickBeton();
    virtual ~BrickBeton();
    virtual void set_up(int x, int y, SDL_Surface *sprite);
    virtual void show(SDL_Surface *screen);
    void set_collision_type(int type);
private:
    SDL_Surface *brickBeton_sprite;
    SDL_Rect clip[5];
    int collision_type;
    Timer timer;
};
#endif
