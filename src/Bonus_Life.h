//Bonus_Life.h
#ifndef BONUS_LIFE_H
#define BONUS_LIFE_H
#include "Bonus.h"
#include "Texture.h"

class Bonus_Life : public Bonus
{
    public:
    Bonus_Life(int x, int y, Texture*);
    ~Bonus_Life();
    virtual void move();
};
#endif
