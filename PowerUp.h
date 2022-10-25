//
// Created by lori0 on 18/10/2022.
//

#ifndef FINNRUNNER_POWERUP_H
#define FINNRUNNER_POWERUP_H

class PowerUp {

public:
        PowerUp();
        virtual ~PowerUp();
        int getCurrentPowerUp() const;
        void setCurrentPowerUp(int currentPowerUp);
private:
        int currentPowerUp;
};


#endif //FINNRUNNER_POWERUP_H
