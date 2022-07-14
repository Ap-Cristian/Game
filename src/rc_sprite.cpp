#include "../include/objects/sprites/RC_sprite.hpp"

#include <thread>
#include <chrono>

#define pngPath "../texture/rc/rc_fin.png"

#define fadeIn 0
#define fadeWait 1
#define fadeOut 2
#define fadeExit -1

RC_sprite::RC_sprite(sf::Vector2f position)
{
    alpha = 0;
    fadeState = 0;

    setSpriteTexture();
    std::cout<<"StartupSpriteSize: "<< startupSprite.getTexture()->getSize().x<< " , "<< startupSprite.getTexture()->getSize().y <<"\n";
    startupSprite.setOrigin(startupSprite.getOrigin().x + textureImage.getSize().x / 2, startupSprite.getOrigin().y + textureImage.getSize().y / 2);
    startupSprite.setPosition(position);

    objT = staticObject;
    objectName = "Startup animated logo";
}

void RC_sprite::setSpriteTexture()
{
    textureImage.loadFromFile(pngPath);
    spriteTexture.loadFromImage(textureImage);
    this->startupSprite.setTexture(spriteTexture);
    startupSprite.setScale(sf::Vector2f(3.6f, 3.6f));
}

void RC_sprite::setPosition(sf::Vector2f position)
{
    startupSprite.setPosition(position);
}

void RC_sprite::fadeAnimation()
{
    switch (fadeState)
    {
    case fadeIn:
        if (alpha >= 255)
        {
            fadeState = fadeWait;
            alpha -= 7;

            break;
        }

        startupSprite.setColor(sf::Color(255, 255, 255, alpha));
        alpha += 7;

        break;

    case fadeWait:
        std::this_thread::sleep_for(std::chrono::seconds(1));

        fadeState = fadeOut;
        break;
    
    case fadeOut:

        if (alpha <= 0)
        {
            fadeState = fadeExit;
            alpha = 0;

            break;
        }
        alpha -= 7;
        startupSprite.setColor(sf::Color(255, 255, 255, alpha));
        break;
        
    default:

        break;
    }
}

int RC_sprite::getFadeState(){
    return fadeState;
}

sf::Sprite RC_sprite::getSprite()
{
    if(fadeState != fadeExit)
        fadeAnimation();
    return startupSprite;
}

RC_sprite::~RC_sprite()
{

}