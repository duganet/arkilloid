//BrickBeton.h
#ifndef BRICK_BETON_H
#define BRICK_BETON_H
#include "BrickStrong.h"
#include "Timer.h"

extern std::vector<Texture*>textureList;

class BrickBeton : public Brick
{
public:
    BrickBeton();
    virtual ~BrickBeton();
    virtual void set_up(int x, int y, Texture* texture= textureList[BRICK_BETON]);
    virtual void show();
    void set_collision_type(int type);
private:
    Texture *texture;
    SDL_Rect clip[5];
    int collision_type;
    Timer timer;
};
#endif
