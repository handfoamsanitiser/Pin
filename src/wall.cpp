#include "wall.hpp"
#include "raylib.h"

Wall::Wall(float x, float y, float w, float h): aabb(AABB(x, y, w, h)) {}

void Wall::Render() {
    DrawRectangle(aabb.GetPos().x, aabb.GetPos().y, aabb.GetSize().x, aabb.GetSize().y, GRAY);
}

AABB Wall::GetAABB() {
    return aabb;
}

Vector2 Wall::GetPos() {
    return aabb.GetPos();
}

Vector2 Wall::GetSize() {
    return aabb.GetSize();
}