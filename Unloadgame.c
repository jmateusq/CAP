#include "header.h"
void UnloadGame(void)
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
    UnloadTexture(player.scarfy);
    UnloadTexture(background.texture_back);
    UnloadTexture(enemyTexture[0].textureEnemy);
    UnloadTexture(enemyTexture[1].textureEnemy);
    UnloadTexture(enemyTexture[2].textureEnemy);
    UnloadTexture(enemyTexture[3].textureEnemy);
}