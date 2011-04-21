#include "BrickPortal.h"
#include "Constants.h"

/* Brick Portal Type A */

BrickPortalA::BrickPortalA()
{
	texture = new Texture();
	type = BRICK_PORTAL_A_T;
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
	SDL_Rect cclip;
	cclip = clip[0];
	textureList[BRICK_PORTAL_A]->show(box.x, box.y,cclip);
}

/* Brick Portal type B */

BrickPortalB::BrickPortalB()
{
	texture = new Texture();
	type = BRICK_PORTAL_B_T;
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
	SDL_Rect cclip;
	cclip = clip[0];
	textureList[BRICK_PORTAL_B]->show(box.x, box.y,cclip);
}
