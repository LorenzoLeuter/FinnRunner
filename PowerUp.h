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
