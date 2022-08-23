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

GameData::GameData() : meters(0), record(0),character_alive(false),inGame(false),xL1(0),xL2(600) {
    this->window = nullptr; //INIZIALIZZAZIONE DELLA FINESTRA DI GIOCO
    initGuiVariables();
    initWindow();
}

GameData::~GameData() {
    delete this->window;
}

void GameData::drawMenu() {

    for (int i = 0; i < max_options; ++i) {
        std::cout << menuOptions[i].getString().isEmpty();
    }

    menuSelected = -1;
}

void GameData::update() {
    while (this->window->pollEvent(this->event)){
        std::cout << event.mouseMove.x << "   " << event.mouseMove.y << std::endl;
        if(inGame){
            if(event.type == sf::Event::Closed)
                this->window->close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window->close();

        }else{
            if(event.type == sf::Event::Closed)
                this->window->close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window->close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(menuSelected == 0){
                    inGame = true;
                    character_alive = true;
                }else if(menuSelected == 1){
                    this->window->close();
                }
            }

            if(sf::Event::MouseMoved){
                if(event.mouseMove.x >= 410 && event.mouseMove.x <= 572 && event.mouseMove.y >= 329 && event.mouseMove.y <= 370){   //exit
                    menuSelected = 1;
                }else if(event.mouseMove.x >= 29 && event.mouseMove.x <= 209 && event.mouseMove.y >= 329 && event.mouseMove.y <= 370) {  //play
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
    if(inGame){
        if(character_alive){
            backgroundLoop();
            player.update();
            player.moveAnimation();
            player.jump();
            scoreUpdate();
        } else {
            //player.death
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

void GameData::renderGame() {
    window->clear();
    window->draw(background);
    window->draw(background2);
    window->draw(score);
    window->draw(player.getGameCharacter());
    window->display();
}

void GameData::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(600,600), "FinnRunner", sf::Style::Titlebar | sf::Style::Close);
}

void GameData::initGuiVariables() {
    //INIZIALIZZAZIONE DELLE COMPONENTI GRAFICHE DELLA FINESTRA (MENU E IL GIOCO)

    if (!font.loadFromFile("C:\\Users\\lori0\\CLionProjects\\FinnRunner\\font_gioco.TTF")) //INSERIMENTO DEL FONT
    {
        std::cout << "DON'T IMPORT THE FONT";

    }

    //CREAZIONE DEI 2 BACKGROUND PER LA REALIZZAZIONE DEL BACKGROUND LOOP
    background.setSize(sf::Vector2f(600,600));
    background.setPosition(sf::Vector2f(xL1,0));
    textureB.loadFromFile("C:\\Users\\lori0\\CLionProjects\\FinnRunner\\assets\\background.png");
    background.setTexture(&textureB);


    background2.setSize(sf::Vector2f(600,600));
    background2.setPosition(sf::Vector2f(xL2,0));
    background2.setTexture(&textureB);

    //CREAZIONE DEL MENU DI GIOCO

    //CREAZIONE DEL TITOLO
    title.setSize(sf::Vector2f(450,175));
    title.setPosition(sf::Vector2f(77,50));
    titleTexture.loadFromFile("C:\\Users\\lori0\\CLionProjects\\FinnRunner\\assets\\FinnRunnerTitle.png");
    title.setTexture(&titleTexture);

    //CREAZIONE DEL TASTO PLAY
    menuOptions[0].setFont(font);
    menuOptions[0].setString("PLAY");
    menuOptions[0].setFillColor(sf::Color::White);
    menuOptions[0].setCharacterSize(50);
    menuOptions[0].setPosition(30,320);

    //CREAZIONE DEL TASTO EXIT
    menuOptions[1].setFont(font);
    menuOptions[1].setString("EXIT");
    menuOptions[1].setFillColor(sf::Color::White);
    menuOptions[1].setCharacterSize(50);
    menuOptions[1].setPosition(410,320);

    //CREAZIONE DEGLI OGGETTI DI GIOCO

    //CREAZIONE DELLO SCORE
    score.setFont(font);
    score.setString("METRES: 0");
    score.setFillColor(sf::Color::White);
    score.setCharacterSize(20);
    score.setPosition(15,15);
    score.setOutlineColor(sf::Color::Black);
    score.setOutlineThickness(2.5);
}

const bool GameData::running() {
    return this->window->isOpen();
}

bool GameData::isInGame() const {
    return inGame;
}

void GameData::backgroundLoop() {
    if(c.getElapsedTime().asSeconds() > 0.025f){
        if(xL1 == -600){
            xL1 = 0;
            xL2 = 600;
        }else{
            xL1 -= 1;
            xL2 -= 1;
        }
        background.setPosition(sf::Vector2f(xL1,0));
        background2.setPosition(sf::Vector2f(xL2,0));
        c.restart();
    }
}

void GameData::scoreUpdate() {
    if(cs.getElapsedTime().asSeconds() > 0.5f){
        meters += 1;
        score.setString("METRES: "+ std::to_string(meters));
        cs.restart();
    }
}


