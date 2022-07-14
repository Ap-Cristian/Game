#pragma once

#include "../SFML/Audio.hpp"
#include "../SFML/Network.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../scenes/Start_scene.hpp"
#include "../scenes/Test_scene.hpp"
#include "../World_Editor.hpp"
#include "GameKeyHandler.hpp"

#include <thread>
#include <chrono>

enum sceneState{
    startscene,
    testscene
};

class Game
{
private:
    int zoom;
    sceneState currentScene;

    sf::RenderWindow *window;
    sf::Event windowEvent;
    
    GameKeyHandler mainHandler;

    Start_scene *ss;
    Test_scene *ts;
    
    
public:
    Game(/* args */);
    
    int windowInit();

    void variablesInit();
    void objectInit();
    void pollEvents();
    void gameLoop();
    void draw();

    sf::Vector2u getCenterOfWindow();
    sf::Color refreshColor;

    ~Game();
};