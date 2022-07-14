#include "../include/game/GameKeyHandler.hpp"
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <SFML/System/Thread.hpp>

void GameKeyHandler::handle(sf::Event event, sf::RenderWindow* rw){
    switch (event.key.code) {
    case sf::Keyboard::F11:
        if(isWindowFullscreen == false){
            delete rw;
            rw = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0],"GAME WINDOW",sf::Style::Fullscreen);
            isWindowFullscreen = true;
        }
        else{
            delete rw;
            rw = new sf::RenderWindow(sf::VideoMode(800,600,32U),"GAME WINDOW",sf::Style::Default);
            isWindowFullscreen = false;
        }
    break;
    }
}

GameKeyHandler::GameKeyHandler(){
    isWindowFullscreen = 0;

}
GameKeyHandler::~GameKeyHandler(){

}