#pragma once
#include "raylib.h"

class AABB {
public:
    AABB(float x, float y, float w, float h);

    bool CheckCollide(AABB other);
    void ResolveCollision(AABB other);

    float GetIntersectX(AABB other);
    float GetIntersectY(AABB other);

    Vector2 GetPos();
    Vector2 GetSize();

    void SetPosX(float x);
    void SetPosY(float y);

private:
    Rectangle rect;
};