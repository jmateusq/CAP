#include "header.h"
#include "Initgame.c"
#include "Updategame.c"
#include "Drawgame.c"
#include "Unloadgame.c"
#include "textinho.c"

int main(void)
{
    // Inicialização 
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "classic game: space invaders");

    InitGame();
    
    InitAudioDevice();             

    Music music = LoadMusicStream("country.mp3");

    PlayMusicStream(music);
    SetMusicVolume(music, 0.01f);

    float timePlayed = 0.0f;       
    bool pause = false;             


    SetTargetFPS(60);

    // Inicializa arquivo
    FILE *f;
    f = fopen("ranking.bin","r+b");
    
    fread(&pontos,sizeof(mitinho),10,f);

    //--------------------------------------------------------------------------------------

    while (!WindowShouldClose())    
    {
    
        UpdateMusicStream(music);  

        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);

        if (timePlayed > 1.0f) timePlayed = 1.0f;   
        
        UpdateGame(f);
        DrawGame();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();        
    
    UnloadMusicStream(music);  

    CloseAudioDevice();         

    CloseWindow();        
    //--------------------------------------------------------------------------------------

    fclose(f);
    return 0;
}
