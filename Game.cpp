#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.addEntity());

Game::Game()
{
    isRunning = false;
    window = nullptr;
}
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

    map = new Map();

    // ECS implementation
    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("assets/player.png");
    player.addComponent<KeyboardController>();
}

void Game::handleEvents()
{
    //SDL_Event event;

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
    manager.refresh();
    manager.update();
    
    //player.getComponent<TransformComponent>().position.Add(Vector2D(5,0));

    //if (player.getComponent<TransformComponent>().position.x > 200)
    //{
    //    player.getComponent<SpriteComponent>().setTex("assets/enemy.png");
    //}
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
    //player->Render();
    //enemy->Render();
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
