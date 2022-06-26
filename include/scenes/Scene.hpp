#pragma once
#include "../objects/Objects.hpp"

class Scene
{
private:

    static int numberOfScenes;
    static std::string sceneName;
    std::vector<Object> objectsToRender;
    
public:
    Scene();
    sf::Color refreshColor;
    
    void pushObjectInObjectsVector(Object obj);
    void getObjectsInScene();
    ~Scene();
};