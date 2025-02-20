#pragma once
#include "raylib.h"

class AABB {
public:
    AABB(float x, float y, float w, float h);

    bool CheckCollide(AABB other);

    float GetIntersectX(AABB other);
    float GetIntersectY(AABB other);

    Vector2 GetPos();
    Vector2 GetSize();

private:
    Rectangle rect;
};