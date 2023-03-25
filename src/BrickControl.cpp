//BrickControl.cpp
#include "BrickControl.h"
#include "BrickPortal.h"
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
    unsigned int agroup = 0;
    unsigned int bgroup = 0;
    for (int i = 0; i < brickCount; i++)
    {
        Brick *brick;
        BrickPortal *brick_portal;
        Portal *portal;

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
			agroup++;
			brick_portal = new BrickPortalA();
			brick_portal->set_up(X,Y);
			brick_portal->set_pg(agroup);
			BrickControl::brickList.push_back(brick_portal);
			portal = new Portal(PORTAL_IN);
			portal->set_group(agroup);
			portal->set_coords(X,Y);
			PortalControl::PortalList.push_back(portal);
			break;
        case BRICK_PORTAL_B_T:
			bgroup++;
			brick_portal = new BrickPortalB();
			brick_portal->set_up(X,Y);
			brick_portal->set_pg(bgroup);
			BrickControl::brickList.push_back(brick_portal);
			portal = new Portal(PORTAL_OUT);
			portal->set_group(bgroup);
			portal->set_coords(X,Y);
			PortalControl::PortalList.push_back(portal);
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
