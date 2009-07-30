//Bita.h
#ifndef BITA_H
#define BITA_H

#include <SDL/SDL.h>
#include "SDLUtils.h"
#include "Texture.h"
#include <vector>

extern std::vector<Texture*> textureList;

class Bita
{
public:
    Bita();
    ~Bita();
    void set_up(int, int, Texture* texture = textureList[BITA]);
    void handle_events(SDL_Event& event);
    void move();
    void show();
    SDL_Rect get_rect();
private:
    SDL_Rect box;
    int xVel, yVel;
    Texture *texture;
static const int BITA_SPEED = 10;
};
#endif
