/*
* SDL2 tutorial
* How To Make A Game #7 : Entity Component System in C++ & SDL2 Tutorial
* https://www.youtube.com/watch?v=XsvI8Sng6dk
* 
* 2023.06.11
*/

#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;  // 16ms not 16.7ms

    Uint32 frameStart;
    Uint32 frameTime;

    game = new Game();
    game->init("GameWindow", 800, 640, false);
    
    while (game->running())
    {
        frameStart = (Uint32)SDL_GetTicks64();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = (Uint32)SDL_GetTicks64() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
