//Level_1.cpp
#include "Level_1.h"
#include "Constants.h"
#include "Globals.h"
#include <sstream>

extern int stateID;
extern int nextState;
extern int lives;
extern std::vector<Mix_Chunk*> soundList;
extern std::vector<SDL_Surface*> imageList;
extern Mix_Music *music;
extern int score;
extern int hi_score;
extern bool sound_on;
TTF_Font *levelFont;
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

Level_1::Level_1(TTF_Font* font, int num_level, std::string filename)
{
    restarted = false;
    levelFont = font;
    SDL_WM_GrabInput(SDL_GRAB_ON);
    this->num_level = num_level;
    SDL_Color textColor = {226,67,71};
    //back = bg;
    if(!BrickControl::LoadBricksFromFile(filename.c_str(), imageList[BRICK_SPR], imageList[BRICK_STRONG_SPR], imageList[BRICK_BETON_SPR]))
    {
        log("map not load");
    }
    bita.set_up(300, 570, imageList[BITA_SPR]);
    font_small = TTF_OpenFont("fonts/aerial.ttf", 20);
    ball_spr = imageList[BALL_SPR];
    if(Ball::ballList.size() <= 0)
    {
        ball = new Ball(bita.get_rect().x + (bita.get_rect().w/2), bita.get_rect().y, ball_spr, false);
        Ball::ballList.push_back(ball);
    }
    else
    {
        for(unsigned int check = 0; check < Ball::ballList.size(); check++)
        {
            Ball::ballList.erase(Ball::ballList.begin() + check);
        }
        ball = new Ball(bita.get_rect().x + (bita.get_rect().w/2), bita.get_rect().y, ball_spr, false);
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
    std::stringstream level_text;
    level_text << "Level " << num_level;
    level_label = TTF_RenderText_Solid(font, level_text.str().c_str(), textColor);
    level_label_small = TTF_RenderText_Solid(font_small, level_text.str().c_str(), textColor);
    level_text << " Clear";
    clear_label = TTF_RenderText_Solid(font, level_text.str().c_str(), textColor);
    begin = false;
    clear = false;
    bonus_created = false;
    timer.Start();
    bonus = NULL;
    heart_spr = imageList[HEART_SPR];
    game_over = false;
    life_label = NULL;
    prevScore = score;
    show_particles = false;
    std::stringstream score_text;
        score_text << "Score: " << score;
        //SDL_Color textColor = {0,0,0};

        score_label = TTF_RenderText_Solid(font_small, score_text.str().c_str(), textColor);

    //TTF_CloseFont(font_small);

    particle_spr = imageList[PARTICLE_SPR];

    for (int i = 0; i < 20; i++)
    {
        particles[i] = new Particles(0,0, particle_spr);
    }
    pause = false;
    resumeButton = new Button(308,436, "images/buttonResume.png");
    exitButton = new Button(518,436, "images/buttonExit.bmp");
    restartButton = new Button(413,436,"images/buttonStart.bmp");
    musicOn = new Checkbox(413, 200, "images/on_off_button.png");
    if(Mix_PlayingMusic() == 0)
    {
        musicOn->check();
    }
    soundOn = new Checkbox(413, 230, "images/on_off_button.png");
    if(sound_on == false)
    {
        soundOn->check();
    }
}

void Level_1::load_files()
{

}

Level_1::~Level_1()
{
    for(unsigned int i = 0; i < BrickControl::brickList.size(); i++)
    {
        BrickControl::brickList[i]->clean_up();
    }
    SDL_FreeSurface(level_label);
    SDL_FreeSurface(level_label_small);
    SDL_FreeSurface(score_label);
    TTF_CloseFont(font_small);
    for (int i = 0; i < 20; i++)
    {
        delete particles[i];
    }
    delete resumeButton;
    delete exitButton;
    delete restartButton;
    delete soundOn;
    delete musicOn;
}

void Level_1::render(SDL_Surface *screen)
{
    apply_surface(0,0,imageList[BG],screen);

    for(unsigned int i = 0; i < BrickControl::brickList.size(); i++)
    {
        BrickControl::brickList[i]->show(screen);
    }
    for(unsigned int i = 0; i < Ball::ballList.size(); i++)
    {
        Ball::ballList[i]->show(screen);
    }

    bita.show(screen);
    if(begin == false)
    {
        apply_surface(SCREEN_WIDTH/2 - level_label->w/2, SCREEN_HEIGHT/2 - level_label->h/2,level_label, screen);
    }
    if(clear == true)
    {
        apply_surface(SCREEN_WIDTH/2 - clear_label->w/2, SCREEN_HEIGHT/2 - clear_label->h/2,clear_label, screen);
    }
    if(Bonus::bonusList.size() > 0)
    {
        for(unsigned int i = 0; i < Bonus::bonusList.size(); i++)
        {
            Bonus::bonusList[i]->show(screen);
        }
    }
    SDL_Color textColor = {226,67,71};
    if(lives > 3 || lives == 0)
    {
        SDL_FreeSurface(life_label);
        life_label= NULL;
        std::stringstream life_text;
        life_text << "x" << lives;

        life_label = TTF_RenderText_Solid(font_small, life_text.str().c_str(), textColor);

        apply_surface(10,10,heart_spr, screen);
        apply_surface(10 + heart_spr->w,5, life_label, screen);
    }
    switch(lives)
    {
    case 3:
        apply_surface(10,10,heart_spr, screen);
        apply_surface(heart_spr->w+10,10,heart_spr,screen);
        apply_surface(heart_spr->w *2+10,10,heart_spr,screen);
        break;
    case 2:
        apply_surface(10,10,heart_spr, screen);
        apply_surface(10+heart_spr->w,10,heart_spr,screen);
        break;
    case 1:
        apply_surface(10,10,heart_spr, screen);
        break;
    case 0:
        break;
    }
    if(prevScore != score)
    {
        SDL_FreeSurface(score_label);
        score_label= NULL;
        std::stringstream score_text;
        score_text << "Score: " << score;
        //SDL_Color textColor = {121,121,121};
        prevScore = score;
        score_label = TTF_RenderText_Solid(font_small, score_text.str().c_str(), textColor);
    }
    apply_surface(520,5, level_label_small,screen);
    apply_surface(SCREEN_WIDTH/2 - score_label->w/2,5, score_label,screen);

    //Particles-----------------------------------------------
    if(show_particles == true)
    {
        for(int p = 0; p < 20; p++)
        {
            particles[p]->show(screen);
        }
    }
    //--------------------------------------------------------
    SDL_Surface *pause_label = NULL;
    if(pause == true)
    {
        apply_surface(0,0,imageList[BG_HELP],screen);
        SDL_Surface *pause_label = TTF_RenderText_Solid(levelFont, "Pause", textColor);
        apply_surface(SCREEN_WIDTH/2 - pause_label->w/2, SCREEN_HEIGHT/2 - pause_label->h/2,pause_label, screen);
        resumeButton->show(screen);
        restartButton->show(screen);
        exitButton->show(screen);
        soundOn->show(screen);
        musicOn->show(screen);
    }
    else
    SDL_FreeSurface(pause_label);
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
             if(BrickControl::brickList[brc]->get_type() == BRICK_BETON)
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
                        if(BrickControl::brickList[i]->get_type() != BRICK_BETON)
                        {
                            if(BrickControl::brickList[i]->get_type() == STRONG_BRICK)
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
                                                             BrickControl::brickList[i]->get_rect().y,
                                                             particle_spr);
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
                                    bonus = new Bonus(BrickControl::brickList[i]->get_center().x - imageList[BONUS_SPEEDUP_SPR]->w/2,BrickControl::brickList[i]->get_rect().y, imageList[BONUS_SPEEDUP_SPR], SPEED_UP);
                                    Bonus::bonusList.push_back(bonus);
                                    bonus_created = true;
                                    break;
                                case 4:
                                    bonus = new Bonus(BrickControl::brickList[i]->get_center().x - imageList[BONUS_SPEEDDOWN_SPR]->w/2,BrickControl::brickList[i]->get_rect().y, imageList[BONUS_SPEEDDOWN_SPR], SPEED_DOWN);
                                    Bonus::bonusList.push_back(bonus);
                                    bonus_created = true;
                                    break;
                                case 5:
                                    bonus = new Bonus(BrickControl::brickList[i]->get_center().x - imageList[BONUS_LIFE_SPR]->w/2,BrickControl::brickList[i]->get_rect().y, imageList[BONUS_LIFE_SPR], LIFE);
                                    Bonus::bonusList.push_back(bonus);
                                    bonus_created = true;
                                    break;
                                case 6:
                                    bonus = new Bonus(BrickControl::brickList[i]->get_center().x - imageList[BONUS_DIE_SPR]->w/2,BrickControl::brickList[i]->get_rect().y, imageList[BONUS_DIE_SPR], DIE);
                                    Bonus::bonusList.push_back(bonus);
                                    bonus_created = true;
                                    break;
                                case 7:
                                    bonus = new Bonus(BrickControl::brickList[i]->get_center().x - imageList[BONUS_ADD_SPR]->w/2,BrickControl::brickList[i]->get_rect().y, imageList[BONUS_ADD_SPR], ADD_BALL);
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
                        Mix_PlayChannel(-1, soundList[3], 0);
                    switch(Bonus::bonusList[i]->get_type())
                    {
                    case SPEED_UP:
                        timer_speed_up.Start();
                        for(unsigned int i = 0; i < Ball::ballList.size(); i++)
                        {
                            Ball::ballList[i]->set_speed(16);
                        }
                        break;
              //for(unsigned int i = 0; i < Ball::ballList.size(); i++)          break;
                    case SPEED_DOWN:
                        timer_speed_down.Start();
                        for(unsigned int i = 0; i < Ball::ballList.size(); i++)
                        {
                            Ball::ballList[i]->set_speed(8);
                        }
                        break;
                    case LIFE:
                        lives += 1;
                        break;
                    case DIE:
                        lives -= 1;
                        break;
                    case ADD_BALL:
                        ball = new Ball(bita.get_rect().x + bita.get_rect().w/2,bita.get_rect().y, ball_spr, true);
                        Ball::ballList.push_back(ball);
                        break;
                    }
                    Bonus::bonusList.erase(Bonus::bonusList.begin()+i);
                }
                if(Bonus::bonusList[i]->get_rect().y > SCREEN_HEIGHT)
                {
                    Bonus::bonusList.erase(Bonus::bonusList.begin()+i);
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
                    Ball::ballList[i]->set_speed(12);
                }
            }
            if(timer_speed_down.Get_Ticks() >= 10000)
            {
                timer_speed_down.Stop();
                for(unsigned int i = 0; i < Ball::ballList.size(); i++)
                {
                    Ball::ballList[i]->set_speed(12);
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
