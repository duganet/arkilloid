//Particles.cpp
#include "Particles.h"
#include <cmath>



const int PI = 3;

Particles::Particles(int x, int y, Texture *texture)
{
    this->x = x - 5 + ( rand() % 34 );
    this->y = y - 5 + ( rand() % 18 );

    frame = 0;
    this->sprite = new Texture();
    this->sprite = texture;
    alpha = 1.0;
}

Particles::~Particles()
{
}

void Particles::show()
{
    int direction = rand() % 360;

    int xVel = (int)(cos(direction*(PI/180))*5);


    //x +=xVel;
    y += xVel;
    if( frame % 1 == 0 )
    {
        alpha -=0.05;
        if(alpha < 0)
         alpha = 0;
//        SDL_SetAlpha( sprite, SDL_SRCALPHA | SDL_RLEACCEL, alpha );
    }
    //Animate
    sprite->show(x,y, alpha);
    frame++;
}

bool Particles::is_dead()
{
    if(frame > 10)
    {
        return true;
    }
    return false;
}
