//Help.cpp
#include "Help.h"

extern int stateID;
extern int nextState;
extern std::ofstream loger;
extern std::vector<Texture*>textureList;
extern Mix_Music *music;
extern bool sound_on;

Help::Help()
{
	#ifdef DEBUG
		log("help state");
	#endif
    //bg = textureList[BG_HELP];
    buttonStart = new Button(413,436, "btn_start.png");
    buttonExit = new Button(518,436, "btn_exit.png");
    musicOn = new Checkbox(413, 200, "on_off_button.png");
    if(Mix_PlayingMusic() == 0)
    {
        musicOn->check();
    }
    soundOn = new Checkbox(413, 230, "on_off_button.png");
    if(sound_on == false)
    {
        soundOn->check();
    }
    #ifndef DEBUG
		SDL_WM_GrabInput(SDL_GRAB_OFF);
    #endif
}

void soundOn_checked()
{
    sound_on = false;
}

void soundOn_notchecked()
{
    sound_on = true;
}
void musicOn_checked()
{
    Mix_HaltMusic();
}

void musicOn_notchecked()
{
    Mix_PlayMusic(music, -1);
}

Help::~Help()
{
    delete bg;
    delete buttonExit;
    delete buttonStart;
    delete soundOn;
    delete musicOn;
}

void Help::handle_events(SDL_Event &event)
{
    buttonStart->handle_events(event, buttonStart_click);
    buttonExit->handle_events(event, buttonExit_click);
    if(soundOn->is_checked())
    {
        soundOn->handle_events(event,soundOn_checked);
    }
    else
    {
        soundOn->handle_events(event,soundOn_notchecked);
    }

    if(musicOn->is_checked())
    {
        musicOn->handle_events(event,musicOn_checked);
    }
    else
    {
        musicOn->handle_events(event,musicOn_notchecked);
    }
}

void Help::logic()
{
}

void Help::render()
{
    textureList[BG_HELP]->show(0,0);
    buttonStart->show();
    buttonExit->show();
    soundOn->show();
    musicOn->show();
}
