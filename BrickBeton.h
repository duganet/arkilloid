//BrickBeton.h
#ifndef BRICK_BETON_H
#define BRICK_BETON_H
#include "BrickStrong.h"

class BrickBeton : public Brick
{
public:
    BrickBeton();
    virtual ~BrickBeton();
    virtual void set_up(int x, int y, SDL_Surface *sprite);
    virtual void show(SDL_Surface *screen);
private:
    SDL_Surface *brickBeton_sprite;
};
#endif
