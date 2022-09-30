
#include "header.h"
void InitGame(void)
{
    //Initialize background
    background.texture_back = LoadTexture("./textures/background.png");
    background.position_x = 0;
    background.position_y = 0;

    // Initialize game variables
    shootRate = 0;
    pause = false;
    gameOver = false;
    victory = false;
    smooth = false;
    wave = FIRST;
    activeEnemies = FIRST_WAVE;
    enemiesKill = 0;
    score = 0;
    alpha = 0;

    // Initialize player
    player.rec.x =  20;
    player.rec.y = 50;
    player.rec.width = 40;
    player.rec.height = 40;
    
    player.scarfy = LoadTexture("./textures/New Piskel (1).png");
    player.speed.x = 4;
    player.speed.y = 5;
    player.color = BLACK;

    

    // Initialize texture enemies
    enemywave1[0].wave1 = LoadTexture("./textures/se.png");
    enemywave1[1].wave1 = LoadTexture("./textures/senao.png");
    enemywave1[2].wave1 = LoadTexture("./textures/leia.png");
    enemywave1[3].wave1 = LoadTexture("./textures/escreva.png");

    enemywave2[0].wave2 = LoadTexture("./textures/realloc.png");
    enemywave2[1].wave2 = LoadTexture("./textures/ponteiro.png");
    enemywave2[2].wave2 = LoadTexture("./textures/vetor.png");
    enemywave2[3].wave2 = LoadTexture("./textures/strlen.png");

    enemywave3[0].wave3 = LoadTexture("./textures/0010.png");
    enemywave3[1].wave3 = LoadTexture("./textures/1001.png");
    enemywave3[2].wave3 = LoadTexture("./textures/file.png");
    enemywave3[3].wave3 = LoadTexture("./textures/fseek.png");

    // Initializate enemies
    for (int i = 0; i < NUM_MAX_ENEMIES; i++)
    {
        enemy[i].realTextureEnemy[0] = &enemywave1[rand() % 4].wave1;
        enemy[i].realTextureEnemy[1] = &enemywave2[rand() % 4].wave2;
        enemy[i].realTextureEnemy[2] = &enemywave3[rand() % 4].wave3;
        enemy[i].rec.width = 40;
        enemy[i].rec.height = 13;
        enemy[i].rec.x = GetRandomValue(screenWidth, screenWidth + 1000);
        enemy[i].rec.y = GetRandomValue(0, screenHeight - enemy[i].rec.height);
        enemy[i].speed.x = 5;
        enemy[i].speed.y = 5;
        enemy[i].active = true;
        enemy[i].color = GREEN;
    }

    // Initialize shoots
    for (int i = 0; i < NUM_SHOOTS; i++)
    {
        shoot[i].rec.x = player.rec.x;
        shoot[i].rec.y = player.rec.y + player.rec.height/4;
        shoot[i].rec.width = 10;
        shoot[i].rec.height = 5;
        shoot[i].speed.x = 7;
        shoot[i].speed.y = 0;
        shoot[i].active = false;
        shoot[i].color = MAROON;
    }
}
