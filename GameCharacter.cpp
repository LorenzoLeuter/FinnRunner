#include "GameCharacter.h"


void GameCharacter::getKilled(){

}

GameCharacter::GameCharacter() {
    texture.loadFromFile("C:\\Users\\lori0\\ClionProjects\\FinnRunner\\assets\\FinnSprite.png");
    game_character.setTexture(texture);
    //game_character.setTextureRect();
    pos = {0.0f, 0.0f}; // pos = {"spawn coordinates"}
}



