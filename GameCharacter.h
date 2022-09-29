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
    float positionX, positionY;
    float velocityX, velocityY;
    float animation_fps = 0.06;
    sf::Sprite game_character;
    sf::Clock clock;
    sf::Texture texture;
};

#endif //FINN_RUNNER_GAMECHARACTER_H