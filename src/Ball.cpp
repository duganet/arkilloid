//Ball.cpp
#include "Ball.h"
#include "SDLUtils.h"
#include "Constants.h"
#include <cmath>
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <cstdlib>
#include <map>
#include <cmath>
#include <report.hpp>

//extern Uint32 deltaTicks;


const double PI = 3.14159265;

std::vector<Ball*> Ball::ballList;

void rotate(double &xVel,double &yVel, int speed, int direction)
{
    double xx = xVel*cos(direction*(PI/180)) - yVel*sin(direction*(PI/180));
    yVel = yVel*cos(direction*(PI/180)) + xVel*sin(direction*(PI/180));
    xVel = xx;
}


Ball::Ball(int X, int Y, bool move, Texture* texture)
{
    this->texture = new Texture();
    this->texture = texture;

    cbRect.w = this->texture->w;
    cbRect.h = this->texture->h;
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
	report("ball create", MSG_DEBUG);
}

void Ball::set_up(int X, int Y, Texture* texture = textureList[BALL])
{
    this->texture = texture;
    cbRect.w = this->texture->w;
    cbRect.h = this->texture->h;
    reset(X, Y);
}

Ball::~Ball()
{
    cbRect.x = 0;
    cbRect.y = 0;
}

void Ball::set_direction(int dir)
{
    xVel = 1;
    yVel = 0;
    direction = dir;
    speed = 10;
    prevSpeed = 10;
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



//int Ball::collision_check(SDL_Rect brickRect)
//{
//    if(check_collision(brickRect, cbRect) == true)
//    {
//        collide = true;
//        set_speed(0);
//        int top    = brickRect.y;
//        int bottom = brickRect.y + brickRect.h;
//        int left   = brickRect.x;
//        int right  = brickRect.x + brickRect.w;
//
//        if((cbRect.x) < left)
//        {
//            xVel = -xVel;
//            set_speed(prevSpeed);
//            collide = true;
//            return COLLISION_LEFT;
//        }
//
//        if((cbRect.y + cbRect.h) > top)
//        {
//            yVel = -yVel;
//            set_speed(prevSpeed);
//            return COLLISION_BOTTOM;
//        }
//        if((cbRect.x + cbRect.w) > right)
//        {
//            xVel = -xVel;
//            set_speed(prevSpeed);
//            return COLLISION_RIGHT;
//        }
//        if((cbRect.y) < bottom)
//        {
//            yVel = -yVel;
//            set_speed(prevSpeed);
//            return COLLISION_TOP;
//        }
//        if(cbRect.x < left && (cbRect.y + cbRect.h) > top)
//        {
//            yVel = xVel;
//            set_speed(prevSpeed);
//            return COLLISION_LEFT;
//        }
//        if(cbRect.x < left && cbRect.y < bottom)
//        {
//            yVel = xVel;
//            set_speed(prevSpeed);
//            return COLLISION_LEFT;
//        }
//        if((cbRect.x+cbRect.w)>right && cbRect.y < bottom)
//        {
//            xVel = yVel;
//            set_speed(prevSpeed);
//            return COLLISION_RIGHT;
//        }
//        if((cbRect.x+cbRect.w)>right && (cbRect.y+cbRect.h) > top)
//        {
//            xVel = yVel;
//            set_speed(prevSpeed);
//            return COLLISION_RIGHT;
//        }
//    }
//    cbRect = newFrame;
//    collide = false;
//    set_speed(prevSpeed);
//    return NO_COLLISION;
//}

bool brick_there(int x, int y)
{
    for(unsigned int i = 0; i < BrickControl::brickList.size(); i++)
    {
        if((x >=BrickControl::brickList[i]->get_rect().x&&
           x <=BrickControl::brickList[i]->get_rect().x+BrickControl::brickList[i]->get_rect().w)&&
           (y >=BrickControl::brickList[i]->get_rect().y&&
           y <=BrickControl::brickList[i]->get_rect().y+BrickControl::brickList[i]->get_rect().h))
        {
            return true;
        }
    }
    return false;
}

int Ball::collision_check(SDL_Rect brickRect)
{
    if(check_collision(brickRect, cbRect)==true)
    {
        SDL_Rect top;
        SDL_Rect bottom;
        SDL_Rect left;
        SDL_Rect right;

        top.x = brickRect.x;
        top.y = brickRect.y;
        top.w = brickRect.w;
        top.h = 0;

        bottom.x = brickRect.x;
        bottom.y = brickRect.y+brickRect.h;
        bottom.w = brickRect.w;
        bottom.h = 0;

        left.x = brickRect.x;
        left.y = brickRect.y;
        left.w = 0;
        left.h = brickRect.h;

        right.x = brickRect.x + brickRect.w;
        right.y = brickRect.y;
        right.w = 0;
        right.h = brickRect.h;

        if((check_collision(left, cbRect) && check_collision(top, cbRect))&&brick_there(left.x-5,left.y)==false)
        {
            xVel = 1;
            yVel = 0;
            rotate(xVel, yVel, speed, 227);
            return COLLISION_TOP;
        }
        if((check_collision(left, cbRect) && check_collision(bottom, cbRect))&&brick_there(left.x-5,left.y)==false)
        {
            xVel = 1;
            yVel = 0;
            rotate(xVel, yVel, speed, 137);
            return COLLISION_BOTTOM;
        }
        if((check_collision(right, cbRect) && check_collision(top, cbRect))&&brick_there(right.x+5,right.y)==false)
        {
            xVel = 1;
            yVel = 0;
            rotate(xVel, yVel, speed, 317);
            return COLLISION_TOP;
        }
        if((check_collision(right, cbRect) && check_collision(bottom, cbRect))&&brick_there(right.x+5,right.y)==false)
        {
            xVel = 1;
            yVel = 0;
            rotate(xVel, yVel, speed, 47);
            return COLLISION_BOTTOM;
        }

        if(check_collision(top, cbRect))
        {
            yVel = -yVel;
            return COLLISION_TOP;
        }
        if(check_collision(bottom, cbRect))
        {
            yVel = -yVel;
            return COLLISION_BOTTOM;
        }
        if(check_collision(left, cbRect))
        {
            xVel = -xVel;
            return COLLISION_LEFT;
        }
        if(check_collision(right, cbRect))
        {
            xVel = -xVel;
            return COLLISION_RIGHT;
        }
    }
    return NO_COLLISION;
}

void Ball::move(SDL_Rect bitaRect, int collision_type, bool menu)
{
    if(moving == true)
    {
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

        if(cbRect.y < 50)
        {
            //Mix_PlayChannel(-1, chunk, 0);
            cbRect.y = 50;
            //normalize();
            yVel = -yVel;
        }

        if(cbRect.y + cbRect.h >= SCREEN_HEIGHT && collision_type == COLLISION_BOTTOM_NEED)
        {
            yVel = -yVel;
        }

        if(check_collision(bitaRect ,cbRect) == 1 && collision_type != COLLISION_BOTTOM_NEED)
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

void Ball::show()
{
    //textureList[BALL]->show((int)cbRect.x, (int)cbRect.y);
    texture->show((int)cbRect.x, (int)cbRect.y);
}

void Ball::reset(int x, int y)
{
    speed = 10;
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
    prevSpeed = speed;
    this->speed = speed;
}

int Ball::get_speed()
{
    return speed;
}
