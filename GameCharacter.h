#ifndef FINN_RUNNER_GAMECHARACTER_H
#define FINN_RUNNER_GAMECHARACTER_H
#include <SFML/Graphics.hpp>

class GameCharacter{
public:
    GameCharacter(float posX,float posY,float velX,float velY) : positionX(posX),positionY(posY),velocityX(velX),velocityY(velY) {}

    virtual void animation() {};
    virtual void update() {};


    sf::Sprite getGameCharacter(){
        return game_character;
    }


protected:
    float positionX = 10, positionY = 500;
    float velocityX = 0.0, velocityY = 0.0;
    sf::Sprite game_character;


};

#endif //FINN_RUNNER_GAMECHARACTER_H