#include "../include/game/Game.hpp"

#include <thread>
#include <chrono>

//Constructor
Game::Game(){

    initVariables();
    windowInit();    
    objectInit();
    gameLoop();
}

//Function
void Game::initVariables(){
    this->window = nullptr;
}

void Game::objectInit(){
    // sUp.setPosition((sf::Vector2f)getCenterOfWindow());
    ss.objects.spriteObj.setPosition((sf::Vector2f)getCenterOfWindow());
    currentScene = startscene;
}

int Game::windowInit(){
    this->window = new sf::RenderWindow(sf::VideoMode(1200,800,32U), "TITLE");
    if(this->window->isOpen()){
        return 0;
    }
    return -1;
}

void Game::pollEvents(){
    while(this->window->pollEvent(this->windowEvent)){
        switch (this->windowEvent.type)
        {
        case sf::Event::EventType::Closed:
            this->window->close();
            break;
        
        default:

            break;
        }
    }
}

void Game::draw(){
    //TO DO:
    //make drawables data structure
    //pop startup logo after animation has ended
    
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    switch (currentScene) {
        case startscene:
            if(ss.objects.spriteObj.getFadeState() != -1){
                ss.draw(this->window);
                refreshColor = ss.refreshColor;
            }
            else{
                currentScene = testscene;
            }
            break;

        case testscene:
            refreshColor = ts.refreshColor;
            break;
            
    }

    
    this->window->display();
    this->window->clear(refreshColor);
    refreshColor = sf::Color::Black;
}

void Game::gameLoop(){
    while(this->window->isOpen()){
        //events
        pollEvents();

        //draw
        draw();

        //...
    }
}

sf::Vector2u Game::getCenterOfWindow(){
    sf::Vector2u windowSize;
    windowSize = this->window->getSize();
    return sf::Vector2u(windowSize.x / 2, windowSize.y / 2);
}

//Destructor
Game::~Game(){
    delete this->window; 
}