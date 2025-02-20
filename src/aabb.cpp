#include "aabb.hpp"
#include "raylib.h"
#include <cmath>

AABB::AABB(float x, float y, float w, float h): rect(Rectangle { x, y, w, h }) {}

bool AABB::CheckCollide(AABB other) {
    if (rect.x < other.GetPos().x + other.GetSize().x
    && rect.x + rect.width > other.GetSize().x
    && rect.y < other.GetPos().y + other.GetSize().y
    && rect.y + rect.height > other.GetSize().y) {
        return true;
    }
    return false;
}

void AABB::ResolveCollision(AABB other) {
    if (!CheckCollide(other)) { return; }

    float intersectX = GetIntersectX(other);
    float intersectY = GetIntersectY(other);

    if (abs(intersectX) > abs(intersectY)) {
        rect.x -= intersectX;
    } else {
        rect.y -= intersectY;
    }
}

float AABB::GetIntersectX(AABB other) {
    if (rect.x + rect.width / 2 < other.GetPos().x + other.GetSize().x / 2) {
        return (other.GetPos().x - (rect.x + rect.width)) * -1;
    } else {
        return rect.x - (other.GetPos().x + other.GetSize().x);
    }
}

float AABB::GetIntersectY(AABB other) {
    if (rect.y + rect.height / 2 < other.GetPos().y + other.GetSize().y / 2) {
        return (other.GetPos().y - (rect.y + rect.height)) * -1;
    } else {
        return rect.y - (other.GetPos().y + other.GetSize().y);
    }
}

Vector2 AABB::GetPos() {
    return Vector2 { rect.x, rect.y };
}

Vector2 AABB::GetSize() {
    return Vector2 { rect.width, rect.height };
}