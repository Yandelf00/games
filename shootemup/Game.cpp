#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
    //attempt to initialize SDL
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(m_pWindow!=0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0)
            {
                m_player = new Player();
                m_enemy1 = new Enemy();
                m_enemy2 = new Enemy();
                m_enemy3 = new Enemy();
                
                m_go.load(100, 100, 128, 82, "animate");
                m_player.load(300, 300, 128, 82, "animate");

                TheTextureManager::Instance()->load("assets/_Attack.png", "animate", m_pRenderer);
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
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
    // SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    // SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    // TheTextureManager::Instance()->drawFrame("animate",100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    m_go.draw(m_pRenderer);
    m_player.draw(m_pRenderer);
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
//    m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    m_go.update();
    m_player.update();
}