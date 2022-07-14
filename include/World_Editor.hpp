#include "SFML/Graphics.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>

class World_Editor{
    private:
        sf::RenderWindow* rw;

        bool active;
        sf::RectangleShape *VLine;
        sf::RectangleShape *HLine;

        std::vector<sf::RectangleShape*> VerticalGrid;
        std::vector<sf::RectangleShape*> HorizontalGrid;

    public:
        World_Editor(sf::RenderWindow* rw);
        World_Editor();
        void toggleEditor();
        void printEditor();
        ~World_Editor();

};