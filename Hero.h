#ifndef FINNRUNNER_HERO_H
#define FINNRUNNER_HERO_H

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"

class Hero : public GameCharacter{
    public:
        Hero();
        virtual ~Hero(); //todo FARE DISTRUTTORE CLASSE HERO

        bool getStatus(){
            return isAlive;
        }

        void getKilled(GameCharacter enemy);
        void animation() override;
        void update() override;
        void jump();
        void attack();

    private:
        float gravity;
        bool onGround, isAlive, isAttacking;
        sf::IntRect rectSourceSprite{448, 0, 32, 32};
};


#endif //FINNRUNNER_HERO_H
