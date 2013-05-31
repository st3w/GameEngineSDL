#include "GameEngine.h"
#include "GameStateManager.h"
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

GameEngine::GameEngine(const char* title, int window_width, int window_height, bool fullscreen)
    : gsm(this)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cout << "Could not initialize SDL!" << endl;
        abort();
    }

    const SDL_VideoInfo* info = SDL_GetVideoInfo();
    int bpp = info->vfmt->BitsPerPixel;
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, true);
    int flags = SDL_OPENGL;
    if (fullscreen)
        flags |= SDL_FULLSCREEN;

    screen = SDL_SetVideoMode(window_width, window_height, bpp, flags);
    if (!screen)
    {
        cout << "SDL could not initialize the screen!" << endl;
        abort();
    }

    SDL_EnableUNICODE(SDL_TRUE);
    glClearColor( 0.f, 0.f, 1.f, 1.f );
    SDL_WM_SetCaption(title, nullptr);

    running = true;
}

GameEngine::~GameEngine()
{
    SDL_Quit();
}
