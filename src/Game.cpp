//Game.cpp
#include "Game.h"
#include <sound.hpp>
#include <report.hpp>
#include <Load.h>

extern int stateID;
extern int nextState;
extern std::vector<Texture*>textureList;
extern AudioEngine *audio;
extern AudioSoundFX *snd_bonusget, *snd_hit, *snd_pow;
extern AudioMusic *audio_music;
extern GLFT_Font font;
extern GLFT_Font fontLevel;
extern GLFT_Font font_small;
Game::Game()
{
    currentState = NULL;
}

Game::~Game()
{
	report("Game destructor", MSG_DEBUG);
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
                currentState = new Level_1(1,"level_1.map");
                break;
            case STATE_LEVEL_2:
                currentState = new Level_1(2,"level_2.map");
                break;
            case STATE_LEVEL_3:
                currentState = new Level_1(3,"level_3.map");
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
        report("gl not init, " + glGetError(), MSG_ERROR);
        return false;
    }
    return true;
}

bool Game::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        report("init failed", MSG_ERROR);
        return false;
    }

	::AudioEngine::Start();
    return true;
}


bool Game::LoadFiles()
{
    std::string filename, mus_basedir;

    mus_basedir = "sounds/music";

/* Load bricks */
	report("Loading bricks...", MSG_DEBUG);
	LoadBrick("brick_beton.png");
	LoadBrick("brick_strong.png");
	LoadBrick("brick_portal_a.png");
	LoadBrick("brick_portal_b.png");
	LoadBrick("brick.png");
	report("Finished loading bricks.", MSG_DEBUG);

/* Load other textures */
	report("Loading other textures...", MSG_DEBUG);
	LoadTexture("bita.bmp");
	LoadTexture("ball.png");
	LoadTexture("bg.png");
	LoadTexture("bg_intro.png");
	LoadTexture("bg_title.png");
	LoadTexture("bg_Help.png");
	LoadTexture("bonus_speed_up.png");
	LoadTexture("bonus_speed_down.png");
	LoadTexture("bonus_life.png");
	LoadTexture("bonus_die.png");
	LoadTexture("bonus_add.png");
	LoadTexture("heart.png");
	LoadTexture("particle.png");
	report("Finished loading other textures", MSG_DEBUG);

//Load fonts ------------------------------------------------
    filename = path_construct("fonts", "aerial.ttf");
//-----------------------------------------------------------
    font.open(filename, 10);
//-----------------------------------------------------------
    fontLevel.open(filename, 50);
//-----------------------------------------------------------
    font_small.open(filename, 20);
//-----------------------------------------------------------

//Load sound-------------------------------------------------
	snd_bonusget = new AudioSoundFX("bonus_get.ogg");
	snd_hit = new AudioSoundFX("hit.ogg");
	snd_pow = new AudioSoundFX("pow.ogg");
//-----------------------------------------------------------

//Load music-------------------------------------------------
	audio_music = new AudioMusic();
//-----------------------------------------------------------

    return true;
}



bool Game::MainLoop()
{
	report("This is DEBUG build! It will log some debug info. If this is not what you want please recompile without -DDEBUG definition.", MSG_DEBUG);
	report("Initializing...", MSG_DEBUG);
    if(Init() == false)
    {
        report("Init() = false", MSG_ERROR);
        return false;
    }

    Window window;

    if(window.error() == true)
    {
        report("error in window", MSG_ERROR);
        return 1;
    }
    if(InitGL() == false)
    {
        return false;
    }
	report("Loading files...", MSG_DEBUG);
    if(LoadFiles() == false)
    {
        report("Some files failed to load :(", MSG_ERROR);
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

		audio_music->CheckPlay();

        if(fps.Get_Ticks() < 1000/FRAMES_PER_SECOND)
        {
            SDL_Delay((1000/FRAMES_PER_SECOND) - fps.Get_Ticks());
        }
    }

    return true;
}

void Game::Close()
{
	report("Game::Close()", MSG_DEBUG);
    logfile.close();
    font.release();
    fontLevel.release();

    for(unsigned int i = 0; i < textureList.size(); i++)
    {
       textureList.erase(textureList.begin(), textureList.end());
    }

    //imageList.erase(imageList.begin(),imageList.end());
	Mix_HaltMusic();
	delete audio_music;
    ::AudioEngine::Stop();
    SDL_Quit();
}

