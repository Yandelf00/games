#include "Game.h"
#include <iostream>

Game* Game::s_pInstance = 0;

Game* Game::Instance()
{
    if(s_pInstance == 0)
    {
        s_pInstance = new Game();
        return s_pInstance;
    }
    return s_pInstance;

}

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
                m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,
                "animate")));
                m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82,
                "animate")));

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
    for(std::vector<GameObject*>::size_type i = 0; i !=
    m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
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

// void Game::draw()
// {
//     for(std::vector<GameObject*>::size_type i = 0; i !=
//     m_gameObjects.size(); i++)
//     {
//         m_gameObjects[i]->draw(m_pRenderer);
//     }
// }


void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::update()
{
//  m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    for(std::vector<GameObject*>::size_type i = 0; i !=
    m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}
