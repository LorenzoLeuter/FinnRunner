#ifndef FINNRUNNER_HERO_H
#define FINNRUNNER_HERO_H

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "PowerUp.h"
#include "PowerUpFactory.h"

class Hero : public GameCharacter {
public:

    Hero();

    virtual ~Hero();

    bool getStatus() {
        return isAlive;
    }

    bool isAttacking1() const {
        return isAttacking;
    }

    void setIsAttacking(bool isAttack) {
        isAttacking = isAttack;
    }

    void getKilled(GameCharacter enemy);

    void animation() override;

    void update() override;

    void jump();

    void setAttackCounter(int attackCounter);

    void reset();

    bool attack();

    bool collect(PowerUp pup, PowerUpFactory itm, int delta);

    bool isSwordCollected() const;

    int getAttackCounter() const;

private:
    float gravity;
    bool onGround, isAttacking, swordCollected, potionCollected;
    int attackCounter;
    int potionJumpCounter = 0;
    sf::IntRect rectSourceSprite{448, 0, 32, 32};
    sf::Texture texture;
};


#endif //FINNRUNNER_HERO_H
