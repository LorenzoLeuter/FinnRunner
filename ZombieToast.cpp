#include "ZombieToast.h"

ZombieToast::ZombieToast(float v): GameCharacter(664,484,v,0.0){
    texture.loadFromFile("assets/ZombieToast.png");
    game_character.setTexture(texture);
    game_character.setPosition(positionX, positionY);
    game_character.scale(1.25, 1.25);
}

void ZombieToast::animation(){
    if (clock.getElapsedTime().asSeconds() > animation_fps){
        if(rectSourceSprite.left == 384) {
            rectSourceSprite.left = 0;
        }else {
            rectSourceSprite.left += 64;
        }

        game_character.setTextureRect(rectSourceSprite);
        clock.restart();

    }
}

void ZombieToast::update() {
    positionX += velocityX * clock.getElapsedTime().asSeconds();
    positionY += velocityY * clock.getElapsedTime().asSeconds();

    game_character.setPosition(positionX, positionY);
}

ZombieToast::~ZombieToast(){
    
}