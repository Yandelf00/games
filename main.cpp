#include <SDL2/SDL.h>
#include <iostream>

// const int WIDTH = 800;
// const int HEIGHT = 600;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{

    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        g_pWindow = SDL_CreateWindow("Chapter 1 : Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

        if(g_pWindow != 0){
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }
    else
    {
        return 1;
    }
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    SDL_RenderClear(g_pRenderer);

    SDL_RenderPresent(g_pRenderer);

    SDL_Delay(5000);

    SDL_Quit();

    return 0;

    // SDL_Window* window = nullptr;
    // SDL_Renderer* renderer = nullptr;

    // // Initialize SDL
    // if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    //     std::cout << "Couldn't initialize SDL. Error: " << SDL_GetError() << std::endl;
    //     return 1;
    // }

    // // Create a window
    // window = SDL_CreateWindow("SDL2 Blue Background", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    // if (window == nullptr) {
    //     std::cout << "Window could not be created. Error: " << SDL_GetError() << std::endl;
    //     SDL_Quit();
    //     return 1;
    // }

    // // Create a renderer
    // renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // if (renderer == nullptr) {
    //     std::cout << "Renderer could not be created. Error: " << SDL_GetError() << std::endl;
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return 1;
    // }

    // // Main loop
    // bool running = true;
    // SDL_Event event;
    // while (running) {
    //     // Handle events
    //     while (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_QUIT) {
    //             running = false;
    //         }
    //     }

    //     // Clear the screen with a blue color
    //     SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color (R=0, G=0, B=255, A=255)
    //     SDL_RenderClear(renderer);

    //     // Update the screen
    //     SDL_RenderPresent(renderer);

    //     // Add a small delay to reduce CPU usage
    //     SDL_Delay(16); // ~60 FPS
    // }

    // // Clean up
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    // return 0;
}