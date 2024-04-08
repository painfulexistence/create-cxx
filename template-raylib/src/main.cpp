#include "fmt/core.h"
#include "raylib.h"

int main(int argc, char* args[]) {
    fmt::print("Hello from CXX!\n");
    int width = 800;
    int height = 450;
    InitWindow(width, height, "raylib");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    return 0;
}