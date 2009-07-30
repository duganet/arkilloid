//Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include "SDLUtils.h"
#include "Texture.h"
enum
{
    CLIP_MOUSEOVER,
    CLIP_MOUSEOUT,
    CLIP_MOUSEDOWN,
    CLIP_MOUSEUP
};
enum
{
    CLIP_MOUSEOVER_CHECKED=2,
    CLIP_MOUSEOUT_CHECKED
};

class Button
{
public:
    Button(){};
    Button(int x, int y, std::string filename);
    virtual ~Button();
    virtual void handle_events(SDL_Event &event,void(callback)(void));
    virtual void show();
    virtual SDL_Rect get_rect();
protected:
    SDL_Rect box;
    SDL_Rect clip;
    Texture *buttonSheet;
private:
    SDL_Rect clips[2];
};

#endif
