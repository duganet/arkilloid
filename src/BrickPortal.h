#ifndef BRICKPORTAL_H
#define BRICKPORTAL_H

#include "BrickStrong.h"
//#include "Ball.h"
#include "Texture.h"

extern std::vector<Texture*>textureList;

class BrickPortalA : public Brick
{
	public:
		BrickPortalA();
		virtual ~BrickPortalA();
		virtual void set_up(int x, int y, Texture *texture = textureList[BRICK_PORTAL_A]);
		virtual void show();
//		void teleportate(Ball *ball);
	private:
		SDL_Rect clip[6];
		Texture *texture;
		unsigned int cclip, frame, fpc;
};

class BrickPortalB : public Brick
{
	public:
		BrickPortalB();
		virtual ~BrickPortalB();
		virtual void set_up(int x, int y, Texture *texture = textureList[BRICK_PORTAL_B]);
		virtual void show();
	private:
		SDL_Rect clip[8];
		Texture *texture;
		unsigned int cclip, frame, fpc;
};

#endif
