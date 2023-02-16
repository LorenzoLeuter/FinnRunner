#include "Bat.h"

Bat::Bat(float positY,float v,const sf::Texture& t): GameCharacter(1264,positY,v+0.15,0.0){
    game_character.setTexture(t);
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
