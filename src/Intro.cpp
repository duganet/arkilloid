//Intro.cpp
#include "Intro.h"
#include <io.hpp>

extern int stateID;
extern int nextState;
extern int lives;
extern std::vector<Mix_Chunk*> soundList;
extern std::vector<Texture*> textureList;


Intro::Intro()
{
	report("Intro::Intro constructor started", MSG_DEBUG);
    bg = textureList[BG_INTRO];
    introTime.Start();
    report("Intro::Intro constructor finished", MSG_DEBUG);
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
        set_next_state(STATE_TITLE);
    }
}

void Intro::render()
{
	report("Intro::render() started", MSG_DEBUG);
	
    textureList[BG_INTRO]->show(0,0);
    
    report("Intro::render() finished", MSG_DEBUG);
}



