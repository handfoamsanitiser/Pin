#pragma once
#include "raylib.h"

class Player {
public:
    Player();

    void Reset(float x, float y);
    void Update();
    void Render();

    Vector2 GetPos();
    Vector2 GetVel();

private:
    Vector2 pos;
    Vector2 vel;
    float speed;
};