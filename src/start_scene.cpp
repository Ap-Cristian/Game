#include "../include/scenes/Start_scene.hpp"
#include "../include/scenes/Scene.hpp"

std::string Scene::sceneName = "Startup Scene";

Start_scene::Start_scene(){
    // pushObjectInObjectsVector(spriteObj);g
    refreshColor = sf::Color::Black;
}

void Start_scene::RC_SpriteAnimator(){
    while(objects.spriteObj.getFadeState() != -1)
        objects.spriteObj.fadeAnimation();
}

void Start_scene::draw(sf::RenderWindow *window){
    window->draw(objects.spriteObj.getSprite());
}

Start_scene::~Start_scene(){

}