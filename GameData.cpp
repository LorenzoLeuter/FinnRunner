//
// Created by lorenzoleuter on 06/07/22.
//

#include <SFML/Graphics.hpp>
#include "GameData.h"

int GameData::getMeters() const {
    return meters;
}

void GameData::setMeters(int meters) {
    GameData::meters = meters;
}

int GameData::getRecord() const {
    return record;
}

void GameData::setRecord(int record) {
    GameData::record = record;
}

bool GameData::isCharacterAlive() const {
    return character_alive;
}

void GameData::setCharacterAlive(bool characterAlive) {
    character_alive = characterAlive;
}

void GameData::restartGame() {

}

GameData::GameData() : meters(0), record(0),character_alive(false) {
    initVariables();
    initWindow();
}

GameData::~GameData() {
    delete this->window;
}

void GameData::drawMenu() {

}

void GameData::update() {
    while (this->window->pollEvent(this->event)){
        if(event.type == sf::Event::Closed)
            this->window->close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->window->close();


    }
}

void GameData::render() {
    window->clear();
    window->display();
}

void GameData::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(600,600), "Finn_Runner");
}

void GameData::initVariables() {
    this->window = nullptr;
}

const bool GameData::running() {
    return this->window->isOpen();
}

