#include "raylib.h"
#include "constants.hpp"
#include "player.hpp"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame();

Player player;

int main() {
    InitWindow(screenWidth, screenHeight, "Explorer");
    InitAudioDevice();

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
    BeginDrawing();
        ClearBackground(RAYWHITE);
        player.Render();
    EndDrawing();
}