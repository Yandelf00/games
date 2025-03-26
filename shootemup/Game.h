#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"


class  Game
{
    public: 
        Game(){}
        ~Game(){}
        bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
        void render();
        void update();
        void handleEvent();
        void clean();
        // void draw();

        bool running(){ return m_bRunning; }
    private: 
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        // SDL_Texture* m_pTexture; // the new SDL texture variable, basically for images
        // SDL_Rect m_sourceRectangle; //the first rectangle
        // SDL_Rect m_destinationRectangle; //the second rectangle
        int m_currentFrame;
        bool m_bRunning;

        GameObject* m_go;
        GameObject* m_player;
        GameObject* m_enemy;
        std::vector<GameObject *> m_gameObjects;
        // GameObject* m_player;
        // GameObject* m_enemy1;
        // GameObject* m_enemy2;
        // GameObject* m_enemy3;
};


#endif