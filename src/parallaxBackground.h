#pragma once
#include "raylib.h"

static Texture2D floor;
static Texture2D mountain;
static Texture2D background;

static float scrollback;
static float speedFloor = 300;
static float scrollbackMountain;
static float speedMountain = 150;
static float scrollbackground;
static float speedCity = 50;

void LoadParallax();
void UnloadParallax();
void DrawBackgroundGame();
void DrawFloorParallax();
void DrawMountainParallax();
void DrawBackgroundParallax();
void UpdateParallax();
void RestartParallax();
