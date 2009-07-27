//SDLUtils.h
#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <fstream>
#include "Globals.h"
#include "Constants.h"
#include <vector>
#include <map>
#include <cmath>
//#include <windows.h>

/*
[A][  B  ][C]
[D][BLOCK][F]
[G][  H  ][i]
*/
//const int NO_COLLISION = 0;
const int ZONE_A = 1;
const int ZONE_B = 2;
const int ZONE_C = 3;
const int ZONE_D = 4;
const int ZONE_E = 5;
const int ZONE_F = 6;
const int ZONE_G = 7;
const int ZONE_H = 8;
const int ZONE_I = 9;

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
int finde_zone(SDL_Rect A, SDL_Rect B);
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
    BRICK = 101,
    STRONG_BRICK,
    BRICK_BETON
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
    BRICK_BETON_SPR,
    BRICK_STRONG_SPR,
    BRICK_SPR,
    BG,
    BITA_SPR,
    BALL_SPR,
    BG_INTRO,
    BG_TITLE,
    BG_HELP,
    BONUS_SPEEDUP_SPR,
    BONUS_SPEEDDOWN_SPR,
    BONUS_LIFE_SPR,
    BONUS_DIE_SPR,
    BONUS_ADD_SPR,
    HEART_SPR,
    PARTICLE_SPR
};
#endif
