//BrickControl.h
#ifndef BRICK_CONTROL_H
#define BRICK_CONTROL_H

//#include "Brick.h"
#include "SDLUtils.h"
#include "BrickStrong.h"
#include "BrickBeton.h"
#include <vector>

class BrickControl
{
public:
    static std::vector<Brick*> brickList;
    //static std::vector<BrickStrong> brickStrongList;
    static bool LoadBricksFromFile(const char*,SDL_Surface* brick_sprite, SDL_Surface *brickStrong_sprite, SDL_Surface* brickBeton_sprite);
    BrickControl();
    ~BrickControl();
private:

};

#endif
