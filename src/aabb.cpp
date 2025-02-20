#include "aabb.hpp"
#include "raylib.h"

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

Vector2 AABB::GetPos() {
    return Vector2 { rect.x, rect.y };
}

Vector2 AABB::GetSize() {
    return Vector2 { rect.width, rect.height };
}