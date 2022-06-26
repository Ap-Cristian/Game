#include "../include/World_Editor.hpp"
#include <SFML/System/Vector2.hpp>

World_Editor::World_Editor(sf::Vector2f screen){
    VLine = sf::RectangleShape(sf::Vector2f(5, screen.y));
    HLine = sf::RectangleShape(sf::Vector2f(screen.x, 5));

    VLine.setFillColor(sf::Color::White);
    HLine.setFillColor(sf::Color::White);

    
}