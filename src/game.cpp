#include "game.h"

#include "parallax_background.h"
#include "player.h"
#include "obstacle.h"
#include "score.h"
#include "game_scene.h"

const int screenWidth = 1280; //1280
const int screenHeight = 768; //768

void InitGame();
void ColissionPlayerObstacle(Player& Player, Obstacle& Obstacle);
void CheckScore(Obstacle& Obstacle);
void LoadTextures();
void UnloadTextures();
void DrawPause();

Player player;
Rectangle playerColission;

Obstacle obstacle[maxObstacles];

bool isPlay = false;
bool isPause = false;

Texture2D playerImg;
Texture2D obstacleDownImg;
Texture2D obstacleUpImg;
Sound scoreMusic;

void StartGame() {
    InitWindow(screenWidth, screenHeight, "Flying Bird by Manuel Dantuono");
    InitAudioDevice();
    LoadTextures();
    LoadParallax();
    InitGame();
    while (!WindowShouldClose())
    {
        ScreenScene();   
    }
    UnloadTextures();
    UnloadParallax();
    CloseAudioDevice();
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

    if (isPlay && !isPause)
    {  
        UpdateParallax();
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
    DrawBackgroundGame();
    //Player
#if _DEBUG
    DrawRectangle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), static_cast<int>(player.width), static_cast<int>(player.height), RED);
#endif
    DrawTexture(playerImg, static_cast<int>(player.position.x - player.width / 8), static_cast<int>(player.position.y - player.height / 2.5f), WHITE);
 

    //Obstacle
    for (int i = 0; i < maxObstacles; i++)
    {
#if _DEBUG
        DrawRectangle(static_cast<int>(obstacle[i].positionDown.x), static_cast<int>(obstacle[i].positionDown.y), static_cast<int>(obstacle[i].widthDown), static_cast<int>(obstacle[i].heightDown), GREEN);
        DrawRectangle(static_cast<int>(obstacle[i].positionUp.x), static_cast<int>(obstacle[i].positionUp.y), static_cast<int>(obstacle[i].widthUp), static_cast<int>(obstacle[i].heightUp), GREEN);
#endif
        DrawTexture(obstacleDownImg, static_cast<int>(obstacle[i].positionUp.x - obstacle[i].widthUp / 1.12f), static_cast<int>(obstacle[i].positionUp.y - obstacle[i].heightUp / 4.5f), WHITE);
        DrawTexture(obstacleUpImg, static_cast<int>(obstacle[i].positionDown.x - obstacle[i].widthDown / 1.12f), static_cast<int>(obstacle[i].positionDown.y - obstacle[i].heightDown / 4), WHITE);
        
    }
    int positionCircle = 100;
    float sizeCircle = 40;
    Rectangle mousePosition = { GetMousePosition().x, GetMousePosition().y, 1,1 };
    DrawCircle(GetScreenWidth() - positionCircle, positionCircle, sizeCircle + 5, BLACK);
    DrawCircle(GetScreenWidth() - positionCircle, positionCircle, sizeCircle, WHITE);
    

    if (CheckCollisionCircleRec({ static_cast<float>(GetScreenWidth() - positionCircle), static_cast<float>(positionCircle) }, sizeCircle, mousePosition))
    {
        DrawCircle(GetScreenWidth() - positionCircle, positionCircle, sizeCircle, RED);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            isPause = true;
        }
        
    }
    DrawText("| |", GetScreenWidth() - 120, 70, 60, BLACK);
    //Score
    DrawScore();

    //Version
    DrawVersion();

    if (!isPlay)
    {
        DrawText("Click to Jump!", GetScreenWidth() / 7, GetScreenHeight() / 2, static_cast<int>(sizeCircle), BLACK);
        DrawText("Click to Jump!", static_cast<int>(GetScreenWidth() / 6.95f), static_cast<int>(GetScreenHeight() / 1.98f), static_cast<int>(sizeCircle), RED);
        DrawText("Escape to Pause!", GetScreenWidth() / 7, static_cast<int>(GetScreenHeight() / 1.7f), 40, BLACK);
        DrawText("Escape to Pause!", static_cast<int>(GetScreenWidth() / 6.95f), static_cast<int>(GetScreenHeight() / 1.69f), static_cast<int>(sizeCircle), RED);
    }

    if (isPause)
    {
        DrawPause();
    }

    EndDrawing();
}

void DrawVersion() {
    DrawText("Version 1.0", static_cast<int>(GetScreenWidth() - 120), static_cast<int>(GetScreenHeight() - 30), 20, WHITE);
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

    if (Player.position.y < 0 - Player.height)
    {
        RestartGame();
    }
}

void CheckScore(Obstacle& Obstacle) {
    Rectangle checkScore = { Obstacle.positionDown.x + Obstacle.widthDown / 2, Obstacle.positionDown.y + GetScreenHeight() / 2, Obstacle.widthDown / 6, Obstacle.heightDown };

    if (CheckCollisionRecs(playerColission, checkScore))
    {
        Obstacle.checkAddScore++;
        if (Obstacle.checkAddScore == 1)
        {
            AddScore(1);
            PlaySound(scoreMusic);
            UpdateMaxScore();
        }
    }
    else
    {
        Obstacle.checkAddScore = 0;
    }

}

void LoadTextures() {
    playerImg = LoadTexture("rsc/bird.png");
    obstacleDownImg = LoadTexture("rsc/obstacleDown.png");
    obstacleUpImg = LoadTexture("rsc/obstacleUp.png");
    scoreMusic = LoadSound("rsc/point.mp3");

    playerImg.width = GetScreenWidth() / 12;
    playerImg.height = GetScreenHeight() / 8;

    obstacleDownImg.width = GetScreenWidth() / 4;
    obstacleDownImg.height = GetScreenHeight();

    obstacleUpImg.width = GetScreenWidth() / 4;
    obstacleUpImg.height = GetScreenHeight();

    SetSoundVolume(scoreMusic, 1);
    SetSoundPitch(scoreMusic, 3);
}

void UnloadTextures() {
    UnloadTexture(playerImg);
    UnloadTexture(obstacleDownImg);
    UnloadTexture(obstacleUpImg);
}

void DrawPause() {
    Rectangle mousePosition = { GetMousePosition().x, GetMousePosition().y, 1,1 };
    Rectangle Reanude = { static_cast<float>(GetScreenWidth() / 3.5f), static_cast<float>(GetScreenHeight() / 2) ,static_cast<float>(GetScreenWidth() / 7), static_cast<float>(GetScreenHeight() / 10) };
    Rectangle Menu = { static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 12), static_cast<float>(GetScreenHeight() / 2) ,static_cast<float>(GetScreenWidth() / 7), static_cast<float>(GetScreenHeight() / 10) };
    Rectangle Pause{ static_cast<float>(GetScreenWidth() / 3.9f), static_cast<float>(GetScreenHeight() / 3.9f), static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 1.9f) };

    DrawRectangle(GetScreenWidth() / 4, GetScreenHeight() / 4, static_cast<int>(GetScreenWidth() / 1.95f), static_cast<int>(GetScreenHeight() / 1.8f), BLACK);
  
    DrawRectangleGradientEx(Pause, SKYBLUE, BLUE, DARKBLUE, WHITE);

    DrawRectangleRec(Reanude, WHITE);
    DrawRectangleRec(Menu, WHITE);

    DrawText("Game Paused!", static_cast<int>(GetScreenWidth() / 2.5f), GetScreenHeight() / 3, 50, BLACK);
    DrawText("Game Paused!", static_cast<int>(GetScreenWidth() / 2.49f), static_cast<int>(GetScreenHeight() / 2.95f), 50, RED);
    DrawText("Reanude", static_cast<int>(GetScreenWidth() / 3.4f), static_cast<int>(GetScreenHeight() / 1.9f), 40, BLACK);
    DrawText("Reanude", static_cast<int>(GetScreenWidth() / 3.39f), static_cast<int>(GetScreenHeight() / 1.89f), 40, RED);
    DrawText("Menu", static_cast<int>(GetScreenWidth() / 2 + GetScreenWidth() / 9), static_cast<int>(GetScreenHeight() / 1.9f), 40, BLACK);
    DrawText("Menu", static_cast<int>(GetScreenWidth() / 2 + GetScreenWidth() / 8.99f), static_cast<int>(GetScreenHeight() / 1.89f), 40, RED);

    if (CheckCollisionRecs(mousePosition, Reanude))
    {
        DrawRectangleRec(Reanude, BLACK);
        DrawText("Reanude", static_cast<int>(GetScreenWidth() / 3.4f), static_cast<int>(GetScreenHeight() / 1.9f), 40, WHITE);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            isPause = false;
        }
    }

    if (CheckCollisionRecs(mousePosition, Menu))
    {
        DrawRectangleRec(Menu, BLACK);
        DrawText("Menu", static_cast<int>(GetScreenWidth() / 2 + GetScreenWidth() / 9), static_cast<int>(GetScreenHeight() / 1.9f), 40, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            isPause = false;
            CheckDefeat(true);
        }
    }
}

void ActivatePause() {
    isPause = true;
}
