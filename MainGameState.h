#ifndef MAINGAMESTATE_H
#define MAINGAMESTATE_H

#include "GameState.h"

class MainGameState : public GameState
{
public:
    void init();
    void cleanup();
    void pause();
    void resume();
    bool execute(GameStateManager* gsm);

    static MainGameState* instance() { return &self; }

protected:
    MainGameState() {}

private:
    static MainGameState self;

};

#endif // MAINGAMESTATE_H
