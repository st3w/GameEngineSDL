#include "MenuGameState.h"
#include "MainGameState.h"
#include "GameStateManager.h"
#include "GameEngine.h"
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <iostream>
using std::cout;
using std::endl;

MenuGameState MenuGameState::self;

void MenuGameState::init()
{
    cout << "Initializing MenuGameState" << endl;
    glClearColor(0.,0.,1.,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapBuffers();
}

void MenuGameState::cleanup()
{
    cout << "Cleaning up MenuGameState" << endl;
}

void MenuGameState::pause()
{
    cout << "Pausing MenuGameState" << endl;
}

void MenuGameState::resume()
{
    cout << "Resuming MenuGameState" << endl;
    glClearColor(0.,0.,1.,1.);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapBuffers();
}

bool MenuGameState::execute(GameStateManager* gsm)
{
    cout << "Executing MenuGameState" << endl;

    bool running = true;
    bool status = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    gsm->game->quit();
                    running = false;
                    status = false;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    if (event.key.keysym.sym != SDLK_ESCAPE)
                    {
                        gsm->pushState(MainGameState::instance());
                        running = false;
                    }
                    else
                    {
                        gsm->game->quit();
                        running = false;
                        status = false;
                    }
                    break;
                }
            }
        }
    }

    return status;
}






