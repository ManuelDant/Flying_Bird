#include "game.h"
#include "player.h"
#include "obstacle.h"
#include "score.h"
#include "gameScene.h"

const int screenWidth = 1280;
const int screenHeight = 768;

void InitGame();
void DrawVersion();
void ColissionPlayerObstacle(Player& Player, Obstacle& Obstacle);
void CheckScore(Obstacle& Obstacle);

Player player;
Rectangle playerColission;

Obstacle obstacle[maxObstacles];

bool isPlay = false;

void StartGame() {
    InitWindow(screenWidth, screenHeight, "Flying Bird by Manuel Dantuono");

    InitGame();
    while (!WindowShouldClose())
    {
        ScreenScene();   
    }

    CloseWindow();
}

void InitGame() {
     player = CreatePlayer();
     for (int i = 0; i < maxObstacles; i++)
     {
         obstacle[i] = CreateObstacle();
         StartPositionObstacle(obstacle);
     }
}

void Update() {
    if (!isPlay && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        isPlay = true;
    }

    if (isPlay)
    {
        PlayerInput(player);
        MovePlayer(player);

        MoveObstacle(obstacle);
       
        for (int i = 0; i < maxObstacles; i++)
        {
            ColissionPlayerObstacle(player, obstacle[i]);
            CheckScore(obstacle[i]);
        }
       
    }   
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(BLACK);

    //Player
    DrawRectangle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), static_cast<int>(player.width), static_cast<int>(player.height), RED);

    //Obstacle
    for (int i = 0; i < maxObstacles; i++)
    {
        DrawRectangle(static_cast<int>(obstacle[i].positionDown.x), static_cast<int>(obstacle[i].positionDown.y), static_cast<int>(obstacle[i].widthDown), static_cast<int>(obstacle[i].heightDown), GREEN);
        DrawRectangle(static_cast<int>(obstacle[i].positionUp.x), static_cast<int>(obstacle[i].positionUp.y), static_cast<int>(obstacle[i].widthUp), static_cast<int>(obstacle[i].heightUp), GREEN);
    }

    //Score
    DrawScore();

    //Version
    DrawVersion();

    EndDrawing();
}

void DrawVersion() {
    DrawText("Version 0.4", static_cast<int>(GetScreenWidth() - 120), static_cast<int>(GetScreenHeight() - 30), 20, WHITE);
}

void RestartGame() {
    StartPositionPlayer(player);
    StartPositionObstacle(obstacle);
    isPlay = false;

    RestartScore();
}

void ColissionPlayerObstacle(Player& Player, Obstacle& Obstacle) {
    playerColission = { Player.position.x , Player.position.y, Player.width, Player.height };
    Rectangle obstacleDown = { Obstacle.positionDown.x , Obstacle.positionDown.y, Obstacle.widthDown, Obstacle.heightDown };
    Rectangle obstacleUp = { Obstacle.positionUp.x , Obstacle.positionUp.y, Obstacle.widthUp, Obstacle.heightUp };
    

    if (CheckCollisionRecs(playerColission, obstacleDown))
    {
        RestartGame();
    }

    if (CheckCollisionRecs(playerColission, obstacleUp))
    {
        RestartGame();
    }
}

void CheckScore(Obstacle& Obstacle) {
    Rectangle checkScore = { Obstacle.positionDown.x + Obstacle.widthDown / 2, Obstacle.positionDown.y + betweenObstacles / 2, Obstacle.widthDown / 6, Obstacle.heightDown };

    if (CheckCollisionRecs(playerColission, checkScore))
    {
        Obstacle.checkAddScore++;
        if (Obstacle.checkAddScore == 1)
        {
            AddScore(1);
            UpdateMaxScore();
        }
    }
    else
    {
        Obstacle.checkAddScore = 0;
    }

}