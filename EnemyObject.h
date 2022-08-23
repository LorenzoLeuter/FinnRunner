#ifndef FINN_RUNNER_ENEMYOBJECT_H
#define FINN_RUNNER_ENEMYOBJECT_H
#include <SFML/Graphics.hpp>


class EnemyObject{
public:
    EnemyObject(int enemy_type);

    void update();
    void animation(int enemy_type);


    sf::Sprite getEnemyObject(){
        return enemy_object;
    }


private:
    float positionX = 600, positionY;
    float velocityX = 0.0;
    sf::Texture texture;
    sf::Sprite enemy_object;
    sf::Clock clock;
    sf::IntRect rectSourceSprite_toast{448, 0, 32, 32};
    sf::IntRect rectSourceSprite_bat{448, 0, 32, 32};
};


#endif //FINN_RUNNER_ENEMYOBJECT_H
