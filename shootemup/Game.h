#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


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

        bool running(){ return m_bRunning; }
    private: 
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        SDL_Texture* m_pTexture; // the new SDL texture variable, basically for images
        SDL_Rect m_sourceRectangle; //the first rectangle
        SDL_Rect m_destinationRectangle; //the second rectangle
        bool m_bRunning;
};


#endif