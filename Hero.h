#ifndef FINNRUNNER_HERO_H
#define FINNRUNNER_HERO_H

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "PowerUpFactory.h"

class Hero : public GameCharacter {
public:
    Hero();

    virtual ~Hero(); //todo FARE DISTRUTTORE CLASSE HERO

    bool getStatus() {
        return isAlive;
    }

    bool isAttacking1() const {
        return isAttacking;
    }

    void setIsAttacking(bool isAttack) {
        isAttacking = isAttack;
    }

    void incAttackCounter(){
        attackCounter++;
    }


    void getKilled(GameCharacter enemy);

    void animation() override;

    void update() override;

    void jump();

    void attack();

    void collect(PowerUpFactory itm);

private:
    float gravity;
    bool onGround, isAlive, isAttacking, swordCollected;
    int attackCounter;
    sf::IntRect rectSourceSprite{448, 0, 32, 32};
};


#endif //FINNRUNNER_HERO_H
