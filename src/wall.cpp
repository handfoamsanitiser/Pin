#include "wall.hpp"
#include "raylib.h"

Wall::Wall(float x, float y, float w, float h): pos(Vector2 { x, y }), size(Vector2 { w, h }) {}

void Wall::Render() {
    DrawRectangle(pos.x, pos.y, size.x, size.y, GRAY);
}

Vector2 Wall::GetPos() {
    return pos;
}

Vector2 Wall::GetSize() {
    return size;
}