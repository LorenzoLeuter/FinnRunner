#ifndef FINN_RUNNER_GAMECHARACTER_H
#define FINN_RUNNER_GAMECHARACTER_H

#include <SFML/Graphics.hpp>

class GameCharacter {
public:
    GameCharacter(float posX, float posY, float velX, float velY) : positionX(posX), positionY(posY), velocityX(velX),
                                                                    velocityY(velY) {}

    virtual void animation() {}

    virtual void update() {}

    virtual int getKilled(GameCharacter gc, int countKill) {}


    void setVelocityX(float velX) {
        GameCharacter::velocityX = velX;
    }

    float getPositionX() const {
        return positionX;
    }

    float getPositionY() const {
        return positionY;
    }

    void setPositionX(float posX){
        positionX = posX;
    }

    sf::Sprite getGameCharacter() {
        return game_character;
    }

protected:
    float positionX, positionY;
    float velocityX, velocityY;
    float animation_fps = 0.06;
    sf::Sprite game_character;
    sf::Clock clock;
};

#endif //FINN_RUNNER_GAMECHARACTER_H