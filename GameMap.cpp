//
// Created by lorenzoleuter on 06/07/22.
//

#include "GameMap.h"
#include <SFML/Graphics.hpp>

void GameMap::createSpawnArea() {
    floor.setPosition(0,550);
    textureFloor.loadFromFile("C:\\Users\\lori0\\ClionProjects\\FinnRunner\\assets\\tileset.png");
    floor.setTexture(textureFloor);
    floor.setTextureRect(sf::IntRect(47,175,50,50));
}

void GameMap::createTerrain() {

}

void GameMap::objectPlacement() {

}

void GameMap::spawnGameCharacter() {

}

const sf::Sprite &GameMap::getFloor() const {
    return floor;
}

GameMap::GameMap() : spawnX(0), spawnY(0) {}


