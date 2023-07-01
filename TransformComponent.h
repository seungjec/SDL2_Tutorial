#pragma once

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
private:
    //int xpos;
    //int ypos;

public:
    Vector2D position;

    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    //int x() { return xpos; }
    //int y() { return ypos; }

    void update() override
    {
        //position.x++;
        //position.y++;
    }

    void setPos(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    //void x(int x) { xpos = x; }
    //void y(int y) { ypos = y; }
};