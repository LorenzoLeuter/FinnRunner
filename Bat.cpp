#include "Bat.h"

Bat::Bat(): GameCharacter(500,400,-1.0,0.0){
    texture.loadFromFile("assets/Bat.png");
    game_character.setTexture(texture);
    game_character.setPosition(positionX, positionY);
    game_character.scale(1.5, 1.5);
}

void Bat::animation(){
    if (clock.getElapsedTime().asSeconds() > animation_fps){
        if(rectSourceSprite.left == 160) {
            rectSourceSprite.left = 0;
        }else {
            rectSourceSprite.left += 32;
        }

        game_character.setTextureRect(rectSourceSprite);
        clock.restart();

    }
}

void Bat::update() {
    positionX += velocityX * clock.getElapsedTime().asSeconds();
    positionY += velocityY * clock.getElapsedTime().asSeconds();

    game_character.setPosition(positionX, positionY);
}

Bat::~Bat(){

}
