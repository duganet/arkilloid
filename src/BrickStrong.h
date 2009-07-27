//BrickStrong.h
#ifndef BRICKSTRONG_H
#define BRICKSTRONG_H

#include "Brick.h"

class BrickStrong : public Brick
{
public:
    BrickStrong();
    virtual ~BrickStrong();
    virtual void set_up(int x, int y, SDL_Surface* sprite);
    virtual void set_up(int x, int y);
    virtual void show(SDL_Surface *screen);
    int get_life();
    void set_life(int l);
    void sprite_change();
private:
    int life;
    SDL_Rect clip[4];
    SDL_Surface *brickStrong_sprite;
};


#endif
