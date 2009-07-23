//Game.cpp
#include "Game.h"
extern int stateID;
extern int nextState;
extern std::ofstream loger;
extern std::vector<Mix_Chunk*> soundList;
extern std::vector<SDL_Surface*> imageList;
extern SDL_Surface *screen;
extern Mix_Music *music;
Game::Game()
{
    currentState = NULL;
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
                currentState = new Title(font);
                break;

            case STATE_HELP:
                currentState = new Help();
                break;
            case STATE_LEVEL_1:
                currentState = new Level_1(font_level,1,"maps/level_1.map");
                break;
            case STATE_LEVEL_2:
                currentState = new Level_1(font_level,2,"maps/level_2.map");
                break;
            case STATE_LEVEL_3:
                currentState = new Level_1(font_level,3,"maps/level_3.map");
                break;
            case STATE_INTRO:
                currentState = new Title(font);
                break;
            case STATE_GAMEOVER:
                currentState = new Title(font);
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

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        return false;
    }

    if(TTF_Init() == -1)
    {
        log("TTF not init");
        return false;
    }

    return true;
}



bool Game::LoadFiles()
{
    //Load Images--------------------------------------------------------------
    SDL_Surface *brkbtn_spr = image_load("images/BetonBrick_n.png", 0xFF, 0, 0xFF);
    if(brkbtn_spr == NULL)
    {
        log("images/BetonBrick_n.png not loaded");
        return false;
    }
    imageList.push_back(brkbtn_spr);

    SDL_Surface *brkstr_spr = image_load("images/StrongBrick.png", 0xFF, 0, 0xFF);
    if(brkstr_spr == NULL)
    {
        log("images/StrongBrick.png not loaded");
        return false;
    }
    imageList.push_back(brkstr_spr);

    SDL_Surface *brk_spr = image_load("images/brick.png", 0xFF, 0, 0xFF);
    if(brk_spr == NULL)
    {
        log("images/brick.png not loaded");
        return false;
    }
    imageList.push_back(brk_spr);

    SDL_Surface *bg = image_load("images/bg.png");
    if(bg == NULL)
    {
        log("images/bg.png not loaded");
        return false;
    }
    imageList.push_back(bg);

    SDL_Surface *bita_sprite = image_load("images/bita.bmp", 0xFF, 0, 0xFF);
    if(bita_sprite == NULL)
    {
        log("images/bita.bmp not loaded");
        return false;
    }
    imageList.push_back(bita_sprite);

    SDL_Surface *ball_sprite = image_load("images/ball.bmp",0xFF, 0, 0xFF);
    if(ball_sprite == NULL)
    {
        log("images/ball.bmp not loaded");
        return false;
    }
    imageList.push_back(ball_sprite);

    SDL_Surface *bg_intro = image_load("images/bg_intro.png");
    if(bg_intro == NULL)
    {
        log("images/intro_bg not loaded");
        return false;
    }
    imageList.push_back(bg_intro);

    SDL_Surface *bg_title = image_load("images/bg_title.png");
    if(bg_title == NULL)
    {
        log("ERROR: bg_title.bmp not load");
        return false;
    }
    imageList.push_back(bg_title);

    SDL_Surface *bg_help = image_load("images/bg_Help.bmp");
    if(bg_help == NULL)
    {
        log("ERROR: bg_help.bmp not load");
        return false;
    }
    imageList.push_back(bg_help);

    SDL_Surface *bonus_speed_up_spr = image_load("images/bonus_speed_up.png",0xFF,0,0xFF);
    if(bonus_speed_up_spr == NULL)
    {
        log("ERROR: bonus_speed_up.png not load");
        return false;
    }
    imageList.push_back(bonus_speed_up_spr);

    SDL_Surface *bonus_speed_down_spr = image_load("images/bonus_speed_down.png", 0xFF, 0, 0xFF);
    if(bonus_speed_down_spr == NULL)
    {
        log("ERROR: bonus_speed_down.png not load");
        return false;
    }
    imageList.push_back(bonus_speed_down_spr);

    SDL_Surface *bonus_life_spr = image_load("images/bonus_life.png", 0xFF, 0, 0xFF);
    if(bonus_life_spr == NULL)
    {
        log("ERROR: bonus_life.png not load");
        return false;
    }
    imageList.push_back(bonus_life_spr);

    SDL_Surface *bonus_die_spr = image_load("images/bonus_die.png", 0xFF, 0, 0xFF);
    if(bonus_die_spr == NULL)
    {
        log("ERROR: bonus_die.png not load");
        stateID = STATE_EXIT;
    }
    imageList.push_back(bonus_die_spr);

    SDL_Surface *bonus_add_spr = image_load("images/bonus_add.png", 0xFF, 0, 0xFF);
    if(bonus_add_spr == NULL)
    {
        log("ERROR: bonus_add.png not load");
        return false;
    }
    imageList.push_back(bonus_add_spr);

    SDL_Surface *heart_sprite = image_load("images/heart.png", 0xFF, 0, 0xFF);
    if(heart_sprite == NULL)
    {
        log("images/heart.png not loaded");
        return false;
    }
    imageList.push_back(heart_sprite);

    SDL_Surface *particle_sprite = image_load("images/particle.png", 0xFF, 0, 0xFF);
    if(particle_sprite == NULL)
    {
        log("images/particle.png not loaded");
        return false;
    }
    imageList.push_back(particle_sprite);
    //-------------------------------------------------------
    //Load fonts --------------------------------------------
    font = TTF_OpenFont("fonts/aerial.ttf", 10);
    if(font == NULL)
    {
        log("fonts/aerial.ttf not loaded");
        return false;
    }

    font_level = TTF_OpenFont("fonts/aerial.ttf", 50);
    if(font == NULL)
    {
        log("fonts/aerial.ttf not loaded");
        return false;
    }
    //--------------------------------------------------------
    //Load sound-------------------------------------
    Mix_Chunk* sound = Mix_LoadWAV("sound/pow.ogg");
    if(sound == NULL)
    {
        log("hit.ogg not found");
        return false;
    }
    soundList.push_back(sound);

    sound = Mix_LoadWAV_RW(SDL_RWFromFile("sound/hit.ogg", "rb"), 1);
    if(sound == NULL)
    {
        log("hit.ogg not found");
        return false;
    }
    soundList.push_back(sound);

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

	music = Mix_LoadMUS("sound/music/intro.ogg");
    if(music == NULL)
    {
	  log("sound/music/intro.ogg not loaded");
	  return false;
	}
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
            if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q))
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
    loger.close();
    TTF_CloseFont(font);
    TTF_Quit();
    Mix_FreeChunk(hit);
    for(unsigned int i = 0; i < soundList.size(); i++)
    {
        Mix_FreeChunk(soundList[i]);
        //soundList.erase(soundList.begin() + i);
    }

    for(unsigned int i = 0; i < imageList.size(); i++)
    {
        SDL_FreeSurface(imageList[i]);
    }
    //imageList.erase(imageList.begin(),imageList.end());
	Mix_HaltMusic();
	Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}

