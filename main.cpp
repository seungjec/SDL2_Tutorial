/*
* SDL2 tutorial
* How To Make A Game #5 : Creating The GameObject Class : C++ And SDL2 Tutorial
* https://www.youtube.com/watch?v=agn8GqGrCj4
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
    int frameTime;

    game = new Game();
    game->init("GameWindow", 800, 600, false);
    
    while (game->running())
    {
        frameStart = SDL_GetTicks64();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks64() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
