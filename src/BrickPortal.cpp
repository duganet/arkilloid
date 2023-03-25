#include "BrickPortal.h"
#include "Constants.h"
#include <io.hpp>
#include <sstream>

std::vector<Portal*>PortalControl::PortalList;

BrickPortal::BrickPortal() {

}

unsigned int BrickPortal::get_pg() {
	return this->pg;
}

void BrickPortal::set_pg(unsigned int group) {
	std::stringstream st;
	st << group;
	report("Setting BrickPortal group: " + st.str(), MSG_DEBUG);
	this->pg = group;
}

/* Brick Portal Type A */

BrickPortalA::BrickPortalA()
{
	texture = new Texture();
	type = BRICK_PORTAL_A_T;
	cclip = 0;
	mpf = 70;
	mlast = SDL_GetTicks();
}

BrickPortalA::~BrickPortalA()
{
}

/*unsigned int BrickPortalA::get_pg()
{
	return this->pg;
}

void BrickPortalA::set_pg(unsigned int group)
{
	std::stringstream st;
	st << group;
	report("Setting BrickPortalA group: " + st.str(), MSG_DEBUG);
	this->pg = group;
}*/

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
	if (SDL_GetTicks() >= mlast + mpf)
	{
		mlast = SDL_GetTicks();
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
	mpf = 70;
	mlast = SDL_GetTicks();
}

BrickPortalB::~BrickPortalB()
{
}

/*unsigned int BrickPortalB::get_pg()
{
	return this->pg;
}

void BrickPortalB::set_pg(unsigned int group)
{
	std::stringstream st;
	st << group;
	report("Setting BrickPortalB group: " + st.str(), MSG_DEBUG);
	this->pg = group;
}*/

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
	if (SDL_GetTicks() >= mlast + mpf)
	{
		mlast = SDL_GetTicks();
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

PortalControl::PortalControl()
{
}

PortalControl::~PortalControl()
{
}

Portal::Portal(unsigned int type)
{
	report("Creating portal", MSG_DEBUG);
	this->set_type(type);
}

Portal::~Portal()
{
	
}

void Portal::set_coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Portal::set_group(unsigned int group)
{
	std::stringstream st;
	st << group;
	report("Setting portal group: " + st.str(), MSG_DEBUG);
	this->group = group;
}

void Portal::set_type(unsigned int type)
{
	std::stringstream st;
	st << type;
	report("Setting portal type: " + st.str(), MSG_DEBUG);
	this->type = type;
}
