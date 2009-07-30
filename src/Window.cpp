//Window.cpp
#include "Window.h"

Window::Window()
{
    if(SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,SDL_OPENGL) == NULL)
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
        if(SDL_SetVideoMode(SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SCREEN_BPP,
                                    SDL_OPENGL |SDL_FULLSCREEN) == NULL)
        {
            windowOk = false;
            return;
        }

        windowed = false;
    }
    else if(windowed == false)
    {
        if(SDL_SetVideoMode(SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SCREEN_BPP,
                                  SDL_OPENGL) == false)
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
        SDL_GL_SwapBuffers();
    }
}

bool Window::error()
{
    return !windowOk;
}
