#ifndef __GameObject__
#define __GameObject__

#include <iostream>

class GameObject
{
    public:
        void draw(){std::cout << "draw game object";}
        void update(){std::cout << "update game object";}
        void clean(){std::cout << "clean game object";}
    
    protected:
        int my_x;
        int my_y;
};


class Player : public GameObject //inherents from GameObject
{
    public : 
        void draw()
        {
            GameObject::draw();
            std::cout<<"draw player";
        }

        void update()
        {
            std::cout<<"update player";
            my_x = 10;
            my_y = 20;
        }
        
        void clean()
        {
            GameObject::clean();
            std::cout<<"clean player";
        }
};

#endif
