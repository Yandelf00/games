#include <SDL2/SDL.h>
#include <iostream>
#include "main.h"


bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    

}


int main(int argc, char *argv[])
{
    App app;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Couldn't initialize SDL. Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    app.window = SDL_CreateWindow("SDL2 Blue Background", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (app.window == nullptr) {
        std::cout << "Window could not be created. Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    if (app.renderer == nullptr) {
        std::cout << "Renderer could not be created. Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        return 1;
    }

    // Main loop
    bool running = true;
    SDL_Event event;
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen with a blue color
        SDL_SetRenderDrawColor(app.renderer, 0, 0, 255, 255); // Blue color (R=0, G=0, B=255, A=255)
        SDL_RenderClear(app.renderer);

        // Update the screen
        SDL_RenderPresent(app.renderer);

        // Add a small delay to reduce CPU usage
        SDL_Delay(16); // ~60 FPS
    }

    // Clean up
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();

    return 0;
}