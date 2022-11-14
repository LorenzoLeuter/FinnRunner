#include "PowerUpFactory.h"

PowerUpFactory::PowerUpFactory(int obj) : positionX(400), positionY(525), velocityX(0.0030){
    switch(obj){
        case 1: //sword
            texture.loadFromFile("assets/sword.png");
            break;
    }
    power_up.setTexture(texture);
    power_up.scale(2.5, 2.5);
    power_up.setPosition(positionX,positionY);
}

void PowerUpFactory::update() {
    positionX -= velocityX * clock.getElapsedTime().asSeconds();

    power_up.setPosition(positionX, positionY);
}


PowerUpFactory::~PowerUpFactory() {

}

int PowerUpFactory::setUpPowerUp(int currentPowerUp) {
    return 0;
}