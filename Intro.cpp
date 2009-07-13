//Intro.cpp
#include "Intro.h"


extern int stateID;
extern int nextState;
extern int lives;
extern std::vector<Mix_Chunk*> soundList;
Intro::Intro()
{
    bg = image_load("images/intro_bg.bmp");
    Mix_PlayChannel(-1, soundList[2], 0);
    introTime.Start();
}

Intro::~Intro()
{
    SDL_FreeSurface(bg);
}

void Intro::handle_events(SDL_Event &event)
{
    if(((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RETURN))||
         (event.type == SDL_MOUSEBUTTONDOWN))
    {
        if(Mix_Playing(-1) != 0)
            Mix_Pause(-1);
        set_next_state( STATE_TITLE );
    }
}

void Intro::logic()
{
    if(introTime.Get_Ticks() > 3000)
    {
        //if(Mix_Playing(-1) != 0)

        set_next_state(STATE_TITLE);
    }
}

void Intro::render(SDL_Surface *screen)
{
    apply_surface(0,0,bg,screen);
}



