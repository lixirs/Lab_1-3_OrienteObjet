#include "entrypoint.h"
#include "raylib.h"

void raylib_start(void){
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Lab 3 (#1)");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);

        // Soleil
        DrawCircle(750, 90, 50, YELLOW);

        // Sol
        DrawRectangle(0, 400, screenWidth, 350, GREEN);

        // Maison
        DrawRectangle(250, 250, 200, 150, BEIGE);

        // Porte
        DrawRectangle(325, 320, 50, 80, DARKBROWN);

        // Fenêtres
        DrawRectangle(275, 290, 40, 40, LIGHTGRAY);
        DrawRectangle(385, 290, 40, 40, LIGHTGRAY);

        // Arbre
        DrawRectangle(580, 300, 30, 100, BROWN);
        DrawCircle(595, 260, 45, DARKGREEN);

        EndDrawing();
    }

    CloseWindow();
}
