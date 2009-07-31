//Button.cpp
#include "Button.h"
#include "file.h"

extern std::ofstream loger;
extern int stateID;
extern int nextState;


Button::Button(int x, int y, std::string filename)
{
    filename = path_construct("images", filename);
    buttonSheet = new Texture;
    buttonSheet->load_from_file(filename, 0xFF,0,0xFF);

    buttonSheet->num_vclip = 2;

    clips[CLIP_MOUSEOVER].x = 0;
    clips[CLIP_MOUSEOVER].y = 0;
    clips[CLIP_MOUSEOVER].w = buttonSheet->w;
    clips[CLIP_MOUSEOVER].h = buttonSheet->h/2;

    clips[CLIP_MOUSEOUT].x = 0;
    clips[CLIP_MOUSEOUT].y = buttonSheet->h/2;
    clips[CLIP_MOUSEOUT].w = buttonSheet->w;
    clips[CLIP_MOUSEOUT].h = buttonSheet->h;

    box.x = x;
    box.y = y;
    box.w = buttonSheet->w;
    box.h = buttonSheet->h/2;

    clip = clips[CLIP_MOUSEOUT];
}

Button::~Button()
{
    delete buttonSheet;
}

void Button::handle_events(SDL_Event &event,void(callback)(void))
{
    //mouse_offsets
    int mouse_x,mouse_y;

    if(event.type == SDL_MOUSEMOTION)
    {
        mouse_x = event.motion.x;
        mouse_y = event.motion.y;

        if((mouse_x > box.x)&&(mouse_y > box.y)&&
           (mouse_x < box.x+box.w)&&(mouse_y < box.y+box.h))
        {
            clip = clips[CLIP_MOUSEOVER];
        }
        else
        {
            clip = clips[CLIP_MOUSEOUT];
        }
    }
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            mouse_x = event.button.x;
            mouse_y = event.button.y;
            if((mouse_x > box.x)&&(mouse_y > box.y)&&
                (mouse_x < box.x+box.w)&&(mouse_y < box.y+box.h))
            {
                //clip = clips[MOUSE_DOWN];
                callback();
            }
        }
    }
//    if(event.type == SDL_MOUSEBUTTONDOWN)
//    {
//        if(event.type == SDL_BUTTON_LEFT)
//        {
//            mouse_x = event.button.x;
//            mouse_y = event.button.y;
//            if((mouse_x > box.x)&&(mouse_y > box.y)&&
//                (mouse_x < box.x+box.w)&&(mouse_y < box.y+box.w))
//            {
//                //clip = clips[MOUSE_UP];
//            }.y;
//            if((mouse_x > box.x)&&(mouse_y > box.y)&&
//                (mouse_x < box.x+box.w)&&(mouse_y < box.y+box.w))
//            {
//                //clip = clips[MOUSE_UP];
//            }
//        }
//    }
}

void Button::show()
{
    buttonSheet->show(box.x, box.y,clip);
}

SDL_Rect Button::get_rect()
{
    return box;
}
