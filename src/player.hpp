#pragma once
#include <vector>
#include "raylib.h"
#include "aabb.hpp"
#include "wall.hpp"
#include "textures.hpp"
#include "enemy.hpp"

extern Sound callSounds[9];
extern Sound explosionSound;

class Player {
public:
    Player();

    void Reset(float x, float y);
    void Update(Camera2D *camera, std::vector<Enemy> *enemies, std::vector<Wall> walls);
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
    void ResolveWallCollision(std::vector<Wall> walls);
    void ResolveEnemyCollision(std::vector<Enemy> *enemies);
    void MoveCamera(Camera2D *camera);
    void PlayRandomCall();

    AABB aabb;
    Vector2 vel;
    float speed;

    TextureResource *texture;
    Rectangle source;
    Rectangle dest;
};