//
// Created by lorenzoleuter on 06/07/22.
//

#include <SFML/Graphics.hpp>
#include "GameData.h"
#include <iostream>

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

GameData::GameData() : meters(0), record(0),character_alive(false),inGame(false) {
    initVariables();
    initWindow();

    if (!font.loadFromFile("C:\\Users\\lori0\\ClionProjects\\FinnRunner\\arial.ttf"))
    {
        std::cout << "DON'T IMPORT THE FONT";

    }

    backgroundGame.setSize(sf::Vector2f(600,600));
    gameTexture.loadFromFile("C:\\Users\\lori0\\ClionProjects\\FinnRunner\\assets\\backgroundGame.png");
    backgroundGame.setTexture(&gameTexture);

    title.setSize(sf::Vector2f(300,120));
    title.setPosition(sf::Vector2f(150,50));
    titleTexture.loadFromFile("C:\\Users\\lori0\\ClionProjects\\FinnRunner\\assets\\FinnRunnerTitle.png");
    title.setTexture(&titleTexture);

    menuOptions[0].setFont(font);
    menuOptions[0].setString("Play");
    menuOptions[0].setFillColor(sf::Color::White);
    menuOptions[0].setCharacterSize(70);
    menuOptions[0].setPosition(50,290);

    //EXIT
    menuOptions[1].setFont(font);
    menuOptions[1].setString("Exit");
    menuOptions[1].setFillColor(sf::Color::White);
    menuOptions[1].setCharacterSize(70);
    menuOptions[1].setPosition(425,290);
}

GameData::~GameData() {
    delete this->window;
}

void GameData::drawMenu() {
    background.setSize(sf::Vector2f(600,600));
    texture.loadFromFile("C:\\Users\\lori0\\ClionProjects\\FinnRunner\\assets\\backgroundMenu.png");
    background.setTexture(&texture);

    for (int i = 0; i < max_options; ++i) {
        std::cout << menuOptions[i].getString().isEmpty();
    }


    menuSelected = -1;
}

void GameData::update() {
    while (this->window->pollEvent(this->event)){
        if(event.type == sf::Event::Closed)
            this->window->close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->window->close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            std::cout << "HA CLICCATO   " << menuSelected << std::endl;
            if(menuSelected == 0){
                inGame = true;
            }else if(menuSelected == 1){
                this->window->close();
            }
        }

        if(sf::Event::MouseMoved){
            std::cout << "SI E' MOSSO" << std::endl;
            std::cout << "x= " << event.mouseMove.x << "  y=" << event.mouseMove.y << std::endl;

            if(event.mouseMove.x >= 431 && event.mouseMove.x <= 541 && event.mouseMove.y >= 310 && event.mouseMove.y <= 360){
                menuSelected = 1;
            }else if(event.mouseMove.x >= 55 && event.mouseMove.x <= 182 && event.mouseMove.y >= 310 && event.mouseMove.y <= 375) {
                menuSelected = 0;
            }else{
                menuSelected = -1;
            }

            if(menuSelected == -1){
                for (int i = 0; i < max_options; i++) {
                    menuOptions[i].setFillColor(sf::Color::White);
                }
            }else{
                menuOptions[menuSelected].setFillColor(sf::Color::Black);
            }
        }
    }
}


void GameData::renderMenu() {
    window->clear();
    window->draw(background);
    window->draw(title);
    for (int i = 0; i < max_options; i++) {
        window->draw(menuOptions[i]);
    }
    window->display();
}

void GameData::render() {
    window->clear();
    window->draw(backgroundGame);
    window->display();
}

void GameData::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(600,600), "Finn_Runner_Menu");
}

void GameData::initVariables() {
    this->window = nullptr;
}

const bool GameData::running() {
    return this->window->isOpen();
}

bool GameData::isInGame() const {
    return inGame;
}
