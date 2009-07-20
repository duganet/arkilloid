//Ball.cpp
#include "Ball.h"
#include "SDLUtils.h"
#include "Constants.h"
#include <cmath>
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <cstdlib>
#include <cmath>

//extern Uint32 deltaTicks;

const double PI = 3.14159265;

std::vector<Ball*> Ball::ballList;

void rotate(double &xVel,double &yVel, int speed, int direction)
{
    double xx = xVel*cos(direction*(PI/180)) - yVel*sin(direction*(PI/180));
    yVel = yVel*cos(direction*(PI/180)) + xVel*sin(direction*(PI/180));
    xVel = xx;
}


Ball::Ball(int X, int Y, SDL_Surface* SPRITE, bool move)
{
    sprite = SPRITE;
    cbRect.w = this->sprite->w;
    cbRect.h = this->sprite->h;
    reset(X, Y);
    moving = move;
    if(moving == true)
    {
        srand((unsigned)time(0));
		direction = (rand()%90) + 225;
        if(direction < 225)
            direction = 225;
        if(direction > 315)
            direction = 315;
        set_direction(direction);
    }
}

void Ball::set_up(int X, int Y, SDL_Surface* SPRITE)
{
    sprite = SPRITE;
    cbRect.w = this->sprite->w;
    cbRect.h = this->sprite->h;
    reset(X, Y);
}

Ball::~Ball()
{
    //SDL_FreeSurface(this->sprite);
    cbRect.x = 0;
    cbRect.y = 0;
}

void Ball::set_direction(int dir)
{
    xVel = 1;
    yVel = 0;
    direction = dir;
    speed = 6;
    rotate(xVel, yVel, speed, direction);
}

void Ball::handle_events(SDL_Event &event)
{
    if(moving == false)
    {
        if(event.type == SDL_MOUSEMOTION)
        {
            cbRect.x = event.motion.x - cbRect.w/2;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                srand((unsigned)time(0));
                //set_direction((rand()%360) + 270);

                direction = (rand()%360) + 270;
                if(direction < 225)
                    direction = 225;
                if(direction > 315)
                    direction = 315;
                xVel = 1;
                yVel = 0;

                rotate(xVel, yVel, speed, direction);

                moving = true;
            }
        }
    }
}

void Ball::normalize()
{
    int velocity = sqrt(xVel*xVel + yVel*yVel);
    xVel = xVel/velocity*2;
    yVel = yVel/velocity*2;
}

int Ball::collision_check(SDL_Rect brickRect)
{
    if(check_collision(brickRect, cbRect))
    {
        //collide = true;
        int top    = brickRect.y;
        int bottom = brickRect.y + brickRect.h;
        int left   = brickRect.x;
        int right  = brickRect.x + brickRect.w;

        if((cbRect.x) < left)
        {
            xVel = -xVel;
//            collide = true;
            return COLLISION_LEFT;
        }

        if((cbRect.y + cbRect.h) > top)
        {
            yVel = -yVel;
//            collide = true;
            return COLLISION_BOTTOM;
        }
        if((cbRect.x + cbRect.w) > right)
        {
            xVel = -xVel;
//            collide = true;
            return COLLISION_RIGHT;
        }
        if((cbRect.y) < bottom)
        {
            yVel = -yVel;
//            collide = true;
            return COLLISION_TOP;
        }
    }
    //cbRect = newFrame;
    collide = false;
    return NO_COLLISION;
}

//int Ball::collision_check(SDL_Rect brickRect)
//{
//    if(check_collision(brickRect, newFrame))
//    {
//        int leftA, leftB;
//        int rightA, rightB;
//        int topA, topB;
//        int bottomA, bottomB;
//
//        leftA = brickRect.x;
//        rightA = brickRect.x + brickRect.w;
//        topA = brickRect.y;
//        bottomA = brickRect.y + brickRect.h;
//
//
//        leftB = newFrame.x;
//        rightB = newFrame.x + newFrame.w;
//        topB = newFrame.y;
//        bottomB = newFrame.y + newFrame.h;
//
//        if( bottomA < topB == false)
//        {
//            return COLLISION_BOTTOM;
//        }
//
//        else if( topA > bottomB == false)
//        {
//            return COLLISION_TOP;
//        }
//
//        else if( rightA < leftB == false)
//        {
//            return COLLISION_RIGHT;
//        }
//
//        else if( leftA > rightB == false)
//        {
//            return COLLISION_LEFT;
//        }
//    }
//    else
//    {
//        return NO_COLLISION;
//    }
//}

void Ball::move(SDL_Rect bitaRect, int collision_type, bool menu)
{
    if(moving == true)
    {
//        if(menu == true)
//        {
//            cbRect.x += (int)(xVel * speed);
//            cbRect.y += (int)(yVel * speed);
//        }
//------------------------------------------------------------------------
//       if(collide == true)
//       {
//        if(collision_type == COLLISION_TOP || collision_type == COLLISION_BOTTOM)
//        {
//            //normalize();
//            collide =false;
//            yVel = -yVel;
//        }
//        else if(collision_type == COLLISION_LEFT || collision_type == COLLISION_RIGHT)
//        {
//            collide =false;
//            xVel = -xVel;
//
//        }
//       }
//        if(collision_type == COLLISION_ANGLE)
//        {
//            if(xVel < 0)
//            {
//                xVel = -xVel;
//            }
//            else
//            yVel = -yVel;
//        }

//        if(collision_type == NO_COLLISION)
//        {
//            //normalize();
//            cbRect = newFrame;
//        }
        //cbRect = newFrame;
        if(cbRect.x < 0)
        {
            //Mix_PlayChannel(-1, chunk, 0);
            cbRect.x = 0;
            //normalize();
            xVel = -xVel;
        }

        if(cbRect.x + cbRect.w >= SCREEN_WIDTH)
        {
            //Mix_PlayChannel(-1, chunk, 0);
            cbRect.x = SCREEN_WIDTH - cbRect.w;
            //normalize();
            xVel = -xVel;
        }



        //if(menu == false)
        {
            if(cbRect.y < 31)
            {
                //Mix_PlayChannel(-1, chunk, 0);
                cbRect.y = 31;
                //normalize();
                yVel = -yVel;
            }

        }
//        else if(menu == true)
//        {
//            if(cbRect.y < 0)
//            {
//                yVel =-yVel;
//            }
//        }

        if(cbRect.y + cbRect.h >= SCREEN_HEIGHT && collision_type == COLLISION_BOTTOM_NEED)
        {
            //normalize();
            yVel = -yVel;
        }

        if(check_collision(bitaRect ,cbRect) == 1)
        {
            direction = ((cbRect.x + cbRect.w/2) - (bitaRect.x + bitaRect.w/2)) + 270;
            if(direction < 225)
                direction = 225;
            if(direction > 315)
                direction = 315;
            xVel = 1;
            yVel = 0;
            rotate(xVel, yVel, speed, direction);
        }

        cbRect.x += (int)(xVel * speed);
        cbRect.y += (int)(yVel * speed);
    }
    else if(moving == false)
    {

        //cbRect.x = bitaRect.x + bitaRect.w/2 - cbRect.w/2;
        //cbRect.y = bitaRect.h;
        if ((cbRect.x+cbRect.w/2) < bitaRect.w/2)
        {
            cbRect.x = bitaRect.w/2 - cbRect.w/2;
        }
        if ((cbRect.x+cbRect.w/2) > SCREEN_WIDTH - bitaRect.w/2)
        {
            cbRect.x = SCREEN_WIDTH - bitaRect.w/2 - cbRect.w/2;
        }
    }
}

void Ball::show(SDL_Surface *screen)
{
    apply_surface((int)cbRect.x, (int)cbRect.y, sprite, screen);
}

void Ball::reset(int x, int y)
{
    speed = 6;
    cbRect.x = x - cbRect.w/2;
    cbRect.y = y - cbRect.h;
    moving = false;
    collide = false;
}

SDL_Rect Ball::get_rect()
{
    return cbRect;
}

SDL_Rect Ball::get_newRect()
{
    return newFrame;
}

void Ball::set_newFrame()
{
    newFrame = cbRect;
    newFrame.x += (int)(xVel*speed);
    newFrame.y += (int)(yVel*speed);
}

void Ball::set_speed(int speed)
{
    this->speed = speed;
}

int Ball::get_speed()
{
    return speed;
}
