#include "header.h"

void DrawGame(void)
{

        if (!gameOver)
        {
            DrawTexture(background.texture_back, background.position_x, background.position_y, RAYWHITE);
            //DrawRectangleRec(player.rec, player.color);
            DrawTexture(player.scarfy, player.rec.x - 10, player.rec.y - 12, RAYWHITE);
            //UnloadTexture(player.scarfy);

            if (wave == FIRST) DrawText("FIRST WAVE", screenWidth/2 - MeasureText("FIRST WAVE", 40)/2, screenHeight/2 - 40, 40, Fade(WHITE, alpha));
            else if (wave == SECOND) DrawText("SECOND WAVE", screenWidth/2 - MeasureText("SECOND WAVE", 40)/2, screenHeight/2 - 40, 40, Fade(WHITE, alpha));
            else if (wave == THIRD) DrawText("THIRD WAVE", screenWidth/2 - MeasureText("THIRD WAVE", 40)/2, screenHeight/2 - 40, 40, Fade(WHITE, alpha));

            for (int i = 0; i < activeEnemies; i++)
            {
                if (enemy[i].active){
                    //DrawRectangleRec(enemy[i].rec, enemy[i].color);
                    DrawTexture(*enemy[i].realTextureEnemy, enemy[i].rec.x, enemy[i].rec.y -40, RAYWHITE);
                }
            }

            for (int i = 0; i < NUM_SHOOTS; i++)
            {
                if (shoot[i].active) DrawRectangleRec(shoot[i].rec, shoot[i].color);
            }

            DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);

            if (victory) DrawText("YOU WIN", screenWidth/2 - MeasureText("YOU WIN", 40)/2, screenHeight/2 - 40, 40, BLACK);

            if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
        }
        else{
            
            DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);
            
        }
}
