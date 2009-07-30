//Bonus_speedDown
#ifndef BONUS_SPEEDDOWN
#define BONUS_SPEEDDOWN
#include "Bonus.h"
#include "Texture.h"

class Bonus_SpeedDown : public Bonus
{
public:
    Bonus_SpeedDown(int x, int y, Texture*);
    ~Bonus_SpeedDown();
    virtual void move();
};
#endif
