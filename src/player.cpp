#include "player.hpp"
#include "raylib.h"
#include "raymath.h"
#include <cstdlib>

#define PLAYER_SIZE 100.0f
#define PLAYER_COL_SIZE 80.0f
#define PLAYER_COL_OFFSET (PLAYER_SIZE - PLAYER_COL_SIZE) / 2.0f

Sound callSounds[9];

Player::Player(): 
    aabb(AABB(0, 0, PLAYER_COL_SIZE, PLAYER_COL_SIZE)), 
    vel(Vector2 { 0, 0 }), 
    speed(250.0), 
    source(Rectangle { 0, 0, 280, 380 }),
    dest(Rectangle { 0, 0, PLAYER_SIZE, PLAYER_SIZE }) {}

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

    if (IsKeyPressed(KEY_G)) {
        PlayRandomCall();
    }

    // Flip player sprite in direction of mouse
    if (GetMousePosition().x < GetScreenWidth() / 2) {
        source.width = abs(source.width) * -1;
    } else {
        source.width = abs(source.width);
    }

    vel = Vector2Normalize(vel);
    vel.x *= speed;
    vel.y *= speed;

    aabb.SetPosX(aabb.GetPos().x + vel.x * GetFrameTime());
    aabb.SetPosY(aabb.GetPos().y + vel.y * GetFrameTime());
}

void Player::Render() {
    // Updates sprite position in render method for some reason
    // very bad, I'll fix it eventually
    dest.x = aabb.GetPos().x - PLAYER_COL_OFFSET;
    dest.y = aabb.GetPos().y - PLAYER_COL_OFFSET;

    //DrawRectangleV(aabb.GetPos(), aabb.GetSize(), RED);
    DrawTexturePro(texture, source, dest, Vector2 { 0, 0 }, 0, WHITE);
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

void Player::LoadTextures() {
    texture = LoadTextureFromImage(LoadImage("resources/textures/pin.png"));
}

Texture2D Player::GetTexture() {
    return texture;
}

Rectangle Player::GetTextureSource() {
    return source;
}

Rectangle Player::GetTextureDest() {
    return dest;
}

void Player::LoadSounds() {
    callSounds[0] = LoadSound("resources/audio/pin-0.ogg");
    callSounds[1] = LoadSound("resources/audio/pin-1.ogg");
    callSounds[2] = LoadSound("resources/audio/pin-2.ogg");
    callSounds[3] = LoadSound("resources/audio/pin-3.ogg");
    callSounds[4] = LoadSound("resources/audio/pin-4.ogg");
    callSounds[5] = LoadSound("resources/audio/pin-5.ogg");
    callSounds[6] = LoadSound("resources/audio/pin-6.ogg");
    callSounds[7] = LoadSound("resources/audio/pin-7.ogg");
    callSounds[8] = LoadSound("resources/audio/pin-8.ogg");
}

void Player::UnloadSounds() {
    for (Sound sound: callSounds) {
        UnloadSound(sound);
    }
}

void Player::PlayRandomCall() {
    int random = rand() % 9;
    switch (random) {
        case 0:
            PlaySound(callSounds[0]);
            break;
        case 1:
            PlaySound(callSounds[1]);
            break;
        case 2:
            PlaySound(callSounds[2]);
            break;
        case 3:
            PlaySound(callSounds[3]);
            break;
        case 4:
            PlaySound(callSounds[4]);
            break;
        case 5:
            PlaySound(callSounds[5]);
            break;
        case 6:
            PlaySound(callSounds[6]);
            break;
        case 7:
            PlaySound(callSounds[7]);
            break;
        case 8:
            PlaySound(callSounds[8]);
            break;
        default:
            break;
    }
}