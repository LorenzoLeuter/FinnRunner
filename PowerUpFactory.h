#ifndef FINNRUNNER_POWERUPFACTORY_H
#define FINNRUNNER_POWERUPFACTORY_H

#include "PowerUp.h"
#include <SFML/Graphics.hpp>

class PowerUpFactory {

public:
    PowerUpFactory(float X);

    virtual ~PowerUpFactory();

    sf::Sprite getPowerUpSprite(){
        return power_up;
    }

    void setTexture(const sf::Texture &texture,const PowerUp &pUp);

    void setPositionX(float positionX);

    void setVelocityX(float velocityX);

    void update();

    void updateCollect();

private:
    float positionX, positionY;
    float velocityX;
    sf::Sprite power_up;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect rectSourceSprite_sword{32, 0, 32, 32};
    sf::IntRect rectSourceSprite_potion{0, 0, 32, 32};
};


#endif //FINNRUNNER_POWERUPFACTORY_H