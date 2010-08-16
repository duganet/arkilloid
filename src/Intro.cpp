//Intro.cpp
#include "Intro.h"


extern int stateID;
extern int nextState;
extern int lives;
extern std::vector<Mix_Chunk*> soundList;
extern std::vector<Texture*> textureList;


Intro::Intro()
{
    bg = textureList[BG_INTRO];
    introTime.Start();
}

Intro::~Intro()
{
    delete bg;
}

void Intro::handle_events(SDL_Event &event)
{
    if(((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RETURN))||
         (event.type == SDL_MOUSEBUTTONDOWN))
    {
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

void Intro::render()
{
    textureList[BG_INTRO]->show(0,0);
}



