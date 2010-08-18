#include "SDLUtils.h"
#include <sound.hpp>

std::vector<Texture*> textureList;

Mix_Chunk snd_bonusget, snd_hit, snd_pow;
AudioMusic *audio_music;

bool sound_on = true;

GLFT_Font font;
GLFT_Font fontLevel;
GLFT_Font font_small;

int stateID = STATE_NULL;
int nextState = STATE_NULL;
//Uint32 deltaTicks = 0;

int lives = 3;
int score = 0;
int hi_score = 0;

SDL_Surface *image_load(std::string filename)
{
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;

    loadedImage = IMG_Load(filename.c_str());
    if(loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    return optimizedImage;
}

SDL_Surface *image_load(std::string filename, int red, int green, int blue)
{

    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;

    loadedImage = IMG_Load(filename.c_str());

    if(loadedImage != NULL)
    {

        optimizedImage = SDL_DisplayFormat(loadedImage);

        SDL_FreeSurface(loadedImage);
    }


    if(optimizedImage != NULL)
    {
        Uint32 colorKey = SDL_MapRGB(optimizedImage->format, red, green, blue);
        SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorKey);
    }

    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, NULL, destination, &offset);
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, destination, &offset);
}

bool check_collision( SDL_Rect A, SDL_Rect B )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    if( bottomA < topB )
    {
        return false;
    }

    if( topA > bottomB )
    {
        return false;
    }

    if( rightA < leftB )
    {
        return false;
    }

    if( leftA > rightB )
    {
        return false;
    }

    return true;
}

void set_next_state( int newState )
{
    //If the user doesn't want to exit
    if( nextState != STATE_EXIT )
    {
        //Set the next state
        nextState = newState;
    }
}
double distance(int x1, int y1, int x2, int y2)
{
    //Return the distance between the two points
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool check_collision(Circle A, Circle B)
{
    //If the distance between the centers of the circles is less than the sum of their radii
    if(distance(A.x, A.y, B.x, B.y) < (A.r + B.r))
    {
        //The circles have collided
        return true;
    }

    //If not
    return false;
}

bool check_collision(Circle A, SDL_Rect B)
{
    //The sides of the shapes
    int leftAv, leftAh, leftB;
    int rightAv, rightAh, rightB;
    int topAv, topAh, topB;
    int bottomAv, bottomAh, bottomB;

    //The corners of box B
    int Bx1, By1;
    int Bx2, By2;
    int Bx3, By3;
    int Bx4, By4;

    //Calculate the sides of A
    leftAv = A.x;
    rightAv = A.x;
    topAv = A.y - A.r;
    bottomAv = A.y + A.r;

    leftAh = A.x - A.r;
    rightAh = A.x + A.r;
    topAh = A.y;
    bottomAh = A.y;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //Calculate the corners of B
    Bx1 = B.x, By1 = B.y;
    Bx2 = B.x + B.w, By2 = B.y;
    Bx3 = B.x, By3 = B.y + B.h;
    Bx4 = B.x + B.w, By4 = B.y + B.h;

    //If no sides from vertical A are outside of B
    if(((bottomAv <= topB) ||
        (topAv >= bottomB) ||
        (rightAv <= leftB) ||
        (leftAv >= rightB)) == false)
    {
        //A collision is detected
        return true;
    }

    //If no sides from horizontal A are outside of B
    if(((bottomAh <= topB) ||
        (topAh >= bottomB) ||
        (rightAh <= leftB) ||
        (leftAh >= rightB)) == false)
    {
        //A collision is detected
        return true;
    }

    //If any of the corners from B are inside A
    if((distance(A.x, A.y, Bx1, By1) < A.r) ||
       (distance(A.x, A.y, Bx2, By2) < A.r) ||
       (distance(A.x, A.y, Bx3, By3) < A.r) ||
       (distance(A.x, A.y, Bx4, By4) < A.r))
    {
        //A collision is detected
        return true;
    }

    //If the shapes have not collided
    return false;
}
