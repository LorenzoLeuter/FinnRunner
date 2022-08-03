//
// Created by lorenzoleuter on 06/07/22.
//

#ifndef FINN_RUNNER_GAMEMAP_H
#define FINN_RUNNER_GAMEMAP_H
#include <SFML/Graphics.hpp>


class GameMap {
    public:
        void createSpawnArea();
        void createTerrain();
        void objectPlacement();
        void spawnGameCharacter();

    GameMap();

    const sf::Sprite &getFloor() const;

private:
        float spawnX;
        float spawnY;

        sf::Texture textureFloor;
        sf::Sprite floor;
};


#endif //FINN_RUNNER_GAMEMAP_H
