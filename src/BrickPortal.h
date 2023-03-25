#ifndef BRICKPORTAL_H
#define BRICKPORTAL_H

#include "Brick.h"
#include "BrickStrong.h"
//#include "Ball.h"
#include "Texture.h"
#include <vector>


extern std::vector<Texture*>textureList;

class BrickPortal : public Brick {
	public:
		BrickPortal();
		virtual unsigned int get_pg();
		virtual void set_pg(unsigned int group);
	private:
		unsigned int pg;
};

class BrickPortalA : public BrickPortal
{
	public:
		BrickPortalA();
		virtual ~BrickPortalA();
		//virtual unsigned int get_pg();
		//virtual void set_pg(unsigned int group);
		virtual void set_up(int x, int y, Texture *texture = textureList[BRICK_PORTAL_A]);
		virtual void show();
//		void teleportate(Ball *ball);
	private:
		SDL_Rect clip[6];
		Texture *texture;
		unsigned int cclip, frame, mpf;
		long mlast;
};

class BrickPortalB : public BrickPortal
{
	public:
		BrickPortalB();
		virtual ~BrickPortalB();
		//virtual unsigned int get_pg();
		//virtual void set_pg(unsigned int group);
		virtual void set_up(int x, int y, Texture *texture = textureList[BRICK_PORTAL_B]);
		virtual void show();
	private:
		SDL_Rect clip[8];
		Texture *texture;
		unsigned int cclip, frame, mpf;
		long mlast;
};

class Portal
{
	public:
		Portal(unsigned int type);
		~Portal();
		int x, y;
		unsigned int group, type;
		void set_coords(int px, int py);
		void set_group(unsigned int group);
		void set_type(unsigned int type);
};

class PortalControl
{
	public:
		PortalControl();
		~PortalControl();
		static std::vector<Portal*>PortalList;
};

enum PortalTypes
{
	PORTAL_IN,
	PORTAL_OUT
};

#endif
