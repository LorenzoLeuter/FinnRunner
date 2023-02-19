#ifndef FINNRUNNER_ZOMBIETOAST_H
#define FINNRUNNER_ZOMBIETOAST_H

#include "GameCharacter.h"

class ZombieToast : public GameCharacter {
public:
    ZombieToast(float v, const sf::Texture &texture);

    virtual ~ZombieToast();

    void animation() override;

    void update() override;

    int getKilled(GameCharacter hero, int countKill);

private:
    sf::IntRect rectSourceSprite{0, 0, 64, 64};
    bool isAlive;

};


#endif //FINNRUNNER_ZOMBIETOAST_H
