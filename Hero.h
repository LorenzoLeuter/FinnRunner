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
        float gravity = 0.5;
        bool onGround;
        float animation_fps;
        sf::IntRect rectSourceSprite{448, 0, 32, 32};
};


#endif //FINNRUNNER_HERO_H
