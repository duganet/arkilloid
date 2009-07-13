//Bonus_speed.h
#ifndef BONUS_SPEED_H
#define BONUS_SPEED_H

#include "Bonus.h"

class Bonus_Speed : public Bonus
{
    public:
    Bonus_Speed(int x, int y, SDL_Surface *sprite);
    ~Bonus_Speed();
    virtual void move();
};


#endif
