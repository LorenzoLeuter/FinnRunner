#ifndef FINNRUNNER_ZOMBIETOAST_H
#define FINNRUNNER_ZOMBIETOAST_H

#include "GameCharacter.h"

class ZombieToast : public GameCharacter{
    public:
        ZombieToast(float v);
        virtual ~ZombieToast();

        void animation() override;
        void update() override;

    private:
        sf::IntRect rectSourceSprite{0, 0, 64, 64};
};


#endif //FINNRUNNER_ZOMBIETOAST_H
