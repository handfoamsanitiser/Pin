#include "player.hpp"
#include "raylib.h"
#include "raymath.h"

Player::Player(): pos(Vector2 { 0.0, 0.0 }), vel(Vector2 { 0.0, 0.0 }), speed(250.0) {}

void Player::Reset(float x, float y) {
    pos.x = x;
    pos.y = y;
}

void Player::Update() {
    vel.x = 0;
    vel.y = 0;
    if (IsKeyDown(KEY_UP)) {
        vel.y = -1;
    }
    if (IsKeyDown(KEY_DOWN)) {
        vel.y = 1;
    }
    if (IsKeyDown(KEY_LEFT)) {
        vel.x = -1;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        vel.x = 1;
    }

    vel = Vector2Normalize(vel);
    vel.x *= speed;
    vel.y *= speed;

    pos.x += vel.x * GetFrameTime();
    pos.y += vel.y *= GetFrameTime();
}

void Player::Render() {
    DrawCircle(pos.x, pos.y, 20, RED);
}

Vector2 Player::GetPos() {
    return pos;
}

Vector2 Player::GetVel() {
    return vel;
}