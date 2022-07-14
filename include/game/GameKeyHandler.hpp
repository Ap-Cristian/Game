#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

// namespace KeyHandler{
//     void handle(sf::Event event,sf::RenderWindow* rw);


// };

class GameKeyHandler{
    private:
        // sf::Event/
        bool isWindowFullscreen;
    public:
        GameKeyHandler();
        void handle(sf::Event event,sf::RenderWindow* rw);
        ~GameKeyHandler();
};