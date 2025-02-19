#include "raylib.h"
#include <vector>
#include "constants.hpp"
#include "player.hpp"
#include "wall.hpp"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

Camera2D camera;

Player player;
std::vector<Wall> walls;

void UpdateDrawFrame();

int main() {
    InitWindow(screenWidth, screenHeight, "Explorer");
    InitAudioDevice();

    // camera initialisation
    camera.target = player.GetPos();
    camera.offset = Vector2 { screenWidth / 2, screenHeight / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // wall initialisation
    walls.push_back(Wall(100, 100, 50, 50));
    walls.push_back(Wall(350, 250, 50, 50));
    walls.push_back(Wall(0, 100, 50, 50));
    walls.push_back(Wall(100, 0, 50, 50));
    walls.push_back(Wall(600, 600, 50, 50));

    #if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
    #else
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
    #endif
    
    CloseAudioDevice();
    CloseWindow();
}

void UpdateDrawFrame() {
    player.Update();
    camera.target = player.GetPos();

    BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
            player.Render();

            for (Wall wall : walls) {
                wall.Render();
            }
        EndMode2D();
    EndDrawing();
}