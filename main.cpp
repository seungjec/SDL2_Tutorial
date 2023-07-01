/*
* SDL2 tutorial
* How To Make A Game #2 : Drawing Textures/Sprites To The Screen : C++ And SDL2 Image Tutorial
* https://www.youtube.com/watch?v=YrWQsuDT3NE
* 
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
