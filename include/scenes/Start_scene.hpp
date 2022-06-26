#pragma once

#include "Scene.hpp"
#include "../objects/sprites/RC_sprite.hpp"

#include "../include/SFML/Window.hpp"

#include <thread>

struct ObjectsInStartScene{
    RC_sprite spriteObj;
};

class Start_scene: public Scene{
    private:

    public:
        ObjectsInStartScene objects;
        Start_scene();
        void RC_SpriteAnimator();
        void draw(sf::RenderWindow *window);
        ~Start_scene();
};