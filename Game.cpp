#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

//SDL_Texture* playerTex;
//SDL_Rect srcR, destR;

GameObject* player;
GameObject* enemy;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    //playerTex = TextureManager::LoadTexture("assets/player.png", renderer);
    player = new GameObject("assets/player.png", renderer, 0, 0);
    enemy = new GameObject("assets/enemy.png", renderer, 50, 50);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    player->Update();
    enemy->Update();
    //cnt++;
    //destR.h = 64;
    //destR.w = 64;
    //destR.x = cnt;

    //std::cout << cnt << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // this is where we would add stuff to render
    //SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}
