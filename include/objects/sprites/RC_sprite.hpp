
#include "../Object.hpp"

class RC_sprite: public Object
{
private:
    int alpha;
    int fadeState;


public:
    RC_sprite(sf::Vector2f position = sf::Vector2f(0,0));
    sf::Sprite getSprite();

    void setSpriteTexture();
    void setPosition(sf::Vector2f position);
    void fadeAnimation();
    
    int getFadeState();
    ~RC_sprite();
};