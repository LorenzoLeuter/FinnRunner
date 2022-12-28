#ifndef FINNRUNNER_HERO_H
#define FINNRUNNER_HERO_H

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "PowerUp.h"
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

    void getKilled(GameCharacter enemy);

    void animation() override;

    void update() override;

    void jump();

    bool attack();

    bool collect(PowerUp pup, PowerUpFactory itm);

    int getAttackCounter() const;

    void setAttackCounter(int attackCounter);

    bool isSwordCollected() const;

    bool isPotionCollected() const;

private:
    float gravity;
    bool onGround, isAlive, isAttacking, swordCollected, potionCollected;
    int attackCounter;
    int potionJumpCounter;
    sf::IntRect rectSourceSprite{448, 0, 32, 32};
    sf::Texture texture;
};


#endif //FINNRUNNER_HERO_H
