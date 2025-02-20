#pragma once
#include "raylib.h"
#include "aabb.hpp"

class Player {
public:
    Player();

    void Reset(float x, float y);
    void Update();
    void Render();

    AABB *GetAABB();
    Vector2 GetPos();
    Vector2 GetVel();

private:
    AABB aabb;
    Vector2 vel;
    float speed;
};