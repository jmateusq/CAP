#include "header.h"

void InitGame(void)
{
    //Initialize background
    background.texture_back = LoadTexture("background.png");
    background.position_x = 0;
    background.position_y = 0;

    // Initialize player
    player.rec.x =  20;
    player.rec.y = 50;
    player.rec.width = 40;
    player.rec.height = 40;
    
    player.scarfy = LoadTexture("New Piskel (1).png");
    player.speed.x = 4;
    player.speed.y = 5;
    player.color = BLACK;

    // Initialize texture enemies
    enemyTexture[0].textureEnemy = LoadTexture("se.png");
    enemyTexture[1].textureEnemy = LoadTexture("senao.png");
    enemyTexture[2].textureEnemy = LoadTexture("leia.png");
    enemyTexture[3].textureEnemy = LoadTexture("escreva.png");

    // Initializate enemies
    for (int i = 0; i < NUM_MAX_ENEMIES; i++)
    {
        enemy[i].realTextureEnemy = &enemyTexture[rand() % 4].textureEnemy;
        enemy[i].rec.width = 20;
        enemy[i].rec.height = 10;
        enemy[i].rec.x = GetRandomValue(screenWidth, screenWidth + 1000);
        enemy[i].rec.y = GetRandomValue(0, screenHeight - enemy[i].rec.height);
        enemy[i].speed.x = 5;
        enemy[i].speed.y = 5;
        enemy[i].active = true;
        enemy[i].color = GREEN;
    }


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
