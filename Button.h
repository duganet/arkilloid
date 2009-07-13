//Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include "SDLUtils.h"

enum
{
    CLIP_MOUSEOVER,
    CLIP_MOUSEOUT,
    CLIP_MOUSEDOWN,
    CLIP_MOUSEUP
};

class Button
{
public:
    Button(int x, int y, std::string filename);
    ~Button();
    void handle_events(SDL_Event &event,void(callback)(void));
    void show(SDL_Surface *screen);
    SDL_Rect get_rect();
private:
    SDL_Rect box;
    SDL_Rect clips[2];
    SDL_Rect clip;
    SDL_Surface *buttonSheet;
};

#endif
