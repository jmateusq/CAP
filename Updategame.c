#include "header.h"
#include <stdlib.h>
void UpdateGame(FILE *arc)
{
    qsort(pontos,10,sizeof(mitinho),compara);
    switch (currentScreen)
    {
    case LOGO:
    {
        framesCounter++; 

        // Espera 2 segundos para mudar pra proxima tela
        if (framesCounter > 120)
        {
            currentScreen = HIST1;
        }
    }
    break;
    case HIST1:
    {
        framesCounter++; 

        if (framesCounter > 900)
        {
            currentScreen = HIST2;
        }
        if (IsKeyPressed(KEY_ENTER)) // pular
        {
            currentScreen = HIST2;
        }
    }
    break;
    case HIST2:
    {
        framesCounter++; 

        
        if (framesCounter > 1800)
        {
            currentScreen = TITLE;
        }
        if (IsKeyPressed(KEY_ENTER)) // pular
        {
            currentScreen = TITLE;       
        }
    }
    break;
    case TITLE:
    {
        
        if (IsKeyPressed(KEY_ENTER)) // iniciar
        {
            currentScreen = GAMEPLAY;
            InitGame();
        }
        if (IsKeyPressed('R')) // ranking
        {
            currentScreen = RANKING;
        }
        if (IsKeyPressed('C')) // ranking
        {
            currentScreen = CREDITOS;
        }
    }
    break;
    case CREDITOS:
    {
        
        if (IsKeyPressed(KEY_ENTER)) 
        {
            currentScreen = TITLE;
            InitGame();
        }
    }
    break;
    case RANKING:
    {
        
        if (IsKeyPressed('R'))
        {
            currentScreen = TITLE;
            InitGame();
        }
    }
    break;

    case NOME:
    {
        
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            
            int key = GetCharPressed();

            
            while (key > 0)
            {
                
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0'; 
                    letterCount++;
                }

                key = GetCharPressed(); 
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                qsort(pontos,10,sizeof(mitinho),compara);
                strcpy(nome_player,name);
                strcpy(pontos[9].nome,nome_player);
                pontos[9].pontos=score;
                qsort(pontos,10,sizeof(mitinho),compara);
                rewind(arc);
                fwrite(&pontos,sizeof(mitinho),10,arc);
                currentScreen=RANKING;
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        
    }
    break;


    case GAMEPLAY:
    {
        if (!gameOver)
        {
            if (IsKeyPressed('P'))
                pause = !pause;

            if (!pause)
            {
                switch (wave)
                {
                case FIRST:
                {
                    if (!smooth)
                    {
                        alpha += 0.02f;

                        if (alpha >= 1.0f)
                            smooth = true;
                    }

                    if (smooth)
                        alpha -= 0.02f;

                    if (enemiesKill -25 == activeEnemies)
                    {
                        enemiesKill = 0;

                        for (int i = 0; i < activeEnemies; i++)
                        {
                            if (!enemy[i].active)
                                enemy[i].active = true;
                        }

                        activeEnemies = SECOND_WAVE;
                        wave = SECOND;
                        smooth = false;
                        alpha = 0.0f;
                    }
                }
                break;
                case SECOND:
                {
                    if (!smooth)
                    {
                        alpha += 0.02f;

                        if (alpha >= 1.0f)
                            smooth = true;
                    }

                    if (smooth)
                        alpha -= 0.02f;

                    if (enemiesKill -40 == activeEnemies)
                    {
                        enemiesKill = 0;

                        for (int i = 0; i < activeEnemies; i++)
                        {
                            if (!enemy[i].active)
                                enemy[i].active = true;
                        }

                        activeEnemies = THIRD_WAVE;
                        wave = THIRD;
                        smooth = false;
                        alpha = 0.0f;
                    }
                }
                break;
                case THIRD:
                {
                    if (!smooth)
                    {
                        alpha += 0.02f;

                        if (alpha >= 1.0f)
                            smooth = true;
                    }

                    if (smooth)
                        alpha -= 0.02f;

                    if (enemiesKill == activeEnemies)
                        victory = true;
                }
                break;
                default:
                    break;
                }

                // Movimento do jogador
                if (IsKeyDown(KEY_RIGHT))
                    player.rec.x += player.speed.x;
                if (IsKeyDown(KEY_LEFT))
                    player.rec.x -= player.speed.x;
                if (IsKeyDown(KEY_UP))
                    player.rec.y -= player.speed.y;
                if (IsKeyDown(KEY_DOWN))
                    player.rec.y += player.speed.y;

                // Colisão com inimigos
                for (int i = 0; i < activeEnemies; i++)
                {
                    if (CheckCollisionRecs(player.rec, enemy[i].rec))
                        gameOver = true;
                }

                // Comportamento dos inimigos
                for (int i = 0; i < activeEnemies; i++)
                {
                    if (enemy[i].active)
                    {
                        if (wave == FIRST) enemy[i].rec.x -= enemy[i].speed.x;
                        else if (wave == SECOND) enemy[i].rec.x -= enemy[i].speed.x + 1;
                        else if (wave == THIRD) enemy[i].rec.x -= enemy[i].speed.x + 2;

                        if (enemy[i].rec.x < -50)
                        {
                            enemy[i].rec.x = GetRandomValue(screenWidth, screenWidth + 1000);
                            enemy[i].rec.y = GetRandomValue(0, screenHeight - enemy[i].rec.height);
                        }
                    }
                }

                // Comortamento da parede
                if (player.rec.x <= 0)
                    player.rec.x = 0;
                if (player.rec.x + player.rec.width >= screenWidth)
                    player.rec.x = screenWidth - player.rec.width;
                if (player.rec.y <= 0)
                    player.rec.y = 0;
                if (player.rec.y + player.rec.height >= screenHeight)
                    player.rec.y = screenHeight - player.rec.height;

                // Inicialização do tiro
                if (IsKeyDown(KEY_SPACE))
                {
                    shootRate += 5;

                    for (int i = 0; i < NUM_SHOOTS; i++)
                    {
                        if (!shoot[i].active && shootRate % 20 == 0)
                        {
                            shoot[i].rec.x = player.rec.x + 30;
                            shoot[i].rec.y = player.rec.y + player.rec.height / 2;
                            shoot[i].active = true;
                            break;
                        }
                    }
                }

                // logica do tiro
                for (int i = 0; i < NUM_SHOOTS; i++)
                {
                    if (shoot[i].active)
                    {
                        // movimento
                        shoot[i].rec.x += shoot[i].speed.x;

                        // colisão com inimigo
                        for (int j = 0; j < activeEnemies; j++)
                        {
                            if (enemy[j].active)
                            {
                                if (CheckCollisionRecs(shoot[i].rec, enemy[j].rec))
                                {
                                    shoot[i].active = false;
                                    enemy[j].rec.x = GetRandomValue(screenWidth, screenWidth + 1000);
                                    enemy[j].rec.y = GetRandomValue(0, screenHeight - enemy[j].rec.height);
                                    shootRate = 0;
                                    enemiesKill++;
                                    score += 100;
                                }

                                if (shoot[i].rec.x + shoot[i].rec.width >= screenWidth)
                                {
                                    shoot[i].active = false;
                                    shootRate = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {

            if(score > pontos[9].pontos){
                currentScreen=NOME;
            }


            else{
                if (IsKeyPressed(KEY_ENTER))
                {
                    InitGame();
                    currentScreen=TITLE;
                }
            }
        }
    }
    break;
    default:
        break;
    }
}
