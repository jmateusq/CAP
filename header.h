#ifndef CABECALHO_H
#define CABECALHO_H
#include "raylib.h"
//Todos os "defines" aqui
#define NUM_SHOOTS 50
#define NUM_MAX_ENEMIES 30
#define FIRST_WAVE 10
#define SECOND_WAVE 20
#define THIRD_WAVE 50

//Todos os typedefs aqui
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING, RANKING } GameScreen;
typedef enum { FIRST = 0, SECOND, THIRD } EnemyWave;

typedef struct Player{
    Rectangle rec;
    Vector2 speed;
    Color color;
} Player;

typedef struct Enemy{
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

//Variaveis globais
const int screenWidth = 800;
const int screenHeight = 450;

bool gameOver = false;
bool pause =  false;
int score = 0;
bool victory = false;

Player player = { 0 };
Enemy enemy[NUM_MAX_ENEMIES] = { 0 };
Shoot shoot[NUM_SHOOTS] = { 0 };
EnemyWave wave = { FIRST };

int shootRate = 0;
float alpha = 0.0f;

int activeEnemies = 0;
int enemiesKill = 0;
bool smooth = false;


//declarações de funções

void InitGame(void);         // Inicia o jogo
void UpdateGame(void);       // atualiza um frame do jogo
void DrawGame(void);         // desenha um frame do jogo
void UnloadGame(void);       // Unload game

#endif
