#include "../include/game/Game.hpp"

//Constructor
Game::Game(){
    variablesInit();
    windowInit();    
    objectInit();
    gameLoop();
}

//Function
void Game::variablesInit(){
    this->window = nullptr;

}

void Game::objectInit(){
    // sUp.setPosition((sf::Vector2f)getCenterOfWindow());
    ss = new Start_scene(window);
    ss->objects.spriteObj.setPosition((sf::Vector2f)getCenterOfWindow());
    currentScene = startscene;

    ts = new Test_scene(window);
    ts->toggleEditor(); //TOGGLE ON
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

        case sf::Event::EventType::KeyPressed:
            mainHandler.handle(this->windowEvent, this->window);
            break;
        
        default:

            break;
        }
    }
}

void Game::draw(){
    //TO DO:
    //core dumped if windowMode is changed consecutively
    //figure out keyHandling
    //make world editor not look retarded
    //maybe work on adding actual tiles to world editor

    
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    switch (currentScene) {
        case startscene:
            if(ss->objects.spriteObj.getFadeState() != -1){
                ss->setCurrentScene(true);
                ss->updateViewSize();
                ss->draw();
                refreshColor = ss->refreshColor;
            }
            else{
                ss->setCurrentScene(false);
                currentScene = testscene;
            }
            
            break;

        case testscene:
            ts->setCurrentScene(true);
            ts->draw();
            refreshColor = ts->refreshColor;
            
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
    delete this->ts;
}