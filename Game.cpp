//Game.cpp
#include "Game.h"
extern int stateID;
extern int nextState;
//extern Uint32 deltaTicks;
extern std::ofstream loger;
extern std::vector<Mix_Chunk*> soundList;
extern std::vector<SDL_Surface*> imageList;
extern SDL_Surface *screen;

Game::Game()
{
    currentState = NULL;
    bg = NULL;
    brk_spr = NULL;
    brkstr_spr = NULL;
    brkbtn_spr = NULL;
    bita_sprite = NULL;
    ball_sprite = NULL;
    bonus_speed_up_spr = NULL;
    bonus_speed_down_spr = NULL;
    bonus_life_spr = NULL;
    bonus_die_spr = NULL;
    bonus_add_spr = NULL;
    heart_sprite = NULL;
    particle_sprite = NULL;
    font = NULL;
    font_small = NULL;
    font_level = NULL;
    hit = NULL;
    sound = NULL;
}

Game::~Game()
{
    Close();
}

void Game::change_state()
{
    //If the state needs to be changed
    if( nextState != STATE_NULL )
    {
        //Delete the current state
        if( nextState != STATE_EXIT )
        {
            delete currentState;
        }

        //Change the state
        switch( nextState )
        {
            case STATE_TITLE:
                currentState = new Title(font, ball_sprite);
                break;

            case STATE_HELP:
                currentState = new Help();
                break;
            case STATE_LEVEL_1:
                currentState = new Level_1(//hit,
                                           bg,
                                           brk_spr,
                                           brkstr_spr,
                                           brkbtn_spr,
                                           bita_sprite,
                                           ball_sprite,
                                           bonus_speed_up_spr,
                                           bonus_speed_down_spr,
                                           bonus_life_spr,
                                           bonus_die_spr,
                                           bonus_add_spr,
                                           heart_sprite,
                                           particle_sprite,
                                           //soundList,
                                           font_level,
                                           1,
                                           "maps/level_1.map");
                break;

            case STATE_LEVEL_2:
                currentState = new Level_1(//hit,
                                           bg,
                                           brk_spr,
                                           brkstr_spr,
                                           brkbtn_spr,
                                           bita_sprite,
                                           ball_sprite,
                                           bonus_speed_up_spr,
                                           bonus_speed_down_spr,
                                           bonus_life_spr,
                                           bonus_die_spr,
                                           bonus_add_spr,
                                           heart_sprite,
                                           particle_sprite,
                                           //hit,
                                           //soundList,
                                           font_level,
                                           2,
                                           "maps/level_2.map");
                break;
            case STATE_LEVEL_3:
                currentState = new Level_1(//hit,
                                           bg,
                                           brk_spr,
                                           brkstr_spr,
                                           brkbtn_spr,
                                           bita_sprite,
                                           ball_sprite,
                                           bonus_speed_up_spr,
                                           bonus_speed_down_spr,
                                           bonus_life_spr,
                                           bonus_die_spr,
                                           bonus_add_spr,
                                           heart_sprite,
                                           particle_sprite,
                                           //hit,
                                           //soundList,
                                           font_level,
                                           3,
                                           "maps/level_3.map");
                break;
            case STATE_INTRO:
                currentState = new Title(font, ball_sprite);
                break;
            case STATE_GAMEOVER:
                currentState = new Title(font, ball_sprite);
                break;
        }

        //Change the current state ID
        stateID = nextState;

        //NULL the next state ID
        nextState = STATE_NULL;
    }
}

bool Game::Start()
{
    return true;
}

bool Game::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        log("ERROR: SDL not init");
        return false;
    }

//    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
//
//    if(screen == NULL)
//    {
//        log("ERROR: Video mode not set");
//        return false;
//    }

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        return false;
    }

    //SDL_WM_SetCaption("Arkilloid", NULL);

    if(TTF_Init() == -1)
    {
        log("TTF not init");
        return false;
    }

    //-------------------------------------------------------------

    //-------------------------------------------------------------
    return true;
}



bool Game::LoadFiles()
{
    brkbtn_spr = image_load("images/BetonBrick_n.png", 0xFF, 0, 0xFF);
    if(brkbtn_spr == NULL)
    {
        log("images/BetonBrick_n.png not loaded");
        return false;
    }

    brkstr_spr = image_load("images/StrongBrick.png", 0xFF, 0, 0xFF);
    if(brkstr_spr == NULL)
    {
        log("images/StrongBrick.png not loaded");
        return false;
    }
    brk_spr = image_load("images/brick.png", 0xFF, 0, 0xFF);
    if(brk_spr == NULL)
    {
        log("images/brick.png not loaded");
        return false;
    }

    bg = image_load("images/bg.bmp");
    if(bg == NULL)
    {
        log("images/bg.bmp not loaded");
        return false;
    }

    bita_sprite = image_load("images/bita.bmp", 0xFF, 0, 0xFF);
    if(bita_sprite == NULL)
    {
        log("images/bita.bmp not loaded");
        return false;
    }
    ball_sprite = image_load("images/ball.bmp",0xFF, 0, 0xFF);
    if(ball_sprite == NULL)
    {
        log("images/ball.bmp not loaded");
        return false;
    }
    bonus_speed_up_spr = image_load("images/bonus_speed_up.png",0xFF,0,0xFF);
    bonus_speed_down_spr = image_load("images/bonus_speed_down.png", 0xFF, 0, 0xFF);
    bonus_life_spr = image_load("images/bonus_life.png", 0xFF, 0, 0xFF);
    bonus_die_spr = image_load("images/bonus_die.png", 0xFF, 0, 0xFF);
    bonus_add_spr = image_load("images/bonus_add.png", 0xFF, 0, 0xFF);
    heart_sprite = image_load("images/heart.png", 0xFF, 0, 0xFF);
    if(!heart_sprite)
    {
        log("images/heart.png not loaded");
        return false;
    }
    particle_sprite = image_load("images/particle.png", 0xFF, 0, 0xFF);
    font = TTF_OpenFont("fonts/aerial.ttf", 10);
    //TTF_Font* font_small = TTF_OpenFont("fonts/aerial.ttf", 20);
    font_level = TTF_OpenFont("fonts/aerial.ttf", 50);

    //Load sound-------------------------------------
    Mix_Chunk* sound = Mix_LoadWAV_RW(SDL_RWFromFile("sound/pow.ogg", "rb"), 1);
    if(sound == NULL)
    {
        log("hit.ogg not found");
        return false;
    }
    soundList.push_back(sound);
    //Mix_FreeChunk(sound);
    sound = Mix_LoadWAV_RW(SDL_RWFromFile("sound/hit.ogg", "rb"), 1);
    if(sound == NULL)
    {
        log("hit.ogg not found");
        return false;
    }
    soundList.push_back(sound);
    //Mix_FreeChunk(sound);
    sound = Mix_LoadWAV_RW(SDL_RWFromFile("sound/intro.ogg", "rb"), 1);
    if(sound == NULL)
    {
        log("hit.ogg not found");
        return false;
    }
    soundList.push_back(sound);
    sound = Mix_LoadWAV_RW(SDL_RWFromFile("sound/bonus_get.ogg", "rb"), 1);
    if(sound == NULL)
    {
        log("hit.ogg not found");
        return false;
    }
    soundList.push_back(sound);
    //-----------------------------------------------

    return true;
}



bool Game::MainLoop()
{
    log("Initializing...");
    if(Init() == false)
    {
        log("ERROR: Init() = false");
        return false;
    }

    Window window;
    if(window.error() == true)
    {
        log("ERROR: error in window");
        return 1;
    }

    log("Loading files...");
    if(LoadFiles() == false)
    {
        log("ERROR: Some files failed to load :(");
        return false;
    }

    stateID = STATE_INTRO;

    //Set the current game state object
    currentState = new Intro();

    Timer fps;
    while(stateID != STATE_EXIT)
    {
        fps.Start();
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            {
                currentState->set_next_state( STATE_EXIT );
            }
            window.handle_events(event);
            currentState->handle_events(event);
        }
        //deltaTicks = fps.Get_Ticks();
        if(window.error() == true)
        {
            return 1;
        }
        currentState->logic();
        //fps.Start();
        //Change state if needed
        change_state();

        //Do state rendering
        currentState->render(screen);

        if(SDL_Flip(screen) == -1)
        {
            log("ERROR: SDL_Flip(screen) = -1");
            return false;
        }

        if(fps.Get_Ticks() < 1000/FRAMES_PER_SECOND)
        {
            SDL_Delay((1000/FRAMES_PER_SECOND) - fps.Get_Ticks());
        }
    }

    return true;
}

void Game::Close()
{
    SDL_FreeSurface(screen);
    SDL_FreeSurface(bg);
    SDL_FreeSurface(brkstr_spr);
    SDL_FreeSurface(brkbtn_spr);
    SDL_FreeSurface(brk_spr);
    SDL_FreeSurface(bonus_speed_up_spr);
    SDL_FreeSurface(bonus_speed_down_spr);
    SDL_FreeSurface(bonus_life_spr);
    SDL_FreeSurface(bonus_die_spr);
    SDL_FreeSurface(bonus_add_spr);
    SDL_FreeSurface(heart_sprite);
    loger.close();
    TTF_CloseFont(font);
    TTF_Quit();
    Mix_FreeChunk(hit);
    for(unsigned int i = 0; i < soundList.size(); i++)
    {
        soundList.erase(soundList.begin() + i);
    }
    Mix_CloseAudio();
    SDL_Quit();
}

