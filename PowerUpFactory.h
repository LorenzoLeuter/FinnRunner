#ifndef FINNRUNNER_POWERUPFACTORY_H
#define FINNRUNNER_POWERUPFACTORY_H

#include "PowerUp.h"
#include <SFML/Graphics.hpp>

class PowerUpFactory {

public:
    PowerUpFactory(int obj, float X);

    virtual ~PowerUpFactory();

    sf::Sprite getPowerUpSprite(){
        return power_up;
    }

    int getObjType(){
        return obj_type;
    }

    void update();

    int setUpPowerUp(int currentPowerUp);

private:
    float positionX, positionY;
    float velocityX, velocityY;
    int obj_type;
    sf::IntRect rectSourceSprite_sword{32, 0, 32, 32};
    sf::Sprite power_up;
    sf::Texture texture;
    sf::Clock clock;
};


#endif //FINNRUNNER_POWERUPFACTORY_H