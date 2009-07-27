//Bita.h
#ifndef BITA_H
#define BITA_H

#include <SDL/SDL.h>

class Bita
{
public:
    Bita();
    ~Bita();
    void set_up(int, int, SDL_Surface *sprite);
    void handle_events(SDL_Event& event);
    void move();
    void show(SDL_Surface *screen);
    SDL_Rect get_rect();
private:
    SDL_Rect box;
    int xVel, yVel;
    SDL_Surface *bita_sprite;
static const int BITA_SPEED = 10;
};
#endif
