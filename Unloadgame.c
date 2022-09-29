#include "header.h"
void UnloadGame(void)
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
    UnloadTexture(player.scarfy);
    UnloadTexture(background.texture_back);
    UnloadTexture(enemywave1[0].wave1);
    UnloadTexture(enemywave1[1].wave1);
    UnloadTexture(enemywave1[2].wave1);
    UnloadTexture(enemywave1[3].wave1);
    UnloadTexture(enemywave2[0].wave2);
    UnloadTexture(enemywave2[1].wave2);
    UnloadTexture(enemywave2[2].wave2);
    UnloadTexture(enemywave2[3].wave2);
    UnloadTexture(enemywave3[0].wave3);
    UnloadTexture(enemywave3[1].wave3);
    UnloadTexture(enemywave3[2].wave3);
    UnloadTexture(enemywave3[3].wave3);
}
