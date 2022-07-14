#include "../include/scenes/Start_scene.hpp"
#include "../include/scenes/Scene.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

std::string Scene::sceneName = "Startup Scene";

Start_scene::Start_scene(sf::RenderWindow* rw) : Scene(rw){
    // pushObjectInObjectsVector(spriteObj);g
    refreshColor = sf::Color::Black;
    
    this->rw = rw;
    this->sceneView.setSize(rw->getSize().x,rw->getSize().y);
    this->sceneView.setCenter(rw->getSize().x/2,rw->getSize().y/2);
}

void Start_scene::RC_SpriteAnimator(){
    while(objects.spriteObj.getFadeState() != -1)
        objects.spriteObj.fadeAnimation();
}

void Start_scene::draw(){
    this->rw->setView(sceneView);
    this->rw->draw(objects.spriteObj.getSprite());
}

Start_scene::~Start_scene(){

}