#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <vector>
using std::vector;

class GameEngine;
class GameState;

class GameStateManager
{
public:
    GameStateManager(GameEngine* g);

    void changeState(GameState* state);
    void pushState(GameState* state);
    void popState();
    void executeCurrentState();

    GameEngine* game;

private:
    vector<GameState*> stateStack;

};

#endif // GAMESTATEMANAGER_H
