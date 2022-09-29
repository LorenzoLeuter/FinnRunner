#ifndef FINNRUNNER_BAT_H
#define FINNRUNNER_BAT_H

#include "GameCharacter.h"

class Bat : public GameCharacter {
    public:
        Bat();
        virtual ~Bat();

        void animation() override;
        //void update() override;

    private:
        sf::IntRect rectSourceSprite{0, 0, 32, 32};

};


#endif //FINNRUNNER_BAT_H
