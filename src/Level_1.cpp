//Level_1.cpp
#include "Level_1.h"
#include "Constants.h"
#include "Globals.h"
#include <sstream>

extern int stateID;
extern int nextState;
extern int lives;
extern std::vector<Mix_Chunk*> soundList;
extern Mix_Chunk *snd_bonusget;
extern std::vector<Texture*> textureList;
extern Mix_Music *music;
extern int score;
extern int hi_score;
extern GLFT_Font font;
extern GLFT_Font fontLevel;
extern GLFT_Font font_small;
extern bool sound_on;

bool Level_1::pause;
//int Level_1::num_level;
bool Level_1::restarted;

void restartButton_click()
{
    Level_1::restarted = true;
}

void resumeButton_click()
{
    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(false);

    Level_1::pause=false;
}

void exitButton_click()
{
    set_next_state(STATE_EXIT);
}

void soundOn_checked_pause()
{
    sound_on = false;
}

void soundOn_notchecked_pause()
{
    sound_on = true;
}
void musicOn_checked_pause()
{
    Mix_HaltMusic();
}

void musicOn_notchecked_pause()
{
    Mix_PlayMusic(music, -1);
}

Level_1::Level_1(int num_level, std::string filename)
{
    std::string dir;
    filename = path_construct("maps", filename);
    log("level_1 constructor");
    restarted = false;
    //levelFont = font;
    SDL_WM_GrabInput(SDL_GRAB_ON);
    this->num_level = num_level;
   // SDL_Color textColor = {226,67,71};
    //back = bg;

    if(!BrickControl::LoadBricksFromFile(filename.c_str()))
    {
        log("map not load");
    }
    bita.set_up(300, 570);

    if(Ball::ballList.size() <= 0)
    {
        ball = new Ball(bita.get_rect().x + (bita.get_rect().w/2), (int)bita.get_rect().y, false);
        Ball::ballList.push_back(ball);
    }
    else
    {
        Ball::ballList.erase(Ball::ballList.begin(),Ball::ballList.end());
        ball = new Ball(bita.get_rect().x + (bita.get_rect().w/2), (int)bita.get_rect().y, false);
        Ball::ballList.push_back(ball);
    }

    if(Bonus::bonusList.size() > 0)
    {
        for(unsigned int i = 0; i < Bonus::bonusList.size(); i++)
        {
            Bonus::bonusList.erase(Bonus::bonusList.begin() + i);
        }
    }

    //ball.set_up(bita.get_rect().x + (bita.get_rect().w/2), bita.get_rect().y, ball_sprite);
    collision_type = 0;
    SDL_ShowCursor(false);

    begin = false;
    clear = false;
    bonus_created = false;
    timer.Start();
    bonus = NULL;

    //heart_spr = new Texture();
    //heart_spr = textureList[HEART];
    game_over = false;
    life_label = NULL;
    prevScore = score;
    prevLives = lives;
    show_particles = false;

    //particle_spr = new Texture();
    //particle_spr = textureList[PARTICLE];
    for (int i = 0; i < 20; i++)
    {
        particles[i] = new Particles(0,0);
    }

    pause = false;
    resumeButton = new Button(308,436, "buttonResume.png");
    exitButton = new Button(518,436, "btn_exit.png");
    restartButton = new Button(413,436,"btn_start.png");
    musicOn = new Checkbox(413, 200, "on_off_button.png");
    if(Mix_PlayingMusic() == 0)
    {
        musicOn->check();
    }
    soundOn = new Checkbox(413, 230, "on_off_button.png");
    if(sound_on == false)
    {
        soundOn->check();
    }
    log("...");
}

void Level_1::load_files()
{

}

Level_1::~Level_1()
{
    BrickControl::delete_bricks();
    //SDL_FreeSurface(level_label);
    //SDL_FreeSurface(level_label_small);
    //SDL_FreeSurface(score_label);
    //font_small.release();
//    levelFont.release();
    for (int i = 0; i < 20; i++)
    {
        delete particles[i];
    }
    delete resumeButton;
    delete exitButton;
    delete restartButton;
    delete soundOn;
    delete musicOn;
    log("level_1 destructor");
}

void Level_1::render()
{
    bg = textureList[BG];
    bg->show(0,0);

    for(unsigned int i = 0; i < BrickControl::brickList.size(); i++)
    {
        BrickControl::brickList[i]->show();
    }

    for(unsigned int i = 0; i < Ball::ballList.size(); i++)
    {
        Ball::ballList[i]->show();
    }
    bita.show();

    if(begin == false)
    {
        glColor3f(0,0,0);
        fontLevel.beginDraw(SCREEN_WIDTH/2,SCREEN_HEIGHT/2) << "Level " << num_level << fontLevel.endDraw();
        glColor3f(1,1,1);
    }
    if(clear == true)
    {
        glColor3f(0,0,0);
        fontLevel.beginDraw(SCREEN_WIDTH/2,SCREEN_HEIGHT/2) << "Level " << num_level << " Clear" << fontLevel.endDraw();
        glColor3f(1,1,1);
    }
    if(Bonus::bonusList.size() > 0)
    {
        for(unsigned int i = 0; i < Bonus::bonusList.size(); i++)
        {
            Bonus::bonusList[i]->show();
        }
    }
    //SDL_Color textColor = {226,67,71};

//    if(lives > 3 || (lives == 0 && prevLives != lives))
//    {
//        prevLives = lives;
//        SDL_FreeSurface(life_label);
//        life_label= NULL;
//
//        heart_spr->show(10,10);
//        glColor3f(0,0,0);
//        font_small.beginDraw(heart_spr->w+10,5) << "x" << lives << font_small.endDraw();
//        glColor3f(1,1,1);
//    }
    switch(lives)
    {
    case 3:
        textureList[HEART]->show(10,10);
        textureList[HEART]->show(textureList[HEART]->w+10,10);
        textureList[HEART]->show(textureList[HEART]->w *2+10,10);
        break;
    case 2:
        textureList[HEART]->show(10,10);
        textureList[HEART]->show(textureList[HEART]->w+10,10);
        break;
    case 1:
        textureList[HEART]->show(10,10);
        break;
    case 0:
        textureList[HEART]->show(10,10);
        glColor3f(0,0,0);
        font_small.beginDraw(textureList[HEART]->w+10,5) << "x0" << font_small.endDraw();
        glColor3f(1,1,1);
        break;
    default:
        textureList[HEART]->show(10,10);
        glColor3f(0,0,0);
        font_small.beginDraw(textureList[HEART]->w+10,5) << "x" << lives << font_small.endDraw();
        glColor3f(1,1,1);
        break;
    }
    //std::stringstream ss;
    //ss << "Score: " + score;
    glColor3f(0,0,0);
    font_small.beginDraw(400,5) << "Score: " << score << font_small.endDraw();
    //font.small
    font_small.beginDraw(720,5) << "Level " << num_level << font_small.endDraw();
    glColor3f(1,1,1);

    //Particles-----------------------------------------------
    if(show_particles == true)
    {
        for(int p = 0; p < 20; p++)
        {
            particles[p]->show();
        }
    }
    //--------------------------------------------------------
    //SDL_Surface *pause_label = NULL;
    if(pause == true)
    {
        textureList[BG_HELP]->show(0,0);

        resumeButton->show();
        restartButton->show();
        exitButton->show();
        soundOn->show();
        musicOn->show();
    }
}

void Level_1::handle_events(SDL_Event &event)
{
    if(begin == true)
    {
        if(event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_p))
        {
            if(pause == false)
            {
                pause = true;
                SDL_WM_GrabInput(SDL_GRAB_OFF);
                SDL_ShowCursor(true);
            }
            else
            {
                SDL_WM_GrabInput(SDL_GRAB_ON);
                SDL_ShowCursor(false);
                pause = false;
            }
        }
        if(pause == false)
        {
            bita.handle_events(event);
            for(unsigned int i = 0; i < Ball::ballList.size(); i++)
            {
                Ball::ballList[i]->handle_events(event);
            }
        }
        else if(pause == true)
        {
            resumeButton->handle_events(event,resumeButton_click);
            restartButton->handle_events(event,restartButton_click);
            exitButton->handle_events(event, exitButton_click);
            if(soundOn->is_checked())
            {
                soundOn->handle_events(event,soundOn_checked_pause);
            }
            else
            {
                soundOn->handle_events(event,soundOn_notchecked_pause);
            }

            if(musicOn->is_checked())
            {
                musicOn->handle_events(event,musicOn_checked_pause);
            }
            else
            {
                musicOn->handle_events(event,musicOn_notchecked_pause);
            }
        }
    }
}


void Level_1::logic()
{
 if(begin == true)
 {
     if(pause == false)
     {
         int brickBeton_num = 0;
         for(unsigned int brc = 0; brc < BrickControl::brickList.size(); brc++)
         {
             BrickControl::brickList[brc]->get_type();
             if(BrickControl::brickList[brc]->get_type() == BRICK_BETON_T)
             {
                 brickBeton_num++;
             }
         }
            if(BrickControl::brickList.size()-brickBeton_num > 0)
            {
                for(unsigned int k = 0; k < Ball::ballList.size(); k++)
                {
                    Ball::ballList[k]->set_newFrame();
                    if(lives < 0)
                    {
                        timer.UnPause();
                        game_over = true;
                        for(unsigned int i = 0; i < BrickControl::brickList.size(); i++)
                        {
                            BrickControl::brickList.erase(BrickControl::brickList.begin()+i);
                        }
                    }
                     for(unsigned int i = 0; i < BrickControl::brickList.size(); i++)
                     {
                            collision_type = Ball::ballList[k]->collision_check(BrickControl::brickList[i]->get_rect());
                            if(collision_type > 0)
                            {
                                if(BrickControl::brickList[i]->get_type() != BRICK_BETON_T)
                                {
                                    if(BrickControl::brickList[i]->get_type() == STRONG_BRICK_T)
                                    {
                                        if(BrickControl::brickList[i]->get_life() > 0)
                                        {
                                            if(sound_on == true)
                                                Mix_PlayChannel(-1, soundList[1], 0);

                                            score += 10;
                                            BrickControl::brickList[i]->set_life(BrickControl::brickList[i]->get_life()-1);
                                            break;
                                        }
                                    }
                                            score += 50;
                                    //Particles--------------------------------------------
                                    if(sound_on == true)
                                        Mix_PlayChannel(-1, soundList[0], 0);

                                    for(unsigned int p = 0; p < 20; p++)
                                    {
                                        delete particles[p];
                                        particles[p] = new Particles(BrickControl::brickList[i]->get_rect().x,
                                                                     BrickControl::brickList[i]->get_rect().y);
                                    }
                                    show_particles = true;

                                    //-----------------------------------------------------

                                    if(bonus_created == false)
                                    {
                                        //srand((unsigned)time(NULL));
                                        int j = rand() % 20;
                                        //int j = 7;
                                        switch(j)
                                        {
                                        case 2:
                                            break;
                                        case 3:
                                            bonus = new Bonus(BrickControl::brickList[i]->get_center().x - textureList[SPEEDUP]->w/2,BrickControl::brickList[i]->get_rect().y, textureList[SPEEDUP], SPEED_UP_B);
                                            Bonus::bonusList.push_back(bonus);
                                            bonus_created = true;
                                            break;
                                        case 4:
                                            bonus = new Bonus(BrickControl::brickList[i]->get_center().x - textureList[SPEEDDOWN]->w/2,BrickControl::brickList[i]->get_rect().y, textureList[SPEEDDOWN], SPEED_DOWN_B);
                                            Bonus::bonusList.push_back(bonus);
                                            bonus_created = true;
                                            break;
                                        case 5:
                                            bonus = new Bonus(BrickControl::brickList[i]->get_center().x - textureList[LIFE]->w/2,BrickControl::brickList[i]->get_rect().y, textureList[LIFE], LIFE_B);
                                            Bonus::bonusList.push_back(bonus);
                                            bonus_created = true;
                                            break;
                                        case 6:
                                            bonus = new Bonus(BrickControl::brickList[i]->get_center().x - textureList[DIE]->w/2,BrickControl::brickList[i]->get_rect().y, textureList[DIE], DIE_B);
                                            Bonus::bonusList.push_back(bonus);
                                            bonus_created = true;
                                            break;
                                        case 7:
                                            bonus = new Bonus(BrickControl::brickList[i]->get_center().x - textureList[ADD]->w/2,BrickControl::brickList[i]->get_rect().y, textureList[ADD], ADD_BALL_B);
                                            Bonus::bonusList.push_back(bonus);
                                            bonus_created = true;
                                            break;
                                        }
                                    }
                                    BrickControl::brickList.erase(BrickControl::brickList.begin()+i);
                                    break;
                                }
                                else
                                {
                                    BrickControl::brickList[i]->set_collision_type(collision_type);
                                    if(sound_on == true)
                                        Mix_PlayChannel(-1, soundList[1], 0);
                                    break;
                                }
                            }
        //----------------------------------------------------------------
        //                    else
        //                    {
        //                        if(Ball::ballList.size() > 1)
        //                        {
        //                            for(unsigned int ball_num = 0; ball_num < Ball::ballList.size(); ball_num++)
        //                            {
        //                                collision_type = Ball::ballList[k]->collision_check(Ball::ballList[ball_num]->get_rect());
        //                            }
        //                        }
        //                    }
        //-------------------------------------------------------------------
                            bonus_created = false;
                     }
                   Ball::ballList[k]->move(bita.get_rect(),  collision_type, false);
                   if (Ball::ballList[k]->get_rect().y+Ball::ballList[k]->get_rect().h > SCREEN_HEIGHT)
                   {
                        if (Ball::ballList.size() > 1)
                        {
                            Ball::ballList.erase(Ball::ballList.begin() + k);
                        }
                        else
                        {
                            lives -= 1;
                            Ball::ballList[k]->reset(bita.get_rect().x + (bita.get_rect().w/2), bita.get_rect().y);
                        }
                   }
                }
                    bita.move();
                if(Bonus::bonusList.size() > 0)
                {
                    for(unsigned int i = 0; i < Bonus::bonusList.size(); i++)
                    {
                        Bonus::bonusList[i]->move();
                        if(check_collision(bita.get_rect(), Bonus::bonusList[i]->get_rect()))
                        {
                            score += 10;
                            if(sound_on == true)
                                Mix_PlayChannel(-1, snd_bonusget, 0);
                            switch(Bonus::bonusList[i]->get_type())
                            {
                            case SPEED_UP_B:
                                timer_speed_up.Start();
                                for(unsigned int i = 0; i < Ball::ballList.size(); i++)
                                {
                                    Ball::ballList[i]->set_speed(14);
                                }
                                break;
                      //for(unsigned int i = 0; i < Ball::ballList.size(); i++)          break;
                            case SPEED_DOWN_B:
                                timer_speed_down.Start();
                                for(unsigned int i = 0; i < Ball::ballList.size(); i++)
                                {
                                    Ball::ballList[i]->set_speed(6);
                                }
                                break;
                            case LIFE_B:
                                lives += 1;
                                break;
                            case DIE_B:
                                lives -= 1;
                                break;
                            case ADD_BALL_B:
                                ball = new Ball(bita.get_rect().x + bita.get_rect().w/2,(int)bita.get_rect().y);
                                Ball::ballList.push_back(ball);
                                break;
                            }
                            Bonus::bonusList.erase(Bonus::bonusList.begin()+i);

                            //Ball::ballList[i]->set_speed(10);
                        }
                        if(Bonus::bonusList[i]->get_rect().y > SCREEN_HEIGHT)
                        {
                            Bonus::bonusList.erase(Bonus::bonusList.begin()+i);

                            //Ball::ballList[i]->set_speed(6);
                        }
                    }
                }

            }
        else
        {
            if(game_over == true)
            {
                set_next_state(STATE_TITLE);
            }

            if(Ball::ballList.size() > 1)
            {
                for(unsigned int k = 1; k < Ball::ballList.size(); k++)
                {
                    Ball::ballList.erase(Ball::ballList.begin()+k);
                }
            }
            Ball::ballList[0]->reset(bita.get_rect().x + (bita.get_rect().w/2), bita.get_rect().y);

            if(Bonus::bonusList.size() > 0)
            {
                for(unsigned int a = 1; a < Ball::ballList.size(); a++)
                {
                    Bonus::bonusList.erase(Bonus::bonusList.begin()+a);
                }
            }
            if(BrickControl::brickList.size() > 0)
            {
                for(unsigned int brick_num = 0; brick_num < BrickControl::brickList.size(); brick_num++)
                {
                    BrickControl::brickList.erase(BrickControl::brickList.begin()+brick_num);
                }
            }

            clear = true;
            timer.UnPause();

            if(timer.Get_Ticks() >= 2000)
            {
                timer.Stop();
                clear = false;
                begin = false;


                set_next_state(num_level + 4);
            }
        }

        if(timer_speed_up.Is_Started() || timer_speed_down.Is_Started())
        {
            if(timer_speed_up.Get_Ticks() >= 10000)
            {
                timer_speed_up.Stop();
                for(unsigned int i = 0; i < Ball::ballList.size(); i++)
                {
                    Ball::ballList[i]->set_speed(10);
                }
            }
            if(timer_speed_down.Get_Ticks() >= 10000)
            {
                timer_speed_down.Stop();
                for(unsigned int i = 0; i < Ball::ballList.size(); i++)
                {
                    Ball::ballList[i]->set_speed(10);
                }
            }
        }
     }
     else if(pause == true)//PAUSE-----------------------
     {
        if(restarted == true)
        {
         if(Ball::ballList.size() > 1)
            {
                for(unsigned int k = 1; k < Ball::ballList.size(); k++)
                {
                    Ball::ballList.erase(Ball::ballList.begin()+k);
                }
            }
            Ball::ballList[0]->reset(bita.get_rect().x + (bita.get_rect().w/2), bita.get_rect().y);

            if(Bonus::bonusList.size() > 0)
            {
                for(unsigned int a = 1; a < Ball::ballList.size(); a++)
                {
                    Bonus::bonusList.erase(Bonus::bonusList.begin()+a);
                }
            }
            if(BrickControl::brickList.size() > 0)
            {
                for(unsigned int brick_num = 0; brick_num < BrickControl::brickList.size(); brick_num++)
                {
                    BrickControl::brickList.erase(BrickControl::brickList.begin()+brick_num);
                }
            }

            clear = true;
            timer.UnPause();

            if(timer.Get_Ticks() >= 2000)
            {
                timer.Stop();
                clear = false;
                begin = false;


                set_next_state(num_level + 3);
            }
        }
        SDL_Delay(60);
     }//-------------------------------------------------
    }
    else
    {
        if(timer.Get_Ticks() >= 1000)
        {
            begin = true;
            timer.Pause();
        }
    }
}
