//Window.h
#ifndef WINDOW_H
#define WINDOW_H
#include "Constants.h"
#include "SDLUtils.h"

class Window
{
public:
    Window();
    ~Window();
    void toggle_fullscreen();
    void handle_events(SDL_Event event);
    bool error();
private:
    bool windowed;
    bool windowOk;
};

#endif
