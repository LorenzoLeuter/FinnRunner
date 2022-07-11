#include "GameCharacter.h"


void GameCharacter::getKilled(){

}

GameCharacter::GameCharacter() {
    texture.loadFromFile("C:\\Users\\gabri\\CLionProjects\\FinnRunner\\assets\\FinnSprite.png");
    game_character.setTexture(texture);
    //game_character.setTextureRect();
    pos = {0.0f, 0.0f}; // pos = {"spawn coordinates"}
}



void GameCharacter::setDirection(const sf::Vector2f &dir) {

    vel = dir * speed;

}

void GameCharacter::Update(float dt) {
    pos += vel * dt;
    game_character.setPosition(pos);
}
