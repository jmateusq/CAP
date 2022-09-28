#include "header.h"
#include "Initgame.c"
#include "Updategame.c"
#include "Drawgame.c"
#include "Unloadgame.c"


int main(){
    
     InitWindow(screenWidth, screenHeight, "TESTE");

     GameScreen currentScreen = LOGO;

     // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {// Update
        
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER)) //iniciar
                {
                    currentScreen = GAMEPLAY;
                    InitGame();
                }
                if (IsKeyPressed('R')) //ranking
                {
                    currentScreen = RANKING;
                }
            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!
                UpdateGame();
                // Press P to pause
                if (IsKeyPressed('X'))
                {
                    currentScreen = TITLE;
                }
            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = TITLE;
                }
            } break;
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
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {
                case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("Mr. P entertainment", 160, 200, 40, BLACK);

                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                    DrawText("Pressione ENTER para iniciar", 200, 150, 30, BLACK);
                    DrawText("Pressione R para ver o ranking", 210, 180, 25, BLACK);
                    DrawText("Jogo criado por:\nJosé Queiroz\nJoão Bizinelli\nAllan Moreira", 220, 350, 15, GRAY);

                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                    DrawText("Pressione ENTER para voltar a tela inicial", 120, 220, 20, DARKBLUE);

                } break;
                case GAMEPLAY:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                    DrawGame();

                } break;
                case RANKING:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                    DrawText("RANKING", 120, 20, 50, DARKGREEN);
                    DrawText("Aperte ENTER para iniciar o jogo", 120, 390, 15, DARKGREEN);
                    DrawText("Aperte R para voltar ao menu iniciar", 120, 420, 15, DARKGREEN);

                } break;
                default: break;
            }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    UnloadGame(); 
    CloseWindow(); 
    return 0;
}
