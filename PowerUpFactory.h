#ifndef FINNRUNNER_POWERUPFACTORY_H
#define FINNRUNNER_POWERUPFACTORY_H

#include "PowerUp.h"
#include <SFML/Graphics.hpp>

enum powerUps {
    sword, speedskip, freeze
};

class PowerUpFactory {

public:
    PowerUpFactory(int obj);

    virtual ~PowerUpFactory();

    sf::Sprite getPowerUpSprite(){
        return power_up;
    }

    void update();

    int setUpPowerUp(int currentPowerUp);

private:
    float positionX, positionY;
    float velocityX, velocityY;
    sf::Sprite power_up;
    sf::Texture texture;
    sf::Clock clock;
};


#endif //FINNRUNNER_POWERUPFACTORY_H