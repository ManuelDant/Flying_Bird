#include "game.h"
#include "player.h"

const int screenWidth = 1280;
const int screenHeight = 768;

void InitGame();
void Update();
void DrawGame();
void DrawVersion();

Player player;

void StartGame() {
    InitWindow(screenWidth, screenHeight, "Flying Bird by Manuel Dantuono");

    InitGame();
    while (!WindowShouldClose())
    {
        DrawGame();
        Update();   
    }

    CloseWindow();
}

void InitGame() {
     player = CreatePlayer();
}

void Update() {
    PlayerInput(player);
    MovePlayer(player);
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(BLACK);

    //Player
    DrawRectangle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), static_cast<int>(player.width), static_cast<int>(player.height), RED);

    DrawVersion();

    

    EndDrawing();
}

void DrawVersion() {
    DrawText("Version 0.1", static_cast<int>(GetScreenWidth() - 120), static_cast<int>(GetScreenHeight() - 30), 20, WHITE);
}