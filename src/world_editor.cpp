#include "../include/World_Editor.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>

struct linePos{
    float x;
    float y;
};

World_Editor::World_Editor(sf::RenderWindow* rw){
//FIX: FLIP_AXIS_OF_GRID!!!

    active = 0;
    this->rw = rw;

    HLine = new sf::RectangleShape(sf::Vector2f(1, rw->getSize().y / 2));
    VLine = new sf::RectangleShape(sf::Vector2f(rw->getSize().x, 1));


    linePos horPos;
    horPos.x = HLine->getPosition().x;
    horPos.y = this->rw->getSize().y / 2;

    linePos verPos;
    verPos.x = VLine->getPosition().x;
    verPos.y = this->rw->getSize().y / 2;

    
    for(int i = 0; i <= rw->getSize().x / 16; i++){
        HLine = new sf::RectangleShape(sf::Vector2f(1, rw->getSize().y / 2));
        HLine->setFillColor(sf::Color::Black);
        horPos.x += 16;
        HLine->setPosition(sf::Vector2f(horPos.x, horPos.y));
        HorizontalGrid.push_back(HLine);

    }

    for(int i = 0; i <= rw->getSize().y  / 16; i++){
        VLine = new sf::RectangleShape(sf::Vector2f(rw->getSize().x, 1));
        VLine->setFillColor(sf::Color::Black);
        VLine->setPosition(sf::Vector2f(verPos.x, verPos.y));
        VerticalGrid.push_back(VLine);
        verPos.y += 16;

    }
}

void World_Editor::printEditor(){
    if (active) {
        for(int i = 0; i < HorizontalGrid.size(); i++){
            rw->draw(*HorizontalGrid[i]);
        }
        for(int i = 0; i < VerticalGrid.size(); i++){
            rw->draw(*VerticalGrid[i]);
        }
    }
}

void World_Editor::toggleEditor(){
    active =! active;
}

World_Editor::~World_Editor(){
    delete VLine;
    delete HLine;
}
    