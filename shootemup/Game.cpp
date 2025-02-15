#include "Game.h"


bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
    //attempt to initialize SDL
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
        if(m_pWindow!=0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0)
            {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }
            else
            {
                //renderer init fail
                return false;
            }
        }
        else
        {
            //window init fail
            return false;
        }
    }
    else 
    {
        //sdl init fail
        return false;
    }
    m_bRunning = true;
    return true;
}

void Game::render(){
    SDL_RenderClear(m_pRenderer); //clear the renderer and draw color
    SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::handleEvent()
{
   SDL_Event event; 
   if(SDL_PollEvent(&event))
   {
        switch(event.type)
        {
            case SDL_QUIT :
                m_bRunning = false;
            break;
            default : 
            break;
        }
   }
}


void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::update()
{

}