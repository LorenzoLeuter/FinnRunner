#include "PowerUpFactory.h"

PowerUpFactory::PowerUpFactory(int obj, float X) : positionX(X), velocityX(0.0030){
    switch(obj){
        case 1: //sword
            texture.loadFromFile("assets/sword_sprite.png");
            power_up.setTextureRect(rectSourceSprite_sword);
            power_up.setTexture(texture);
            power_up.scale(2.5, 2.5);
            positionY = 520;
            break;

        case 2: //potion
            texture.loadFromFile("assets/potion.png");
            power_up.setTexture(texture);
            power_up.scale(0.65, 0.65);
            positionY = 545;
            break;
    }

    obj_type = obj;
    power_up.setPosition(positionX, positionY);

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