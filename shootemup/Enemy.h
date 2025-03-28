#ifndef __ENEMY__
#define __ENEMY__

#include "GameObject.h"
#include "SDLGameObject.h"
#include <SDL2/SDL.h>

class Enemy : public SDLGameObject //inherents from GameObject
{
    public : 
        Enemy(const LoaderParams* pParams);
        virtual void draw();
        virtual void update();
        virtual void clean();
};

#endif