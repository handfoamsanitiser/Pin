#pragma once
#include "raylib.h"

class Wall {
public:
    Wall(float x, float y, float w, float h);

    void Render();

    Vector2 GetPos();
    Vector2 GetSize();

private:
    Vector2 pos;
    Vector2 size;
};