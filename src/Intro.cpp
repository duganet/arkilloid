//Intro.cpp
#include "Intro.h"


extern int stateID;
extern int nextState;
extern int lives;
extern std::vector<Mix_Chunk*> soundList;
extern std::vector<SDL_Surface*> imageList;
extern Mix_Music *music;
extern SDL_Surface *buffer;

Intro::Intro()
{
    bg = imageList[BG_INTRO];
    introTime.Start();
    Mix_PlayChannel(-1, soundList[2], 0);
    //Mix_PlayChannel(-1, soundList[4], -1);
	Mix_PlayMusic(music, -1);
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
    apply_surface(0,0,bg,buffer);
}



