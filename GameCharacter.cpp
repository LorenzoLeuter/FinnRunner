#include "GameCharacter.h"


void GameCharacter::getKilled(){

}

GameCharacter::GameCharacter() {
    texture.loadFromFile("C:\\Users\\gabri\\CLionProjects\\FinnRunner\\assets\\FinnSprite.png");
    game_character.setTexture(texture);
    game_character.setTextureRect({0,0,32,32});
    game_character.setPosition(pos); //spawn position
}



