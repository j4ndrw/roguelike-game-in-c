#include "raylib.h"

int main()
{
    InitWindow(1920, 1080, "Roguelike Game");
    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            const char* text = "Hello, World";
            int fontSize = 120;
            const int textSize = MeasureText(text, fontSize);
            DrawText(text, GetScreenWidth() / 2 - (textSize / 2), GetScreenHeight() / 2, fontSize, BLACK);
        EndDrawing();
    }
    return 0;
}
