//Bonus.h
#ifndef BONUS_H
#define BONUS_H

#include "SDLUtils.h"
#include "Constants.h"
#include <vector>

enum BonusType
{
    SPEED_UP,
    SPEED_DOWN,
    LIFE,
    DIE,
    ADD_BALL
};

class Bonus
{
public:
    static std::vector<Bonus*> bonusList;
    Bonus(int x, int y, SDL_Surface *sprite,int type);
    Bonus(){};
    virtual ~Bonus();
    void set_up(int x, int y, SDL_Surface *sprite,int type);
    virtual void move();
    virtual void show(SDL_Surface *screen);
    SDL_Rect get_rect();
    int get_type();
protected:
    int yVel;
    SDL_Surface* bonus_sprite;
    SDL_Rect bonusRect;
    int bonus_type;
};

#endif
