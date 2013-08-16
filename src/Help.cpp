//Help.cpp
#include "Help.h"
#include "Game.h"
#include <report.hpp>
#include <sound.hpp>

extern int stateID;
extern int nextState;
extern std::ofstream loger;
extern std::vector<Texture*>textureList;
extern bool sound_on;
extern AudioMusic *audio_music;
//extern Game game;

Help::Help()
{
	report("help state", MSG_DEBUG);
    //bg = textureList[BG_HELP];
    HelpButtonExit = new Button(518,436, "btn_exit.png");
    musicOn = new Checkbox(417, 90, "on_off_button.png");
	if (Mix_PausedMusic())
	{
		musicOn->uncheck();
	}
	soundOn = new Checkbox(417, 150, "on_off_button.png");
	if(sound_on == false)
	{
		soundOn->uncheck();
	}
	#ifndef DEBUG
		SDL_WM_GrabInput(SDL_GRAB_OFF);
	#endif
}

void HelpButtonExit_click()
{
    set_next_state(STATE_TITLE);
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
    audio_music->Off();
}
void musicOn_notchecked()
{
	audio_music->On();
}

Help::~Help()
{
    delete bg;
    delete HelpButtonExit;
    delete soundOn;
    delete musicOn;
}

void Help::handle_events(SDL_Event &event)
{
    HelpButtonExit->handle_events(event, HelpButtonExit_click);
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
    HelpButtonExit->show();
    soundOn->show();
    musicOn->show();
}
