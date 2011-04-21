#include "BrickPortal.h"
#include "Constants.h"

/* Brick Portal Type A */

BrickPortalA::BrickPortalA()
{
	texture = new Texture();
	type = BRICK_PORTAL_A_T;
	cclip = 0;
	frame = 1;
	fpc = 15;
}

BrickPortalA::~BrickPortalA()
{
}

void BrickPortalA::set_up(int x, int y, Texture* texture)
{
	this->texture = texture;
	textureList[BRICK_PORTAL_A]->num_hclip = 6;
	int nclips = textureList[BRICK_PORTAL_A]->num_hclip;

	for(unsigned int i = 0; i < nclips; i++)
	{
		clip[i].x = textureList[BRICK_PORTAL_A]->w*i/nclips;
		clip[i].y = 0;
		clip[i].w = textureList[BRICK_PORTAL_A]->w*(i+1)/nclips;
		clip[i].h = textureList[BRICK_PORTAL_A]->h;
	}

    this->box.x = x;
    this->box.y = y;
    this->box.w = textureList[BRICK_PORTAL_A]->w/nclips;
    this->box.h = textureList[BRICK_PORTAL_A]->h;

}

void BrickPortalA::show()
{
	unsigned int nclips = textureList[BRICK_PORTAL_A]->num_hclip;
	if (frame < fpc)
	{
		frame++;
	}
	else
	{
		frame = 1;
		if (cclip < nclips - 1)
		{
			cclip++;
		}
		else
		{
			cclip = 0;
		}
	}
	textureList[BRICK_PORTAL_A]->show(box.x, box.y,clip[cclip]);
}

/*
void BrickPortalA::teleportate(Ball *ball)
{
	ball->teleportate();
}
*/

/* Brick Portal type B */

BrickPortalB::BrickPortalB()
{
	texture = new Texture();
	type = BRICK_PORTAL_B_T;
	cclip = 0;
	frame = 1;
	fpc = 15;
}

BrickPortalB::~BrickPortalB()
{
}

void BrickPortalB::set_up(int x, int y, Texture* texture)
{
	this->texture = texture;
	textureList[BRICK_PORTAL_B]->num_hclip = 6;
	int nclips = textureList[BRICK_PORTAL_B]->num_hclip;

	for(unsigned int i = 0; i < nclips; i++)
	{
		clip[i].x = textureList[BRICK_PORTAL_B]->w*i/nclips;
		clip[i].y = 0;
		clip[i].w = textureList[BRICK_PORTAL_B]->w*(i+1)/nclips;
		clip[i].h = textureList[BRICK_PORTAL_B]->h;
	}

    this->box.x = x;
    this->box.y = y;
    this->box.w = textureList[BRICK_PORTAL_B]->w/nclips;
    this->box.h = textureList[BRICK_PORTAL_B]->h;

}

void BrickPortalB::show()
{
	unsigned int nclips = textureList[BRICK_PORTAL_B]->num_hclip;
	if (frame < fpc)
	{
		frame++;
	}
	else
	{
		frame = 1;
		if (cclip < nclips - 1)
		{
			cclip++;
		}
		else
		{
			cclip = 0;
		}
	}
	textureList[BRICK_PORTAL_B]->show(box.x, box.y,clip[cclip]);
}
