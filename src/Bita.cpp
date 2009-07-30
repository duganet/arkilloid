//Bita.cpp
#include "Bita.h"
#include "Constants.h"
#include "SDLUtils.h"



Bita::Bita()
{
    texture = new Texture();
}

void Bita::set_up(int X, int Y, Texture *texture)
{
    this->texture = texture;
    box.x = X;
    box.y = Y;
    box.w = texture->w;
    box.h = texture->h;
    xVel = 0;
    yVel = 0;
}

Bita::~Bita()
{
    //delete texture;
}

void Bita::handle_events(SDL_Event &event)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_LEFT:   xVel -= BITA_SPEED;break;
        case SDLK_RIGHT:  xVel += BITA_SPEED;break;
        default: break;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_LEFT:   xVel += BITA_SPEED;break;
        case SDLK_RIGHT:  xVel -= BITA_SPEED;break;
        default:break;
        }
    }
    if(event.type == SDL_MOUSEMOTION)
    {
        box.x = event.motion.x - box.w/2;
        if(box.x < 0)
            box.x = 0;
        if(box.x+box.w > SCREEN_WIDTH)
            box.x = SCREEN_WIDTH - box.w;
    }
}

void Bita::move()
{
    box.x += xVel;
    if((box.x < 0)||(box.x + box.w) > SCREEN_WIDTH)
    {
        box.x -= xVel;
    }
}

void Bita::show()
{
    texture->show(box.x, box.y);
}

SDL_Rect Bita::get_rect()
{
    return box;
}
