#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "constants.hpp"
#include "textures.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "wall.hpp"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

Camera2D camera;

Player player;
std::vector<Wall> walls;
std::vector<Enemy> enemies;

Music music;

void UpdateDrawFrame();

int main() {
    InitWindow(screenWidth, screenHeight, "Пин");
    InitAudioDevice();

    // texture initialisation
    playerTexture.Load("resources/textures/pin.png");
    kroshTexture.Load("resources/textures/krosh.png");
    yozhykTexture.Load("resources/textures/yozhyk.png");
    kopatychTexture.Load("resources/textures/kopatych.png");
    losyashTexture.Load("resources/textures/losyash.png");

    // camera initialisation
    camera.target = player.GetPos();
    camera.offset = Vector2 { screenWidth / 2, screenHeight / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // audio initialisation
    music = LoadMusicStream("resources/audio/music.ogg");
    PlayMusicStream(music);

    Player::LoadSounds();

    // enemy initialisation
    enemies.push_back(Enemy(Vector2 { 500, 500 }, &kopatychTexture, Rectangle { 100, 100, 1000, 1000 }));

    // wall initialisation
    walls.push_back(Wall(-2500, -2500, 50, 5000));
    walls.push_back(Wall(-2500, -2500, 5000, 50));
    walls.push_back(Wall(-2450, 2500, 5000, 50));
    walls.push_back(Wall(2500, -2500, 50, 5000));

    walls.push_back(Wall(100, 100, 50, 50));
    walls.push_back(Wall(350, 250, 50, 50));
    //walls.push_back(Wall(0, 100, 50, 50));
    //walls.push_back(Wall(100, 0, 50, 50));
    //walls.push_back(Wall(600, 600, 50, 50));

    #if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
    #else
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
    #endif
    
    UnloadMusicStream(music);
    Player::UnloadSounds();
    CloseAudioDevice();
    CloseWindow();
}

void UpdateDrawFrame() {
    UpdateMusicStream(music);
    player.Update(&camera, &enemies, walls);
    for (Enemy enemy: enemies) {
        enemy.Update();
    }

    BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
            for (Wall wall: walls) {
                wall.Render();
            }

            for (Enemy enemy: enemies) {
                enemy.Render();
            }

            player.Render();
        EndMode2D();
    EndDrawing();
}