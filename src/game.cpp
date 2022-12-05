#include "game.h"
#include "player.h"
#include "obstacle.h"

const int screenWidth = 1280;
const int screenHeight = 768;

void InitGame();
void Update();
void DrawGame();
void DrawVersion();

Player player;
Obstacle obstacle;

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
     obstacle = CreateObstacle();
}

void Update() {
    PlayerInput(player);
    MovePlayer(player);
    MoveObstacle(obstacle);
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(BLACK);

    //Player
    DrawRectangle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), static_cast<int>(player.width), static_cast<int>(player.height), RED);

    //Obstacle
    DrawRectangle(static_cast<int>(obstacle.positionDown.x), static_cast<int>(obstacle.positionDown.y), static_cast<int>(obstacle.widthDown), static_cast<int>(obstacle.heightDown), GREEN);
    DrawRectangle(static_cast<int>(obstacle.positionUp.x), static_cast<int>(obstacle.positionUp.y), static_cast<int>(obstacle.widthUp), static_cast<int>(obstacle.heightUp), GREEN);

    DrawVersion();

    

    EndDrawing();
}

void DrawVersion() {
    DrawText("Version 0.2", static_cast<int>(GetScreenWidth() - 120), static_cast<int>(GetScreenHeight() - 30), 20, WHITE);
}