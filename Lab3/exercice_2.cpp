#include "entrypoint.h"
#include "raylib.h"
#define rect_size 50


void raylib_start(void)
{
    int screenWidth = 800;
    int screenHeight = 600;
    Vector2 pos = {screenWidth / 2, screenHeight / 2};

    InitWindow(screenWidth, screenHeight, "Lab 3 (#2)");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // W or A
        if (IsKeyDown(KEY_W))
        {
            pos.y -= 3;
        }
        else if (IsKeyDown(KEY_S))
        {
            pos.y += 3;
        }
        // A or D
        if (IsKeyDown(KEY_A))
        {
            pos.x -= 3;
        }
        else if (IsKeyDown(KEY_D))
        {
            pos.x += 3;
        }
        // Bring to opposite side if needed
        if (pos.x + rect_size < 0)
        {
            pos.x = screenWidth - rect_size;
        }
        else if (pos.x + rect_size > screenWidth)
        {
            pos.x = 0;
        }
        else if (pos.y + rect_size < 0)
        {
            pos.y = screenHeight - rect_size;
        }
        else if (pos.y + rect_size > screenHeight)
        {
            pos.y = 0;
        }

        DrawRectangle(pos.x, pos.y, rect_size, rect_size, RED);
        EndDrawing();
    }
    CloseWindow();
}
