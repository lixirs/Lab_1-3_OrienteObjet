#include "entrypoint.h"
#include "raylib.h"
#define rect_size 50

void raylib_start(void)
{
    int screenWidth = 800;
    int screenHeight = 600;
    Vector2 speedAxis = {5, 3};
    Vector2 pos = {screenWidth / 2, screenHeight / 2};

    InitWindow(screenWidth, screenHeight, "Lab 3 (#3)");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        pos.x += speedAxis.x;
        pos.y += speedAxis.y;
        // bounce effect
        if (pos.x + rect_size >= screenWidth || pos.x < 0)
        {
            speedAxis.x = -speedAxis.x;
        }
        if (pos.y + rect_size >= screenHeight || pos.y < 0)
        {
            speedAxis.y = -speedAxis.y;
        }
        DrawRectangle(pos.x, pos.y, rect_size, rect_size, RED);
        EndDrawing();
    }
    CloseWindow();
}
