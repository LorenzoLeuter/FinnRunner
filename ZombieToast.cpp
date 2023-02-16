#include "ZombieToast.h"

ZombieToast::ZombieToast(float v,const sf::Texture& t) : GameCharacter(1264, 484, v, 0.0), isAlive(true),Active(false) {
    game_character.setTexture(t);
    game_character.setPosition(positionX, positionY);
    game_character.scale(1.25, 1.25);
}

void ZombieToast::animation() {
    if (clock.getElapsedTime().asSeconds() > animation_fps) {
        if (isAlive) {
            if (rectSourceSprite.left == 384) {
                rectSourceSprite.left = 0;
            } else {
                rectSourceSprite.left += 64;
            }

        } else {
            //ANIMAZIONE MORTE
            if(rectSourceSprite.left != 768){
                rectSourceSprite.left += 64;
            }
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


int ZombieToast::getKilled(GameCharacter hero,int countKill) {
    if ((int)positionX >= (int)hero.getPositionX() + 15 && (int)positionX <= (int)hero.getPositionX() + 20 && isAlive) {
        isAlive = false;
        rectSourceSprite.left = 975;
        animation_fps = 0.03;
        return countKill+1;
    }
    return countKill;
}


ZombieToast::~ZombieToast() {

}