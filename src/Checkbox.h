//Checkbox.h
#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "Button.h"
#include <io.hpp>

class Checkbox : public Button
{
public:
    Checkbox(int x, int y, std::string filename);
    bool is_checked()
    {return checked;}
    void check();
    void handle_events(SDL_Event &event,void(callback)(void));
private:
    bool checked;
    SDL_Rect clips[4];
};

#endif
