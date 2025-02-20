#include "player.hpp"
#include "raylib.h"
#include "raymath.h"

Player::Player(): aabb(AABB(1.0f, 0.0f, 40.0f, 40.0f)), vel(Vector2 { 0.0, 0.0 }), speed(250.0) {}

void Player::Reset(float x, float y) {
    aabb.SetPosX(x);
    aabb.SetPosY(y);
}

void Player::Update() {
    vel.x = 0;
    vel.y = 0;
    if (IsKeyDown(KEY_W)) {
        vel.y = -1;
    }
    if (IsKeyDown(KEY_S)) {
        vel.y = 1;
    }
    if (IsKeyDown(KEY_A)) {
        vel.x = -1;
    }
    if (IsKeyDown(KEY_D)) {
        vel.x = 1;
    }

    vel = Vector2Normalize(vel);
    vel.x *= speed;
    vel.y *= speed;

    aabb.SetPosX(aabb.GetPos().x + vel.x * GetFrameTime());
    aabb.SetPosY(aabb.GetPos().y + vel.y * GetFrameTime());
}

void Player::Render() {
    DrawRectangleV(aabb.GetPos(), aabb.GetSize(), RED);
}

AABB *Player::GetAABB() {
    return &aabb;
}

Vector2 Player::GetPos() {
    return aabb.GetPos();
}

Vector2 Player::GetVel() {
    return vel;
}