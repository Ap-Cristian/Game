#pragma once
#include "../objects/Objects.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
private:
    static int numberOfScenes;
    static std::string sceneName;
    bool currentScene;
    std::vector<Object> objectsToRender;
public:
    sf::RenderWindow* rw;

    explicit Scene(sf::RenderWindow* rw);
    sf::View sceneView;
    sf::Color refreshColor;
    
    void pushObjectInObjectsVector(Object obj);
    void getObjectsInScene();

    void setCurrentScene(bool value);
    bool isCurrentScene();
    
    void updateViewSize();
    ~Scene();
};