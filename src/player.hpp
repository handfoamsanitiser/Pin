#pragma once
#include "raylib.h"
#include "aabb.hpp"

class Player {
public:
    Player();

    void Reset(float x, float y);
    void Update();
    void Render();

    AABB *GetAABB();
    Vector2 GetPos();
    Vector2 GetVel();

    void LoadTextures();
    Texture2D GetTexture();
    Rectangle GetTextureSource();
    Rectangle GetTextureDest();

    static void LoadSounds();
    static void UnloadSounds();

private:
    void PlayRandomCall();

    AABB aabb;
    Vector2 vel;
    float speed;

    Texture2D texture;
    Rectangle source;
    Rectangle dest;
};

extern Sound callSounds[2];