//BrickStrong.h
#ifndef BRICKSTRONG_H
#define BRICKSTRONG_H

#include "Brick.h"
#include "Texture.h"

extern std::vector<Texture*>textureList;

class BrickStrong : public Brick
{
public:
    BrickStrong();
    virtual ~BrickStrong();
    virtual void set_up(int x, int y, Texture *texture = textureList[BRICK_STRONG]);
    virtual void show();
    int get_life();
    void set_life(int l);
    //void sprite_change();
private:
    int life;
    SDL_Rect clip[4];
    Texture *texture;
};


#endif
