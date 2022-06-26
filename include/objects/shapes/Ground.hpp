#include "../Object.hpp"

class Ground: public Object{
    public:

    private:
        sf::RectangleShape tile;
        sf::Texture tileTexture;
        sf::Image tileImageTexture;
};