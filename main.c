#include "header.h"
#include "Initgame.c"
#include "Updategame.c"
#include "Drawgame.c"
#include "Unloadgame.c"

int main(){
    
     InitWindow(screenWidth, screenHeight, "TESTE");
     
     InitAudioDevice();              // Initialize audio device

    Music music = LoadMusicStream("resources/country.mp3");

    PlayMusicStream(music);
    
    float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]
   
    bool pause = false;             // Music playing paused


     GameScreen currentScreen = LOGO;

     // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {// Update
         UpdateMusicStream(music);   // Update music buffer with new stream data
         SetMusicVolume(music, 0.007f);                  
        // Pause/Resume music playing
        if (IsKeyPressed(KEY_P))
        {
            pause = !pause;

            if (pause) PauseMusicStream(music);
            else ResumeMusicStream(music);
        }

        // Get normalized time played for current music stream
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);

        if (timePlayed > 1.0f) timePlayed = 1.0f;   // Make sure time played is no longer than music
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 1)
                {
                    currentScreen = HIST1;
                }
            } break;
            case HIST1:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 1)
                {
                    currentScreen = HIST2;
                }
            } break;
            case HIST2:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 1)
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
                
                case HIST1:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("Em uma galáxia TOTALMENTE distante, jovens, iniciantes na área", 40, 0, 20, BLACK);
                    DrawText("jovens, iniciantes na área de programação,", 160, 40, 20, BLACK);
                    DrawText("buscam incessantemente por conhecimento divino", 140, 80, 20, BLACK);
                    DrawText("sobre as mais variáveis linguagens.", 220, 120, 20, BLACK);
                    DrawText("Entretato..., ", 320,160, 20, BLACK);
                    DrawText("eles não contavam com os obstáculos que apreceriam no caminho.", 60, 200, 20, BLACK);
                    DrawText("Criaturas bizzaras como o PORTUGOL,", 190, 240, 20, BLACK);
                    DrawText("ou altamente complicadas de entender,", 190, 280, 20, BLACK);
                    DrawText("como o arquivo binário, parecem brotar do canto da tela",100, 320, 20, BLACK);
                    DrawText("com objetivo de anaquilar esses estudantes ", 180, 360, 20, BLACK);
                    DrawText(" '-' ( ou nou!!)", 310, 400, 20, BLACK);
                     
                } break;
                 
                 case HIST2:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("Então, montados em sua nave EL RATON,", 180, 140, 20, BLACK);
                    DrawText("os gênios da programação irão enfrentar tais criaturas,", 120, 180, 20, BLACK); 
                    DrawText(" passando por diversas ondas de inimigos, almejando", 120, 220, 20, BLACK);
                    DrawText("unicamente o conhecimento ABSOLUTO!!!", 180,260, 20, BLACK);                      
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
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
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
