#ifndef FINN_RUNNER_GAMECHARACTER_H
#define FINN_RUNNER_GAMECHARACTER_H
#include <SFML/Graphics.hpp>

class GameCharacter{
    public:

        GameCharacter();
        virtual ~GameCharacter(); //todo FARE DISTRUTTORE GameCharacter

        void getKilled();
        void animation();
        void update();
        void jump();


        sf::Sprite getGameCharacter(){
            return game_character;
    }




    private:

        float positionX, positionY;
        float velocityX, velocityY;
        float gravity;
        bool onGround;
        float animation_fps;
        sf::Texture texture;
        sf::Sprite game_character;
        sf::Clock clock;
        sf::IntRect rectSourceSprite{448, 0, 32, 32};
};


#endif //FINN_RUNNER_GAMECHARACTER_H