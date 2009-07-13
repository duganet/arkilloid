//Bonus_Die.h
#ifndef BONUS_DIE_H
#define BONUS_DIE_H
#include "Bonus.h"

class Bonus_Die : public Bonus
{
    public:
    Bonus_Die(int x, int y, SDL_Surface *sprite);
    ~Bonus_Die();
    virtual void move();
};

#endif
