#pragma once
#include "../../SFML/Graphics.hpp"
#include "../SFML/System.hpp"


#include <string.h>
#include <iostream>


enum objectType {
        staticObject,
        triggerObject,
        dynamicObject
};

class Object
{
public:
    std::string objectName;
    objectType objT;

    sf::Sprite startupSprite;
    sf::Image textureImage;
    sf::RectangleShape objectAsShape;
    sf::Texture spriteTexture;

    Object();
    Object(sf::Sprite obj_sprite);
    Object(sf::RectangleShape obj_shape);

    ~Object();
};



