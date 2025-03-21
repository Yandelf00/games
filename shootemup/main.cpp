#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "main.h"



Game* g_game = 0;


int main(int argc, char *argv[])
{
    g_game = new Game();
    g_game->init("GameClass", 100, 100, 480, 640, 0);

    while(g_game->running())
    {
        g_game->handleEvent();
        g_game->update();
        g_game->render();

        SDL_Delay(10); // add the delay
    }
    g_game->clean();
    
    return 0;
}

