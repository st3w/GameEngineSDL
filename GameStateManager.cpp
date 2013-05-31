#include "GameStateManager.h"
#include "GameEngine.h"
#include "GameState.h"

using std::vector;

GameStateManager::GameStateManager(GameEngine* g) : game(g) {}

void GameStateManager::changeState(GameState* state)
{
    // Free current state's resources and pop it
    if (!stateStack.empty())
    {
        stateStack.back()->cleanup();
        stateStack.pop_back();
    }

    // Push new state and initialize it
    stateStack.push_back(state);
    stateStack.back()->init();
}

void GameStateManager::pushState(GameState* state)
{
    // pause current state
    if (!stateStack.empty())
        stateStack.back()->pause();

    stateStack.push_back(state);
    stateStack.back()->init();
}

void GameStateManager::popState()
{
    if (!stateStack.empty())
    {
        stateStack.back()->cleanup();
        stateStack.pop_back();
    }

    if (!stateStack.empty())
        stateStack.back()->resume();
}

void GameStateManager::executeCurrentState()
{
    if (!stateStack.back()->execute(this))
        game->quit();
}
