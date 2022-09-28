#include "header.h"
void DrawGame(void)
{
    BeginDrawing();
    ClearBackground(WHITE);
    switch (currentScreen)
    {
    case LOGO:
    {
        // TODO: Draw LOGO screen here!
        DrawText("Mr. P entertainment", 160, 200, 40, BLACK);
    }
    break;

    case HIST1:
    {
        // TODO: Draw LOGO screen here!
        DrawText("Em uma galáxia TOTALMENTE distante, jovens, iniciantes na área", 40, 0, 20, BLACK);
        DrawText("jovens, iniciantes na área de programação,", 160, 40, 20, BLACK);
        DrawText("buscam incessantemente por conhecimento divino", 140, 80, 20, BLACK);
        DrawText("sobre as mais variáveis linguagens.", 220, 120, 20, BLACK);
        DrawText("Entretato..., ", 320, 160, 20, BLACK);
        DrawText("eles não contavam com os obstáculos que apreceriam no caminho.", 60, 200, 20, BLACK);
        DrawText("Criaturas bizzaras como o PORTUGOL,", 190, 240, 20, BLACK);
        DrawText("ou altamente complicadas de entender,", 190, 280, 20, BLACK);
        DrawText("como o arquivo binário, parecem brotar do canto da tela", 100, 320, 20, BLACK);
        DrawText("com objetivo de anaquilar esses estudantes ", 180, 360, 20, BLACK);
        DrawText(" '-' ( ou nou!!)", 310, 400, 20, BLACK);
    }
    break;

    case HIST2:
    {
        // TODO: Draw LOGO screen here!
        DrawText("Então, montados em sua nave EL RATON,", 180, 140, 20, BLACK);
        DrawText("os gênios da programação irão enfrentar tais criaturas,", 120, 180, 20, BLACK);
        DrawText(" passando por diversas ondas de inimigos, almejando", 120, 220, 20, BLACK);
        DrawText("unicamente o conhecimento ABSOLUTO!!!", 180, 260, 20, BLACK);
    }
    break;

    case TITLE:
    {
        // TODO: Draw TITLE screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
        DrawText("Pressione ENTER para iniciar", 200, 150, 30, BLACK);
        DrawText("Pressione R para ver o ranking", 210, 180, 25, BLACK);
        DrawText("Jogo criado por:\nJosé Queiroz\nJoão Bizinelli\nAllan Moreira", 220, 350, 15, GRAY);
    }
    break;
    case RANKING:
    {
        // TODO: Draw TITLE screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
        DrawText("RANKING", 120, 20, 50, DARKGREEN);
        DrawText("Aperte ENTER para iniciar o jogo", 120, 390, 15, DARKGREEN);
        DrawText("Aperte R para voltar ao menu iniciar", 120, 420, 15, DARKGREEN);
    }
    break;
    case GAMEPLAY:
    {
        if (!gameOver)
        {
            DrawTexture(background.texture_back, background.position_x, background.position_y, RAYWHITE);
            // DrawRectangleRec(player.rec, player.color);
            DrawTexture(player.scarfy, player.rec.x - 10, player.rec.y - 12, RAYWHITE);
            // UnloadTexture(player.scarfy);

            if (wave == FIRST)
                DrawText("FIRST WAVE", screenWidth / 2 - MeasureText("FIRST WAVE", 40) / 2, screenHeight / 2 - 40, 40, Fade(WHITE, alpha));
            else if (wave == SECOND)
                DrawText("SECOND WAVE", screenWidth / 2 - MeasureText("SECOND WAVE", 40) / 2, screenHeight / 2 - 40, 40, Fade(WHITE, alpha));
            else if (wave == THIRD)
                DrawText("THIRD WAVE", screenWidth / 2 - MeasureText("THIRD WAVE", 40) / 2, screenHeight / 2 - 40, 40, Fade(WHITE, alpha));

            for (int i = 0; i < activeEnemies; i++)
            {
                if (enemy[i].active)
                {
                    // DrawRectangleRec(enemy[i].rec, enemy[i].color);
                    DrawTexture(*enemy[i].realTextureEnemy, enemy[i].rec.x, enemy[i].rec.y - 42, RAYWHITE);
                }
            }

            for (int i = 0; i < NUM_SHOOTS; i++)
            {
                if (shoot[i].active)
                    DrawRectangleRec(shoot[i].rec, shoot[i].color);
            }

            DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);

            if (victory)
                DrawText("YOU WIN", screenWidth / 2 - MeasureText("YOU WIN", 40) / 2, screenHeight / 2 - 40, 40, BLACK);

            if (pause)
                DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
        }
        else
        {

            DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);
        }
    }
    break;
    default:
        break;
    }
    EndDrawing();
}