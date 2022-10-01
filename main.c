#include "header.h"
#include "Initgame.c"
#include "Updategame.c"
#include "Drawgame.c"
#include "Unloadgame.c"
#include "textinho.c"

int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "classic game: space invaders");

    InitGame();
    
    InitAudioDevice();              // Initialize audio device

    Music music = LoadMusicStream("./sounds/music.mp3");

    PlayMusicStream(music);
    SetMusicVolume(music, 0.03f);

    float timePlayed = 0.0f;        // Time played normalized
    bool pause = false;             // Music playing paused


    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Initialization file
    FILE *f;
    f = fopen("ranking.bin","r+b");
    
    fread(&pontos,sizeof(mitinho),10,f);

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateMusicStream(music);   // Update music 
        SetMusicVolume(music, 0.05f);

        // Get normalized time played for current music stream
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);

        if (timePlayed > 1.0f) timePlayed = 1.0f;   // Make sure time played is no longer than music
        
        UpdateGame(f);
        DrawGame();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)
    
    UnloadMusicStream(music);   // Unload music stream buffers from RAM

    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    fclose(f);
    return 0;
}
