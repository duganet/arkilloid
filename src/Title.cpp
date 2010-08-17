//Title.cpp
#include "Title.h"
#include <sstream>
#include <vector>

extern int stateID;
extern int nextState;
extern std::ofstream loger;
extern int lives;
extern int score;
extern int hi_score;
extern std::vector<Texture*> textureList;
extern GLFT_Font font;
extern Mix_Music *music;
//void set_next_state( int newState )
//{
//    //If the user doesn't want to exit
//    if( nextState != STATE_EXIT )
//    {
//        //Set the next state
//        nextState = newState;
//    }
//}

//void buttonStart_click()
//{
//    set_next_state(STATE_LEVEL_1);
//}
//
//void buttonExit_click()
//{
//    stateID = STATE_EXIT;
//}

void buttonHelp_click()
{
    set_next_state(STATE_HELP);
}

Title::Title()
{
    //bg = imageList[BG_TITLE];
    ball = new Ball(300,300);
    buttonStart = new Button(524,380, "btn_start.png");
	buttonHelp = new Button(413, 436,"btn_help.png");
    buttonExit = new Button(518,436, "btn_exit.png");
    lives = 3;
    if(score > hi_score)
        hi_score = score;
    score = 0;
    SDL_ShowCursor(true);
    #ifndef DEBUG
    SDL_WM_GrabInput(SDL_GRAB_OFF);
    #endif
    Mix_PlayMusic(music, -1);
}

Title::~Title()
{
    hi_score_show = NULL;
    version = NULL;
    delete buttonExit;
    delete buttonStart;
    delete buttonHelp;
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

    collision_type = ball->collision_check(buttonStart->get_rect());
    if(collision_type == NO_COLLISION)
    {
        collision_type = ball->collision_check(buttonHelp->get_rect());
        if(collision_type == NO_COLLISION)
        {
            collision_type = ball->collision_check(buttonExit->get_rect());
            if(collision_type == NO_COLLISION)
            {
                ball->move(rect, COLLISION_BOTTOM_NEED, true);
            }
            else
            {
                ball->move(rect, collision_type, true);
            }
        }
        else
        {
            ball->move(rect, collision_type, true);
        }
    }
    else
    {
        ball->move(rect, collision_type, true);
    }
}

void Title::render()
{
    textureList[BG_TITLE]->show(0,0);
    buttonStart->show();
    buttonHelp->show();
    buttonExit->show();
    ball->show();

    font.beginDraw(50,30) << "Hi score: " << hi_score << font.endDraw();
    #ifndef DEBUG
		font.drawText(520,30,"V.0.0.1");
	#else
		font.drawText(520,30,"V.0.0.1 DEBUG");
	#endif
}
