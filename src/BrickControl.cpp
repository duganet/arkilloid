//BrickControl.cpp
#include "BrickControl.h"
#include <sstream>
#include <report.hpp>
extern std::ofstream loger;
std::vector<Brick*> BrickControl::brickList;

BrickControl::BrickControl()
{


}

BrickControl::~BrickControl()
{

}

bool BrickControl::LoadBricksFromFile(const char *filename)
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

        fscanf(FileHandle, "%d %d %d\n", &brickType, &X, &Y);

        switch(brickType)
        {
        case BRICK_T:
            brick = new Brick();
            brick->set_up(X,Y);
            BrickControl::brickList.push_back(brick);
            //brick.clean_up();
            break;
        case STRONG_BRICK_T:
            brick = new BrickStrong();
            brick->set_up(X,Y);
            BrickControl::brickList.push_back(brick);
            break;
        case BRICK_BETON_T:
            brick = new BrickBeton();
            brick->set_up(X,Y);
            BrickControl::brickList.push_back(brick);
            break;
        case BRICK_PORTAL_A_T:
			brick = new BrickPortalA();
			brick->set_up(X,Y);
			BrickControl::brickList.push_back(brick);
			BrickControl::portalaList.push_back(brick);
			break;
        case BRICK_PORTAL_B_T:
			brick = new BrickPortalB();
			brick->set_up(X,Y);
			BrickControl::brickList.push_back(brick);
			break;
		}
    }
	report("brick loaded", MSG_DEBUG);
    fclose(FileHandle);

    return true;
}

void BrickControl::delete_bricks()
{
    BrickControl::brickList.erase(BrickControl::brickList.begin(), BrickControl::brickList.end());
}
