#include <SDL2/SDL.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_image.h>
#include "../include/game.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

inline void init();
inline void GameLoop();
inline void close();

int main(int argc , char * argv[])
{
    init();
    GameLoop();
    close();

    return 0;
}

inline void init(){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG); 
}

inline void GameLoop()
{
    Candy::Game Game("Chess",WINDOW_WIDTH,WINDOW_HEIGHT);
    while (Game.isRunning())
    {
        Game.pollEvent();
        Game.update();
        Game.render();
    }
}

inline void close()
{
    SDL_Quit();
    IMG_Quit();
}
