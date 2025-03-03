#pragma once
#include <vector>
#include "raylib.h"
#include "aabb.hpp"
#include "wall.hpp"
#include "textures.hpp"

extern Sound callSounds[9];

class Player {
public:
    Player();

    void Reset(float x, float y);
    void Update(Camera2D *camera, std::vector<Wall> walls);
    void Render();

    AABB *GetAABB();
    Vector2 GetPos();
    Vector2 GetVel();

    //void LoadTextures();
    Texture2D GetTexture();
    Rectangle GetTextureSource();
    Rectangle GetTextureDest();

    static void LoadSounds();
    static void UnloadSounds();

private:
    void ResolveCollision(std::vector<Wall> walls);
    void MoveCamera(Camera2D *camera);
    void PlayRandomCall();

    AABB aabb;
    Vector2 vel;
    float speed;

    TextureResource *texture;
    Rectangle source;
    Rectangle dest;
};