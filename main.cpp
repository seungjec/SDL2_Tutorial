/*
* SDL2 tutorial
* Making A Game #1: Making The Game Loop : C++ And SDL2 Tutorial
* https://www.youtube.com/watch?v=44tO977slsU
* 2023.06.10
*/

#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game();
    game->init("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}
