//Bonus_Die.h
#ifndef BONUS_DIE_H
#define BONUS_DIE_H
#include "Bonus.h"
#include "Texture.h"

class Bonus_Die : public Bonus
{
    public:
    Bonus_Die(int x, int y, Texture*);
    ~Bonus_Die();
    virtual void move();
};

#endif
