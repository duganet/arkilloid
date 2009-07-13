//Title.cpp
#include "Title.h"
#include <sstream>

extern int stateID;
extern int nextState;
extern std::ofstream loger;
extern int lives;
extern int score;
extern int hi_score;

//void set_next_state( int newState )
//{
//    //If the user doesn't want to exit
//    if( nextState != STATE_EXIT )
//    {
//        //Set the next state
//        nextState = newState;
//    }
//}

void buttonStart_click()
{
    set_next_state(STATE_LEVEL_1);
}

void buttonExit_click()
{
    stateID = STATE_EXIT;
}

void buttonHelp_click()
{

}

Title::Title(TTF_Font*font, SDL_Surface *ball_sprite)
{
    bg = image_load("images/bg_title.bmp");
    if(bg == NULL)
    {
        log("ERROR: bg_title.bmp not load");
        stateID = STATE_EXIT;
    }
    buttonStart = new Button(308,436, "images/buttonStart.bmp");
    buttonExit = new Button(518,436, "images/buttonExit.bmp");
    buttonHelp = new Button(413, 436,"images/buttonHelp.bmp");
    ball = new Ball(300,300, ball_sprite, true);
    SDL_Color textColor = {226,67,71};
    version = TTF_RenderText_Blended(font, "V.0.0.1", textColor);
    lives = 3;
    if(score > hi_score)
        hi_score = score;
    score = 0;
    std::stringstream text;
    text << "Hi score: " << hi_score;
    SDL_ShowCursor(true);
    hi_score_show = TTF_RenderText_Blended(font, text.str().c_str(), textColor);
    SDL_WM_GrabInput(SDL_GRAB_OFF);
}

Title::~Title()
{
    SDL_FreeSurface(bg);
    bg = NULL;
    SDL_FreeSurface(version);
    SDL_FreeSurface(hi_score_show);
    hi_score_show = NULL;
    version = NULL;
    delete buttonExit;
    delete buttonStart;
    delete ball;
}

void Title::handle_events(SDL_Event &event)
{
    buttonStart->handle_events(event, buttonStart_click);
    buttonExit->handle_events(event, buttonExit_click);
    buttonHelp->handle_events(event, buttonHelp_click);
}

void Title::logic()
{
    SDL_Rect rect;
    //rect.x = 20;
    //rect.y = 20;
    int collision_type;

    if(ball->collision_check(buttonStart->get_rect()) == 0)
    {
        if(ball->collision_check(buttonExit->get_rect()) == 0)
        {
            if(ball->collision_check(buttonHelp->get_rect()) == 0)
            {
                ball->move(rect, 6, true);
                ball->set_newFrame();
            }
            else
            {
                collision_type = ball->collision_check(buttonHelp->get_rect());
                ball->move(rect, collision_type, true);
                ball->set_newFrame();
            }
        }
        else
        {
            collision_type = ball->collision_check(buttonExit->get_rect());
            ball->move(rect, collision_type, true);
            ball->set_newFrame();
        }
    }
    else
    {
        collision_type = ball->collision_check(buttonStart->get_rect());
        ball->move(rect, collision_type, true);
        ball->set_newFrame();
    }
}

void Title::render(SDL_Surface *screen)
{
    apply_surface(0,0,bg,screen);
    buttonStart->show(screen);
    buttonExit->show(screen);
    buttonHelp->show(screen);
    ball->show(screen);
    apply_surface(520, 30, version, screen);
    apply_surface(50, 30, hi_score_show, screen);
}
