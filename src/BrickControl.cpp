//BrickControl.cpp
#include "BrickControl.h"
#include <sstream>
extern std::ofstream loger;
std::vector<Brick*> BrickControl::brickList;
//std::vector<BrickStrong> BrickControl::brickStrongList;

BrickControl::BrickControl()
{


}

BrickControl::~BrickControl()
{

}

bool BrickControl::LoadBricksFromFile(const char *filename, SDL_Surface* brk_spr, SDL_Surface *brkstr_spr, SDL_Surface* brkbtn_spr)
{
    FILE *FileHandle = fopen(filename, "r");
    if(FileHandle == NULL)
    {
        return false;
    }
    int brickCount = 0;
    int brickType = 0;
    fscanf(FileHandle, "%d\n", &brickCount);
    int X, Y;
    for (int i = 0; i < brickCount; i++)
    {
        Brick *brick;
        //BrickStrong tmpBrickStrong;

        fscanf(FileHandle, "%d %d %d\n", &brickType, &X, &Y);

        switch(brickType)
        {
        case BRICK:
            brick = new Brick();
            brick->set_up(X,Y, brk_spr);
            BrickControl::brickList.push_back(brick);
            //brick.clean_up();
            break;
        case STRONG_BRICK:
            brick = new BrickStrong();
            brick->set_up(X,Y, brkstr_spr);
            BrickControl::brickList.push_back(brick);
            break;
        case BRICK_BETON:
            brick = new BrickBeton();
            brick->set_up(X,Y, brkbtn_spr);
            BrickControl::brickList.push_back(brick);
        }
    }

    fclose(FileHandle);

    return true;

}
