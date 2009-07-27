//GameState.cpp
#include "GameState.h"

extern int stateID;
extern int nextState;

void GameState::set_next_state( int newState )
{
    //If the user doesn't want to exit
    if( nextState != STATE_EXIT )
    {
        //Set the next state
        nextState = newState;
    }
}

void buttonStart_click()
{
    set_next_state(STATE_LEVEL_1);
}

void buttonExit_click()
{
    stateID = STATE_EXIT;
}
