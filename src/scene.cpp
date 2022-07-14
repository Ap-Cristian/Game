#include "../include/scenes/Scene.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

int Scene::numberOfScenes = 0;

Scene::Scene(sf::RenderWindow* rw){
    this->rw = rw;
    numberOfScenes++;
    currentScene = 0;
}

void Scene::setCurrentScene(bool value){
    currentScene = value;
}

bool Scene::isCurrentScene(){
    return this->currentScene;
}

void Scene::pushObjectInObjectsVector (Object obj){
    // switch (obj.objT) {
    //     case staticObject:
    //         objectsInScene.addStaticObj(obj);
    //         break;
    //     case triggerObject:
    //         //
    //         break;
    //     case dynamicObject:
    //         //
    //         break;
    //     default:
    //     break;
    // }
}

void Scene::updateViewSize(){
    sceneView.setSize(rw->getSize().x,rw->getSize().y);
}

void Scene::getObjectsInScene (){
    // return this->objectsInScene;
}

Scene::~Scene(){

}