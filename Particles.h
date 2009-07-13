//Particles.h
#ifndef PARTICLES_H
#define PARTICLES_H

#include "SDLUtils.h"

class Particles
{
public:
    Particles(int x, int y, SDL_Surface *sprite);
    ~Particles();

    void show(SDL_Surface *screen);
    bool is_dead();
private:
    int x,y;
    SDL_Surface *sprite;
    int frame;
    int alpha;
};

#endif
