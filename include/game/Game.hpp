#pragma once

#include "../SFML/Audio.hpp"
#include "../SFML/Network.hpp"

#include "../scenes/Start_scene.hpp"
#include "../scenes/Test_scene.hpp"

enum sceneState{
    startscene,
    testscene
};

class Game
{
private:
    sceneState currentScene;

    sf::RenderWindow *window;
    sf::Event windowEvent;
    
    Start_scene ss;
    Test_scene ts;
    
public:
    Game(/* args */);
    
    int windowInit();

    void initVariables();
    void objectInit();
    void pollEvents();
    void gameLoop();
    void draw();

    sf::Vector2u getCenterOfWindow();
    sf::Color refreshColor;

    ~Game();
};