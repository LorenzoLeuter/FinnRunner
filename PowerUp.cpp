//
// Created by lori0 on 18/10/2022.
//

#include "PowerUp.h"

PowerUp::PowerUp() {
    currentPowerUp = 0;
}

PowerUp::~PowerUp() {

}

int PowerUp::getCurrentPowerUp() const {
    return currentPowerUp;
}

void PowerUp::setCurrentPowerUp(int currentPowerUp) {
    PowerUp::currentPowerUp = currentPowerUp;
}
