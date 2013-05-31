#include "MainGameState.h"
#include "GameStateManager.h"
#include "GameEngine.h"
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
using std::cout;
using std::endl;

MainGameState MainGameState::self;

void MainGameState::init()
{
    cout << "Initializing MainGameState" << endl;
    glClearColor(1.,0.,0.,1.);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapBuffers();
}

void MainGameState::cleanup()
{
    cout << "Cleaning up MainGameState" << endl;
}

void MainGameState::pause()
{
    cout << "Pausing MainGameState" << endl;
}

void MainGameState::resume()
{
    cout << "Resuming MainGameState" << endl;
    glClearColor(1.,0.,0.,1.);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapBuffers();
}

bool MainGameState::execute(GameStateManager* gsm)
{
    cout << "Executing MainGameState" << endl;

    bool running = true;
    bool status = true;

    while (running)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gsm->game->quit();
                running = false;
                status = false;
                break;
            }

            Uint8* keys = SDL_GetKeyState(nullptr);
            if (keys[SDLK_ESCAPE])
            {
                gsm->popState();
                running = false;
                break;
            }
        }
    }

    return status;
}
