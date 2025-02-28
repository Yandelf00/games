#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class TextureManager
{
    public : 
        static TextureManager* Instance();

        bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

        //the draw function is for an entire image 
        void draw(std::string id, int x, int y, int width, int height, 
        SDL_Renderer* pRenderer, SDL_RendererFlip flip=SDL_FLIP_NONE);

        //draw frame is just for a frame on a spritesheet
        void drawFrame(std::string id, int x, int y, int width, int
        height, int currentRow, int currentFrame, SDL_Renderer*
        pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    private :
        TextureManager(){}
        ~TextureManager(){}
        static TextureManager* s_pInstance;
        std::map<std::string, SDL_Texture*> m_textureMap;
};  

typedef TextureManager TheTextureManager;

#endif