#include "Hero.h"

Hero::Hero(): GameCharacter(10,500,0.0,0.0), gravity(0.5), onGround(true){
    texture.loadFromFile("C:\\Users\\gabri\\CLionProjects\\FinnRunner\\assets\\FinnSprite.png");
    gc_sprite.setTexture(texture);
    gc_sprite.setPosition(positionX, positionY);
    gc_sprite.scale(2.5, 2.5);
}



void Hero::getKilled(){

}

void Hero::animation(){
    if (clock.getElapsedTime().asSeconds() > animation_fps){
        if(onGround){
            //ANIMAZIONE CORSA (quando è a terra)
            if(rectSourceSprite.left == 448 || rectSourceSprite.left == 480) {
                rectSourceSprite.left = 288;
            }else {
                rectSourceSprite.left += 32;
            }
        } else {
            //ANIMAZIONE SALTO (cambia solamente la porzione di texture)
            rectSourceSprite.left = 480;
        }

        gc_sprite.setTextureRect(rectSourceSprite);
        clock.restart();
    }

}

void Hero::update() {
    positionX += velocityX * clock.getElapsedTime().asSeconds();
    positionY += velocityY * clock.getElapsedTime().asSeconds();
    velocityY += gravity * clock.getElapsedTime().asSeconds();

    gc_sprite.setPosition(positionX, positionY);

    //MANTIENE A TERRA IL PERSONAGGIO
    if(positionY > 500){
        positionY = 500;
        velocityY = 0.0;
        onGround = true;
        animation_fps = 0.06;
    }

}

void Hero::jump() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround == true){
        velocityY = -12.0;
        onGround = false;
        animation_fps = 0.015;
    }
}

Hero::~Hero() {

}
