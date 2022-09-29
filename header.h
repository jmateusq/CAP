#ifndef HEADER_H
#define HEADER_H
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------
#define NUM_SHOOTS 50
#define NUM_MAX_ENEMIES 50
#define FIRST_WAVE 10
#define SECOND_WAVE 20
#define THIRD_WAVE 50

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum { FIRST = 0, SECOND, THIRD } EnemyWave;
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY,RANKING, HIST1, HIST2 } GameScreen;

typedef struct Background{
    Texture2D texture_back;
    int position_x;
    int position_y;
} Background;

typedef struct Player{
    Texture2D scarfy;
    Rectangle rec;
    Vector2 speed;
    Color color;
} Player;

typedef struct Enemywave1{
    Texture2D wave1;
} Enemywave1;

typedef struct Enemywave2{
    Texture2D wave2;
} Enemywave2;

typedef struct Enemywave3{
    Texture2D wave3;
} Enemywave3;

typedef struct Enemy{
    Texture2D* realTextureEnemy[3];
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Enemy;

typedef struct Shoot{
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Shoot;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

static bool gameOver = false;
static bool pause =  false;
static int score = 0;
static bool victory = false;

static Enemywave1 enemywave1[4] = { 0 };
static Enemywave2 enemywave2[4] = { 0 };
static Enemywave3 enemywave3[4] = { 0 };
static Background background = { 0 };
static Player player= { 0 };
static Enemy enemy[NUM_MAX_ENEMIES] = { 0 };
static Shoot shoot[NUM_SHOOTS] = { 0 };
static EnemyWave wave = { FIRST };

static int shootRate = 0;
static float alpha = 0.0f;

static int activeEnemies = 0;
static int enemiesKill = 0;
static bool smooth = false;


GameScreen currentScreen = LOGO;
int framesCounter = 0;


//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game

#endif
