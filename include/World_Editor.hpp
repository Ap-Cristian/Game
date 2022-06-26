#include "SFML/Graphics.hpp"
#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>

class World_Editor{
    private:
        bool active;
        sf::RectangleShape VLine;
        sf::RectangleShape HLine;

        std::vector<sf::RectangleShape> verticalGrid;
        std::vector<sf::RectangleShape> HorizontalGrid;

    public:
        World_Editor(sf::Vector2f scrreen = sf::Vector2f(800,600));
        ~World_Editor();

};