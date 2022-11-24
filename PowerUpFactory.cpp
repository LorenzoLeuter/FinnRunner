#include "PowerUpFactory.h"

PowerUpFactory::PowerUpFactory(float X) : positionX(X), velocityX(30){}

void PowerUpFactory::update() {
    if(positionX > -500){
        positionX -= velocityX * clock.getElapsedTime().asSeconds();
    }else{
        positionY = -100;
        positionX = -100;
    }
    power_up.setPosition(positionX, positionY);
    clock.restart();
}


PowerUpFactory::~PowerUpFactory() {

}

void PowerUpFactory::setTexture(const sf::Texture &t,const PowerUp& pUp) {
    if(pUp.getCurrentPowerUp()==1) {
        positionY = 520;
        power_up.setTextureRect(rectSourceSprite_sword);
        power_up.setScale(2.5, 2.5);
    }else{
        positionY = 540;
        power_up.setTextureRect(rectSourceSprite_potion);
        power_up.setScale(0.75, 0.75);
    }
    power_up.setTexture(t);
    power_up.setPosition(positionX, positionY);
}

void PowerUpFactory::setPositionX(float positionX) {
    PowerUpFactory::positionX = positionX;
}

void PowerUpFactory::setVelocityX(float velocityX) {
    PowerUpFactory::velocityX = velocityX;
}

