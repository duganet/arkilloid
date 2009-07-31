//Game.cpp
#include "Game.h"
extern int stateID;
extern int nextState;
extern std::ofstream loger;
extern std::vector<Mix_Chunk*> soundList;
extern std::vector<Texture*>textureList;
extern Mix_Music *music;
extern GLFT_Font font;
extern GLFT_Font fontLevel;
extern GLFT_Font font_small;
Game::Game()
{
    currentState = NULL;
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
                currentState = new Title();
                break;

            case STATE_HELP:
                currentState = new Help();
                break;
            case STATE_LEVEL_1:
                currentState = new Level_1(1,"maps/level_1.map");
                break;
            case STATE_LEVEL_2:
                currentState = new Level_1(2,"maps/level_2.map");
                break;
            case STATE_LEVEL_3:
                currentState = new Level_1(3,"maps/level_3.map");
                break;
            case STATE_INTRO:
                currentState = new Title();
                break;
            case STATE_GAMEOVER:
                currentState = new Title();
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

bool Game::InitGL()
{
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
    glEnable( GL_TEXTURE_2D );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(glGetError() != GL_NO_ERROR)
    {
        log("ERROR: gl not init, " + glGetError());
        return false;
    }
    return true;
}

bool Game::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        log("ERROR: init failed");
        return false;
    }


    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
    {
        return false;
    }
    return true;
}


bool Game::LoadFiles()
{
    std::string fontsdir, imagedir, sounddir,musicdir,font_filename, img_filename, snd_filename, mus_filename;
    #ifdef WIN32
    imagedir = "images";
    fontsdir = "fonts/";
    sounddir = "sound/";
    musicdir = "sound/music/";
    #else
    /*imagedir = "../share/" + PACKAGE + "/images";
    fontsdir = "../share/" + PACKAGE + "/fonts";*/
    imagedir = "../share/arkilloid/images";
    fontsdir = "../share/arkilloid/fonts/";
    sounddir = "../share/arkilloid/sound/";
    musicdir = "../share/arkilloid/sound/music/";
    #endif

//Load Images------------------------------------------------
    img_filename = imagedir + "/BetonBrick_n.png";
    Texture *brickbtn_tex = new Texture;
    if(brickbtn_tex->load_from_file(img_filename) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(brickbtn_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/StrongBrick.png";
    Texture *brickstr_tex = new Texture;
    if(brickstr_tex->load_from_file(img_filename) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(brickstr_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/brick.png";
    Texture *brick_tex = new Texture;
    if(brick_tex->load_from_file(img_filename) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(brick_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bita.bmp";
    Texture *bita_tex = new Texture;
    if(bita_tex->load_from_file(img_filename, 0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(bita_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/ball.png";
    Texture *ball_tex = new Texture;
    if(ball_tex->load_from_file(img_filename, 0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(ball_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bg.png";
    Texture *bg_tex = new Texture;
    if(bg_tex->load_from_file(img_filename) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(bg_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bg_intro.png";
    Texture *bgintro_tex = new Texture;
    if(bgintro_tex->load_from_file(img_filename) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(bgintro_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bg_title.png";
    Texture *bgtitle_tex = new Texture;
    if(bgtitle_tex->load_from_file(img_filename) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(bgtitle_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bg_Help.bmp";
    Texture *bghelp_tex = new Texture;
    if(bghelp_tex->load_from_file(img_filename) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(bghelp_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bonus_speed_up.png";
    Texture *speedup_tex = new Texture;
    if(speedup_tex->load_from_file(img_filename, 0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(speedup_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bonus_speed_down.png";
    Texture *speeddown_tex = new Texture;
    if(speeddown_tex->load_from_file(img_filename, 0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(speeddown_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bonus_life.png";
    Texture *life_tex = new Texture;
    if(life_tex->load_from_file(img_filename,0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(life_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bonus_die.png";
    Texture *die_tex = new Texture;
    if(die_tex->load_from_file(img_filename,0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(die_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/bonus_add.png";
    Texture *add_tex = new Texture;
    if(add_tex->load_from_file(img_filename,0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(add_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/heart.png";
    Texture *heart_tex = new Texture;
    if(heart_tex->load_from_file(img_filename,0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(heart_tex);
//-----------------------------------------------------------
    img_filename = imagedir + "/particle.png";
    Texture *particle_tex = new Texture;
    if(particle_tex->load_from_file(img_filename,0xFF,0,0xFF) == false)
    {
        log("ERROR: " + img_filename + " not found");
        return false;
    }
    textureList.push_back(particle_tex);
//-----------------------------------------------------------

//Load fonts ------------------------------------------------
    font_filename = fontsdir + "/aerial.ttf";
//-----------------------------------------------------------
    font.open(font_filename, 10);
//-----------------------------------------------------------
    fontLevel.open(font_filename, 50);
//-----------------------------------------------------------
    font_small.open(font_filename, 20);
//-----------------------------------------------------------

//Load sound-------------------------------------------------
    snd_filename = sounddir + "pow.ogg";
    Mix_Chunk* sound = Mix_LoadWAV(snd_filename.c_str());
    if(sound == NULL)
    {
        log("ERROR: " + snd_filename + " not found");
        return false;
    }
    soundList.push_back(sound);
//-----------------------------------------------------------
    snd_filename = sounddir + "hit.ogg";
    sound = Mix_LoadWAV_RW(SDL_RWFromFile(snd_filename.c_str(), "rb"), 1);
    if(sound == NULL)
    {
        log("ERROR: " + snd_filename + " not found");
        return false;
    }
    soundList.push_back(sound);
//-----------------------------------------------------------
    snd_filename = sounddir + "intro.ogg";
    sound = Mix_LoadWAV_RW(SDL_RWFromFile(snd_filename.c_str(), "rb"), 1);
    if(sound == NULL)
    {
        log("ERROR: " + snd_filename + " not found");
        return false;
    }
    soundList.push_back(sound);
//-----------------------------------------------------------
    snd_filename = sounddir + "bonus_get.ogg";
    sound = Mix_LoadWAV_RW(SDL_RWFromFile(snd_filename.c_str(), "rb"), 1);
    if(sound == NULL)
    {
        log("ERROR: " + snd_filename + " not found");
        return false;
    }
    soundList.push_back(sound);
//-----------------------------------------------------------

//Load music-------------------------------------------------
	mus_filename = musicdir + "intro.ogg";
	music = Mix_LoadMUS(mus_filename.c_str());
    if(music == NULL)
    {
	  log("ERROR: " + mus_filename + " not found");
	  return false;
	}
//-----------------------------------------------------------

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
    if(InitGL() == false)
    {
        return false;
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
//        if(window.error() == true)
//        {
//            return 1;
//        }
        currentState->logic();
        fps.Start();
        //Change state if needed
        change_state();

        //Do state rendering
        glClear(GL_COLOR_BUFFER_BIT);
        currentState->render();

        SDL_GL_SwapBuffers();

        if(fps.Get_Ticks() < 1000/FRAMES_PER_SECOND)
        {
            SDL_Delay((1000/FRAMES_PER_SECOND) - fps.Get_Ticks());
        }
    }

    return true;
}

void Game::Close()
{
    loger.close();
    font.release();
    fontLevel.release();
    for(unsigned int i = 0; i < soundList.size(); i++)
    {
        Mix_FreeChunk(soundList[i]);
        //soundList.erase(soundList.begin() + i);
    }

    for(unsigned int i = 0; i < textureList.size(); i++)
    {
       textureList.erase(textureList.begin(), textureList.end());
    }

    //imageList.erase(imageList.begin(),imageList.end());
	Mix_HaltMusic();
	Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}

