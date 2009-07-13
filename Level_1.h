//Level_1.h
#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "GameState.h"
#include "BrickControl.h"
#include "Ball.h"
#include "Bita.h"
#include "Timer.h"
#include "Bonus.h"
#include "Particles.h"
#include <vector>
#include <SDL/SDL_mixer.h>
class Level_1 : public GameState
{
public:
    Level_1(//Mix_Chunk* Hit,
            SDL_Surface*bg,
            SDL_Surface*brk_spr,
            SDL_Surface*brkstr_spr,
            SDL_Surface*brkbtn_spr,
            SDL_Surface *,
            SDL_Surface *bonus_speed_up_spr,
            SDL_Surface *bonus_speed_down_spr,
            SDL_Surface *bonus_life_spr,
            SDL_Surface *bonus_die_spr,
            SDL_Surface *bonus_add_spr,
            SDL_Surface *heart_sprite,
            SDL_Surface *particle_sprite,
            //std::vector<Mix_Chunk*> soundList,
            //TTF_Font* ,
            SDL_Surface*, TTF_Font*,
            int num_level,
            std::string filename);
    ~Level_1();
    void render(SDL_Surface*);
    void logic();
    void handle_events(SDL_Event&);
    void load_files();
protected:
    Mix_Chunk *hit;
    Mix_Chunk *hit_wall;
    SDL_Surface *back;
    SDL_Surface *level_label;
    SDL_Surface *level_label_small;
    SDL_Surface *clear_label;
    SDL_Surface *score_label;
    SDL_Surface *life_label;
    SDL_Surface *b_speed_up_sprite;
    SDL_Surface *b_speed_down_sprite;
    SDL_Surface *b_life_sprite;
    SDL_Surface *b_die_sprite;
    SDL_Surface *heart_spr;
    SDL_Surface *ball_spr;
    SDL_Surface *b_add_sprite;
    SDL_Surface *particle_spr;
    Ball *ball;
    Bita bita;
    Bonus *bonus;
    bool bonus_created;
    int collision_type;
    bool begin;
    bool clear;
    bool game_over;
    bool show_particles;
    Timer timer;
    Timer timer_speed_up;
    Timer timer_speed_down;
    TTF_Font *font_small;
    //SDL_Color textColor;
    int prevScore;
    int num_level;
    int pause;
    Particles *particles[20];
};

#endif
