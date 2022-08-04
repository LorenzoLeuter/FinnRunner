#include "GameCharacter.h"


void GameCharacter::getKilled(){

}

GameCharacter::GameCharacter() {
    texture.loadFromFile("C:\\Users\\gabri\\CLionProjects\\FinnRunner\\assets\\FinnSprite.png");
    game_character.setTexture(texture);
    game_character.setTextureRect({0,0,288,32});
    game_character.setPosition(pos); //spawn position
}

void GameCharacter::moveAnimation() {
    if (clock.getElapsedTime().asSeconds() > 0.025f){
        if (rectSourceSprite.left == 480)
            rectSourceSprite.left = 288;
        else
            rectSourceSprite.left += 32;

        game_character.setTextureRect(rectSourceSprite);
        clock.restart();
    }

}



