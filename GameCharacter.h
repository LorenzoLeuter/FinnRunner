#ifndef FINN_RUNNER_GAMECHARACTER_H
#define FINN_RUNNER_GAMECHARACTER_H
#include <SFML/Graphics.hpp>

class GameCharacter{
    public:

        GameCharacter(float x, float y, float vel_x, float vel_y) : positionX(x), positionY(y), velocityX(vel_x), velocityY(vel_y){
        }

        virtual void animation();
        virtual void update();

        sf::Sprite getGameCharacter(){
            return gc_sprite;
        }


    protected:
        float positionX, positionY;
        float velocityX, velocityY;
        sf::Texture texture;
        sf::Sprite gc_sprite;
        sf::Clock clock;
};


#endif //FINN_RUNNER_GAMECHARACTER_H