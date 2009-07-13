//Title.h
#ifndef TITLE_H
#define TITLE_H
#include "Intro.h"
#include "Button.h"
#include "Ball.h"
class Title : public Intro
{
public:
    Title(TTF_Font*font, SDL_Surface* sprite);
    ~Title();
    void handle_events(SDL_Event &event);
    void logic();
    void render(SDL_Surface *screen);
//    void buttonExit_click();
//    void buttonStart_click();
private:
    Button *buttonStart;
    Button *buttonExit;
    Button *buttonHelp;
    Ball *ball;
    SDL_Surface *version;
    SDL_Surface *hi_score_show;
};


#endif
