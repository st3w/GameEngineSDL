#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "SDL/SDL.h"
#include "GameStateManager.h"

class GameEngine
{
public:
    GameEngine(const char* title, int window_width, int window_height, bool fullscreen);
    ~GameEngine();

    bool isRunning() { return running; }
    void quit() { running = false; }

    GameStateManager gsm;
    SDL_Surface* screen;

private:
    bool running;
    bool fullscreen;
};

#endif // GAMEENGINE_H
