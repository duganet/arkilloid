//Window.cpp
#include "Window.h"

extern SDL_Surface* screen;

Window::Window()
{
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(screen == NULL)
    {
        windowOk = false;
        return;
    }
    else
    {
        windowOk = true;
    }
    SDL_WM_SetCaption("Arkilloid", NULL);
    windowed = true;
}

Window::~Window()
{
}

void Window::toggle_fullscreen()
{
    if(windowed == true)
    {
        screen = SDL_SetVideoMode(SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SCREEN_BPP,
                                  SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN);
        if(screen == NULL)
        {
            windowOk = false;
            return;
        }

        windowed = false;
    }
    else if(windowed == false)
    {
        screen = SDL_SetVideoMode(SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SCREEN_BPP,
                                  SDL_HWSURFACE | SDL_DOUBLEBUF);
        if(screen == false)
        {
            windowOk = false;
            return;
        }
        windowed = true;
    }
}

void Window::handle_events(SDL_Event event)
{
    if(windowOk == false)
    {
        return;
    }

    else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F5)
    {
        toggle_fullscreen();
    }
    else if(event.type == SDL_VIDEOEXPOSE)
    {
        if(SDL_Flip(screen) == -1)
        {
           windowOk = false;
           return;
        }
    }
}

bool Window::error()
{
    return !windowOk;
}
