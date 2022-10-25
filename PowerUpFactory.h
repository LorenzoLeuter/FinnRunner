//
// Created by lori0 on 18/10/2022.
//

#ifndef FINNRUNNER_POWERUPFACTORY_H
#define FINNRUNNER_POWERUPFACTORY_H

#include "PowerUp.h"

enum powerUps { sword, speedskip, freeze};

class PowerUpFactory {

public:
    PowerUpFactory();
    virtual ~PowerUpFactory();
    int setUpPowerUp(int currentPowerUp);
};


#endif //FINNRUNNER_POWERUPFACTORY_H
