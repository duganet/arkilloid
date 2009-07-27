//Bonus_Life.h
#ifndef BONUS_LIFE_H
#define BONUS_LIFE_H
#include "Bonus.h"

class Bonus_Life : public Bonus
{
    public:
    Bonus_Life(int x, int y, SDL_Surface *sprite);
    ~Bonus_Life();
    virtual void move();
};
#endif
