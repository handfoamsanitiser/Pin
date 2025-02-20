#pragma once
#include "raylib.h"
#include "aabb.hpp"

class Wall {
public:
    Wall(float x, float y, float w, float h);

    void Render();

    Vector2 GetPos();
    Vector2 GetSize();

private:
    AABB aabb;
};