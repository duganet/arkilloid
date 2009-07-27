//Bonus_speedDown
#ifndef BONUS_SPEEDDOWN
#define BONUS_SPEEDDOWN
#include "Bonus.h"

class Bonus_SpeedDown : public Bonus
{
public:
    Bonus_SpeedDown(int x, int y, SDL_Surface *sprite);
    ~Bonus_SpeedDown();
    virtual void move();
};
#endif
