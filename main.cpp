//main.cpp
#include "Game.h"

int main(int argc, char**argv)
{

    Game game;
    if(game.MainLoop() == false)
    {
        return 1;
    }
    return 0;
}
