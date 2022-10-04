#ifndef FINNRUNNER_HERO_H
#define FINNRUNNER_HERO_H

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"

class Hero : public GameCharacter{
    public:
        Hero();
        virtual ~Hero(); //todo FARE DISTRUTTORE CLASSE HERO

        void getKilled();
        void animation() override;
        void update() override;
        void jump();

    private:
        float gravity;
        bool onGround;
        sf::IntRect rectSourceSprite{448, 0, 32, 32};
};


#endif //FINNRUNNER_HERO_H
