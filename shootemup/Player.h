#ifndef __PLAYER__
#define __PLAYER__

#include "GameObject.h"

class Player : public GameObject //inherents from GameObject
{
    public : 
        void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* p_Renderer);
        void update(); 
        void clean();
};

#endif