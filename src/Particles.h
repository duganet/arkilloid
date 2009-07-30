//Particles.h
#ifndef PARTICLES_H
#define PARTICLES_H

#include "SDLUtils.h"
#include "Texture.h"

extern std::vector<Texture*> textureList;

class Particles
{
public:
    Particles(int x, int y, Texture *texture = textureList[PARTICLE]);
    ~Particles();

    void show();
    bool is_dead();
private:
    int x,y;
    Texture *sprite;
    int frame;
    float alpha;
};

#endif
