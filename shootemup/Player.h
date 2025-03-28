#ifndef __PLAYER__
#define __PLAYER__

#include "GameObject.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Player : public SDLGameObject //inherents from GameObject
{
    public : 

        Player(const LoaderParams* pParams);
        virtual void draw();
        virtual void update();
        virtual void clean();
};

#endif