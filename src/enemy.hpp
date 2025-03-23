#pragma once
#include "raylib.h"
#include "textures.hpp"
#include "aabb.hpp"

class Enemy {
public:
    Enemy(Vector2 pos, TextureResource *texture, Rectangle source);

    void Update();
    void Render();

    AABB *GetAABB();
    Vector2 GetPos();
    Vector2 GetVel();

private:
    AABB aabb;
    Vector2 vel;
    float speed;

    TextureResource *texture;
    Rectangle source;
    Rectangle dest;
};