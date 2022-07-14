#include "Scene.hpp"

#include "../World_Editor.hpp"
struct objects{
    
};

class Test_scene: public Scene, public World_Editor{
    private:
        sf::RenderWindow* rw;

    public:
        explicit Test_scene(sf::RenderWindow* rw);
        void draw();
        ~Test_scene();
};