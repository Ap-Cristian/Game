#include "../include/scenes/Test_scene.hpp"

Test_scene::Test_scene(sf::RenderWindow *rw) : Scene(rw), World_Editor(rw){
    refreshColor = sf::Color(135, 206, 235, 255);
    this->rw = rw;
    this->sceneView.setSize(rw->getSize().x/2,rw->getSize().y/2);
    this->sceneView.setCenter(rw->getSize().x/2,rw->getSize().y/2);

    // this->rw->setView(mainView); move this somwere else

}

void Test_scene::draw(){
    rw->setView(this->sceneView);
    printEditor();
}

Test_scene::~Test_scene(){
}