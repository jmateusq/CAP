#include "header.h"
void UpdateGame(void)
{
    switch (currentScreen)
    {
    case LOGO:
    {
        // TODO: Update LOGO screen variables here!

        framesCounter++; // Count frames

        // Wait for 2 seconds (120 frames) before jumping to TITLE screen
        if (framesCounter > 1)
        {
            currentScreen = HIST1;
        }
    }
    break;
    case HIST1:
    {
        // TODO: Update LOGO screen variables here!

        framesCounter++; // Count frames

        // Wait for 2 seconds (120 frames) before jumping to TITLE screen
        if (framesCounter > 1)
        {
            currentScreen = HIST2;
        }
    }
    break;
    case HIST2:
    {
        // TODO: Update LOGO screen variables here!

        framesCounter++; // Count frames

        // Wait for 2 seconds (120 frames) before jumping to TITLE screen
        if (framesCounter > 1)
        {
            currentScreen = TITLE;
        }
    }
    break;
    case TITLE:
    {
        // TODO: Update TITLE screen variables here!

        // Press enter to change to GAMEPLAY screen
        if (IsKeyPressed(KEY_ENTER)) // iniciar
        {
            currentScreen = GAMEPLAY;
            InitGame();
        }
        if (IsKeyPressed('R')) // ranking
        {
            currentScreen = RANKING;
        }
    }
    break;
    case RANKING:
    {
        // TODO: Update ENDING screen variables here!

        // Press enter to return to TITLE screen
        if (IsKeyPressed(KEY_ENTER))
        {
            currentScreen = GAMEPLAY;
        }
        if (IsKeyPressed('R'))
        {
            currentScreen = TITLE;
        }
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

                    if (enemiesKill == activeEnemies)
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

                    if (enemiesKill == activeEnemies)
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

                // Player movement
                if (IsKeyDown(KEY_RIGHT))
                    player.rec.x += player.speed.x;
                if (IsKeyDown(KEY_LEFT))
                    player.rec.x -= player.speed.x;
                if (IsKeyDown(KEY_UP))
                    player.rec.y -= player.speed.y;
                if (IsKeyDown(KEY_DOWN))
                    player.rec.y += player.speed.y;

                // Player collision with enemy
                for (int i = 0; i < activeEnemies; i++)
                {
                    if (CheckCollisionRecs(player.rec, enemy[i].rec))
                        gameOver = true;
                }

                // Enemy behaviour
                for (int i = 0; i < activeEnemies; i++)
                {
                    if (enemy[i].active)
                    {
                        enemy[i].rec.x -= enemy[i].speed.x;

                        if (enemy[i].rec.x < -40)
                        {
                            enemy[i].rec.x = GetRandomValue(screenWidth, screenWidth + 1000);
                            enemy[i].rec.y = GetRandomValue(0, screenHeight - enemy[i].rec.height);
                        }
                    }
                }

                // Wall behaviour
                if (player.rec.x <= 0)
                    player.rec.x = 0;
                if (player.rec.x + player.rec.width >= screenWidth)
                    player.rec.x = screenWidth - player.rec.width;
                if (player.rec.y <= 0)
                    player.rec.y = 0;
                if (player.rec.y + player.rec.height >= screenHeight)
                    player.rec.y = screenHeight - player.rec.height;

                // Shoot initialization
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

                // Shoot logic
                for (int i = 0; i < NUM_SHOOTS; i++)
                {
                    if (shoot[i].active)
                    {
                        // Movement
                        shoot[i].rec.x += shoot[i].speed.x;

                        // Collision with enemy
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
            if (IsKeyPressed(KEY_ENTER))
            {
                InitGame();
                gameOver = false;
            }
        }
    }
    break;
    default:
        break;
    }
}