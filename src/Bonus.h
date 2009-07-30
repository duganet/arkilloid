//Bonus.h
#ifndef BONUS_H
#define BONUS_H

#include "SDLUtils.h"
#include "Constants.h"
#include "Texture.h"
#include <vector>

enum BonusType
{
    SPEED_UP_B,
    SPEED_DOWN_B,
    LIFE_B,
    DIE_B,
    ADD_BALL_B
};

class Bonus
{
public:
    static std::vector<Bonus*> bonusList;
    Bonus(int x, int y, Texture*,int type);
    Bonus(){};
    virtual ~Bonus();
    void set_up(int x, int y, Texture*,int type);
    virtual void move();
    virtual void show();
    SDL_Rect get_rect();
    int get_type();
protected:
    int yVel;
    Texture *texture;
    SDL_Rect bonusRect;
    int bonus_type;
};

#endif
