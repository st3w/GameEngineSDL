#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameStateManager;

class GameState
{
public:
    virtual void init() = 0;
    virtual void cleanup() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual bool execute(GameStateManager*) = 0;

protected:
    GameState() {}
};

#endif // GAMESTATE_H
