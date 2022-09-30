#ifndef HEADER_H
#define HEADER_H
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------
#define NUM_SHOOTS 50
#define NUM_MAX_ENEMIES 50
#define FIRST_WAVE 10
#define SECOND_WAVE 20
#define THIRD_WAVE 50
#define MAX_INPUT_CHARS 9

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum
{
    FIRST = 0,
    SECOND,
    THIRD
} EnemyWave;
typedef enum GameScreen
{
    LOGO = 0,
    TITLE,
    GAMEPLAY,
    RANKING,
    HIST1,
    HIST2,
    NOME
} GameScreen;

typedef struct Background
{
    Texture2D texture_back;
    int position_x;
    int position_y;
} Background;

typedef struct Player
{
    Texture2D scarfy;
    Rectangle rec;
    Vector2 speed;
    Color color;
} Player;

typedef struct Enemywave1
{
    Texture2D wave1;
} Enemywave1;

typedef struct Enemywave2
{
    Texture2D wave2;
} Enemywave2;

typedef struct Enemywave3
{
    Texture2D wave3;
} Enemywave3;

typedef struct Enemy
{
    Texture2D *realTextureEnemy[3];
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Enemy;

typedef struct Shoot
{
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Shoot;

typedef struct
{
    int pontos;
    char nome[10];
} mitinho;

char * auxiliar;
char nome_player[10];
mitinho pontos[10]/*={{100,"pedro"},{120,"braulio"},{150,"cleiton"},{150,"cleiton"},{160,"ademar"},{180,"creoke"},{190,"bolsonaro"},{200,"lula"},{210,"eymael"},{230,"kataguiri"}}*/;
int pedro;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

static bool gameOver = false;
static bool pause = false;
static int score = 0;
static bool victory = false;

static Enemywave1 enemywave1[4] = {0};
static Enemywave2 enemywave2[4] = {0};
static Enemywave3 enemywave3[4] = {0};
static Background background = {0};
static Player player = {0};
static Enemy enemy[NUM_MAX_ENEMIES] = {0};
static Shoot shoot[NUM_SHOOTS] = {0};
static EnemyWave wave = {FIRST};

static int shootRate = 0;
static float alpha = 0.0f;

static int activeEnemies = 0;
static int enemiesKill = 0;
static bool smooth = false;

GameScreen currentScreen = LOGO;
int framesCounter = 0;

int ganhou = 0;

int verificador = 0;

char name[MAX_INPUT_CHARS + 1] = "\0"; // NOTE: One extra space required for null terminator char '\0'
int letterCount = 0;

Rectangle textBox = {screenWidth / 2.0f - 100, 180, 225, 50};
bool mouseOnText = false;


//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);   // Initialize game
static void UpdateGame(void); // Update game (one frame)
static void DrawGame(void);   // Draw game (one frame)
static void UnloadGame(void); // Unload game
char * toArray(int number);
int compara(const void* a,const void* b);
int compara2(const void* a,const void* b);

#endif
