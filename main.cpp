/*
* SDL2 tutorial
* How To Make Games #4 : Creating A Simple Texture Loader : C++ And SDL2 Tutorial
* https://www.youtube.com/watch?v=RqvpkZ7I1aU
* 
* 2023.06.10
*/

#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("GameWindow", 800, 600, false);
    
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
