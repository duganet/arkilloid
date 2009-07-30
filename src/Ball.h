//Ball.h
#ifndef BALL_H
#define BALL_H

#include <SDL/SDL.h>
//#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <vector>
#include "SDLUtils.h"
#include "BrickControl.h"
#include "Texture.h"
extern std::vector<Texture*> textureList;

class Ball
{
public:
    static std::vector<Ball*> ballList;
    Ball(int X, int Y, bool move=true, Texture* texture= textureList[BALL]);
    ~Ball();
    void set_up(int, int, Texture*);
    void handle_events(SDL_Event& event);
    void move(SDL_Rect,   int collision_type, bool menu);
    void show();
    void reset(int x, int y);
    SDL_Rect get_rect();
    SDL_Rect get_newRect();
    void set_direction(int dir);
    bool collide;

    int collision_check(SDL_Rect brickRect);
    void set_newFrame();
    void set_speed(int speed);
    int get_speed();
    Circle get_circle();
private:
    SDL_Rect cbRect;
    SDL_Rect newFrame;
    Circle c;
    Circle newC;
    double xVel;
    double yVel;
    int speed;
    int prevSpeed;
    int direction;
    bool moving;
    Texture *texture;
};

#endif
