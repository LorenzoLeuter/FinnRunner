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

GameData::GameData() : meters(0), record(0),character_alive(false),inGame(false),xL1(0),xL2(600),blVel(0.025f),rangeSpawn(2.6),enemyVX(-1.3) {
    this->window = nullptr; //INIZIALIZZAZIONE DELLA FINESTRA DI GIOCO
    initGuiVariables();
    initWindow();
}

GameData::~GameData() {
    delete this->window;
}

void GameData::drawMenu() {
    //CREAZIONE DEL MENU DI GIOCO

    //CREAZIONE DEL TITOLO
    title.setSize(sf::Vector2f(450,175));
    title.setPosition(sf::Vector2f(77,50));
    titleTexture.loadFromFile("assets/Title.png");
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

    //SCELTA NEL MENU A -1
    menuSelected = -1;
}

void GameData::update() {
    while (this->window->pollEvent(this->event)){
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
        if(player.getStatus()){

            backgroundLoop();
            setEnemyVelocity();

            player.update();
            player.animation();
            player.jump();
            player.attack();

            /*for (int i = 0; i < enemies.size(); i++) {
                int x = enemies[i]->getPositionX();
                if(x != -64){
                    enemies[i]->update();
                    enemies[i]->animation();
                    player.attack(*enemies[i]);
                    player.getKilled(*enemies[i]);

                }else{
                    deleteEnemy(i);
                }
            }
            if(enemySpawn.getElapsedTime().asSeconds() > rangeSpawn){
                createEnemy();
            }*/

            scoreUpdate();

        } else {

            /*for (int i = 0; i < enemies.size(); i++) {
                int x = enemies[i]->getPositionX();
                if(x != -64){
                    enemies[i]->update();
                    enemies[i]->animation();

                }else{
                    deleteEnemy(i);
                }
            }*/


            player.animation();
            player.jump();

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
    window->draw(achievementTxt);
    window->draw(player.getGameCharacter());
    for (int i = 0; i < enemies.size(); i++) {
        window->draw(enemies[i]->getGameCharacter());
    }
    //window->draw(bat_test.getGameCharacter());
    window->display();
}

void GameData::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(600,600), "FinnRunner", sf::Style::Titlebar | sf::Style::Close);
}

void GameData::initGuiVariables() {
    //INIZIALIZZAZIONE DELLE COMPONENTI GRAFICHE DELLA FINESTRA (MENU E IL GIOCO)

    if (!font.loadFromFile("assets/font.TTF")) //INSERIMENTO DEL FONT
    {
        std::cout << "DON'T IMPORT THE FONT";

    }

    //CREAZIONE DEI 2 BACKGROUND PER LA REALIZZAZIONE DEL BACKGROUND LOOP
    background.setSize(sf::Vector2f(600,600));
    background.setPosition(sf::Vector2f(xL1,0));
    textureB.loadFromFile("assets/background.png");
    background.setTexture(&textureB);


    background2.setSize(sf::Vector2f(600,600));
    background2.setPosition(sf::Vector2f(xL2,0));
    background2.setTexture(&textureB);

    //CREAZIONE DEGLI OGGETTI DI GIOCO
    //CREAZIONE DELLO SCORE
    score.setFont(font);
    score.setString("METERS: 0");
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
    setBackgroundVelocity();
    if(c.getElapsedTime().asSeconds() > blVel){
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
        score.setString("METERS: "+ std::to_string(meters));
        cs.restart();
    }
    notifyObservers();
}

void GameData::createEnemy() {
    if(meters >= 500){
        if((rand()%7) == 0){
            enemies.push_back(std::unique_ptr<ZombieToast>(new ZombieToast(enemyVX)));
        }else{
            if((rand()%7) == 0){
                enemies.push_back(std::unique_ptr<Bat>(new Bat(500,enemyVX)));
            }else{
                enemies.push_back(std::unique_ptr<Bat>(new Bat(440,enemyVX)));
            }
        }
        enemySpawn.restart();
    }else{
        enemies.push_back(std::unique_ptr<ZombieToast>(new ZombieToast(enemyVX)));
        enemySpawn.restart();
    }
}

void GameData::deleteEnemy(int posList) {
    enemies.erase(enemies.begin()+posList);
}

void GameData::registerObserver(Observer *o) {
    observers.push_back(o);
}

void GameData::removeObserver(Observer *o) {
    observers.remove(o);
}

void GameData::notifyObservers() const{
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++)
        (*itr)->update();
}

void GameData::setAchievementTxt(std::string achievement) {
    //CREAZIONE DEGLI ACHIEVEMENT
    achievementTxt.setFont(font);
    achievementTxt.setString(achievement);
    achievementTxt.setFillColor(sf::Color::Black);
    achievementTxt.setCharacterSize(10);
    achievementTxt.setPosition(495,5);
}

void GameData::setBackgroundVelocity() {
    switch (meters) {
        case 20:
            blVel = 0.021f;
            break;
        case 22:
            blVel = 0.017f;
            break;
        case 24:
            blVel = 0.014f;
            break;
        case 26:
            blVel = 0.010f;
            break;
        case 40:
            blVel = 0.0085f;
            break;
        case 42:
            blVel = 0.007f;
            break;
        case 44:
            blVel = 0.0062f;
            break;
        case 46:
            blVel = 0.0046f;
            break;
    }
}

void GameData::setEnemyVelocity() {
    switch (meters) {
        case 20:
            enemyVX = -1.45;
            break;
        case 22:
            enemyVX = -1.65;
            rangeSpawn = 1.65;
            break;
        case 24:
            enemyVX = -1.85;
            break;
        case 26:
            enemyVX = -2.05;
            break;
        case 40:
            enemyVX = -2.1;
            break;
        case 42:
            enemyVX = -2.2;
            rangeSpawn = 1.47;
            break;
        case 44:
            enemyVX = -2.3;
            break;
        case 46:
            enemyVX = -2.4;
            break;
    }
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->setVelocityX(enemyVX);
    }
}
