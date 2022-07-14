#pragma once

#include "Scene.hpp"
#include "../objects/sprites/RC_sprite.hpp"

#include "../include/SFML/Window.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <thread>

struct ObjectsInStartScene{
    RC_sprite spriteObj;
};

class Start_scene: public Scene{
    private:

    public:
        ObjectsInStartScene objects;
        explicit Start_scene(sf::RenderWindow* rw);
        void RC_SpriteAnimator();
        void draw();
        ~Start_scene();
};