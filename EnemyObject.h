//
// Created by lorenzoleuter on 06/07/22.
//

#ifndef FINN_RUNNER_ENEMYOBJECT_H
#define FINN_RUNNER_ENEMYOBJECT_H
#include <SFML/Graphics/Sprite.hpp>


class EnemyObject : sf::Sprite{
    public:

private:
        float cordX;
        float cordY;
        enum enemy_type {bullet,fire};
};


#endif //FINN_RUNNER_ENEMYOBJECT_H
