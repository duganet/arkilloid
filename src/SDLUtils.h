//SDLUtils.h
#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include "Constants.h"
#include "Globals.h"
#include "Texture.h"
#include <GLFT_Font.hpp>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>

struct Circle
{
    int x,y;  // center of the Circle
    int r;    // radius of the Circle
};

SDL_Surface *image_load(std::string filename);
SDL_Surface *image_load(std::string filename, int red, int green, int blue);
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip);
double distance(int x1, int y1, int x2, int y2);
bool check_collision(SDL_Rect A, SDL_Rect B);
bool check_collision(Circle A, SDL_Rect B);
bool check_collision(Circle A, Circle B);
void set_next_state( int newState );

struct Point
{
    int x;
    int y;
};

void log(std::string message);



enum GameStates
{
    STATE_NULL,
    STATE_INTRO,
    STATE_TITLE,
    STATE_HELP,
    STATE_LEVEL_1,
    STATE_LEVEL_2,
    STATE_LEVEL_3,
    STATE_GAMEOVER,
    STATE_EXIT
};

enum BrickType
{
    BRICK_T = 101,
    STRONG_BRICK_T,
    BRICK_BETON_T
};

enum collision_type
{
    NO_COLLISION,
    COLLISION_TOP,
    COLLISION_BOTTOM,
    COLLISION_LEFT,
    COLLISION_RIGHT,
    COLLISION_ANGLE,
    COLLISION_BOTTOM_NEED
};

enum images
{
    BRICK_BETON,
    BRICK_STRONG,
    BRICK,
    BITA,
    BALL,
    BG,
    BG_INTRO,
    BG_TITLE,
    BG_HELP,
    SPEEDUP,
    SPEEDDOWN,
    LIFE,
    DIE,
    ADD,
    HEART,
    PARTICLE
};

#endif
