#pragma once

#include "Components.h"
#include <SDL.h>

class SpriteComponent : public Component
{
private:
    PositionComponent* position;
    SDL_Texture* texture;
    SDL_Rect scrRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTex(path);
    }
    
    void setTex(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override
    {
        position = &entity->getComponent<PositionComponent>();

        scrRect.x = scrRect.y = 0;
        scrRect.w = scrRect.h = 32;
        destRect.w = destRect.h = 64;
    }

    void update() override
    {
        destRect.x = position->x();
        destRect.y = position->y();
    }

    void draw() override
    {
        TextureManager::Draw(texture, scrRect, destRect);
    }

};