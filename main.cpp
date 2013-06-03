#include "GameEngine.h"
#include "MenuGameState.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{

    cout << "Creating game" << endl;
    GameEngine game("Blue is Menu. Red is Gameplay.", 640, 480, false);
    cout << "Game created" << endl;
    game.gsm.changeState(MenuGameState::instance());

    while (game.isRunning())
        game.gsm.executeCurrentState();

    return 0;
}
