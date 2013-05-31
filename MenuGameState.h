#ifndef MENUGAMESTATE_H
#define MENUGAMESTATE_H

#include "GameState.h"

class MenuGameState : public GameState
{
public:
    void init();
    void cleanup();
    void pause();
    void resume();
    bool execute(GameStateManager* gsm);

    static MenuGameState* instance()
    {
        return &self;
    }

protected:
    MenuGameState() {}

private:
    static MenuGameState self;

};

#endif // MENUGAMESTATE_H
