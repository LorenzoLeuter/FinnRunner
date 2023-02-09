#include <SFML/Graphics.hpp>
#include "GameData.h"
#include <iostream>
#include <fstream>
#include <cstring>


int GameData::getMeters() const {
    return meters;
}

void GameData::setMeters(int meters) {
    GameData::meters = meters;
}

int GameData::getRecord(){
    f = std::fopen("record.txt","r");
    std::fread(&record[0], sizeof record[0], record.size(),f);
    for(int j=0;j<record.size();j++) {
        if(record[0]<'0' || record[0]>'9'){
            record[0]='0';
        }
        if(record[j]>='0' && record[j]<='9'){
            strApp=strApp+record[j];
        }else{
            j=record.size()+1;
        }
    }
    std::fclose(f);
}

bool GameData::setRecord() {
    if(meters > std::stoi(strApp)){
        f= std::fopen("record.txt","w");
        std::fputs(std::to_string(meters).c_str(),f);
        std::fclose(f);
    }
    return true;
}

bool GameData::isCharacterAlive() const {
    return character_alive;
}

void GameData::setCharacterAlive(bool characterAlive) {
    character_alive = characterAlive;
}

void GameData::restartGame() {

}

GameData::GameData() : meters(0), record(10),character_alive(false),inGame(false),xL1(0),xL2(600),rangeSpawn(2),
                        enemyVX(-1.3),spawnPUP(1),objectVelX(30),countE(1),contrTakeObj(false),swordTake(false),defaultS(""),
                       countKill(0), countSP(0), countPP(0),contrSaveR(false){
    //LA VELOCITA' DELLO ZOMBIE E' LA VELOCITA' DEL BACKGROUND / 100
    getRecord();
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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                if(swordTake){
                    if(!player.isAttacking1()){
                        sis = player.attack();
                        if(sis){
                            swords[player.getAttackCounter()].setTextureRect(rectSourceSpriteSwords);
                        }
                    }
                }
            }

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

            if(attackingTime.getElapsedTime().asSeconds() >= (float)coolDownAttack){
                player.setIsAttacking(false);
                attackingTime.restart();
            }
            setObjectVelocity();
            backgroundLoop();

            player.update();
            player.animation();
            player.jump();


            /*for (int i = 0; i < enemies.size(); i++) {
                int x = enemies[i]->getPositionX();
                if(x != -64){
                    enemies[i]->update();
                    enemies[i]->animation();

                    if (player.isAttacking1()) {
                        enemies[i]->getKilled(player);
                    }

                    player.getKilled(*enemies[i]);

                }else{
                    deleteEnemy(i);
                }
            }
            if(enemySpawn.getElapsedTime().asSeconds() > rangeSpawn || (countE != 1 && (664-(int)enemies[enemies.size()-1]->getPositionX())==33)){
                createEnemy();
            }*/


            if(meters == (20)*spawnPUP){
                spawnPUP++;
                /*if((rand()%2) == 0){
                    powerUp.setCurrentPowerUp(1);
                    powerUpGui.setTexture(swords_texture,powerUp);
                    powerUpGui.setPositionX(610);
                }else{*/
                    powerUp.setCurrentPowerUp(2);
                    powerUpGui.setTexture(potion,powerUp);
                    powerUpGui.setPositionX(610);
                //}
            }

            if(powerUp.getCurrentPowerUp()==1){
                contrTakeObj = player.collect(powerUp, powerUpGui,8);
            }else{
                contrTakeObj = player.collect(powerUp, powerUpGui,19);
            }


            scoreUpdate();


            if(contrTakeObj){
                powerUpGui.updateCollect();
                if(!swordTake){
                    swordTake = true;
                }
                if(powerUp.getCurrentPowerUp()==1){
                    for (int i = 0; i < 3; i++) {
                        swords[i].setTextureRect(rectSourceSprite_sword);
                    }
                    player.setAttackCounter(3);
                    countSP++;
                }else{
                    countPP++;
                }
            }else{
                powerUpGui.update();
            }


        } else {

            for (int i = 0; i < enemies.size(); i++) {
                int x = enemies[i]->getPositionX();
                if(x != -64){
                    enemies[i]->update();
                    enemies[i]->animation();

                }else{
                    deleteEnemy(i);
                }
            }

            player.update();
            player.animation();
            //player.jump();
            if(!contrSaveR){
                contrSaveR = setRecord();
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

void GameData::renderGame() {
    window->clear();
    window->draw(background);
    window->draw(background2);
    window->draw(score);
    window->draw(recordT);
    if(swordTake && player.isSwordCollected()){
        window->draw(swords[0]);
        window->draw(swords[1]);
        window->draw(swords[2]);
    }
    if(achievementTxt.getString() != defaultS){
        window->draw(achievementTrophy);
        window->draw(achievementTxt);
    }
    window->draw(player.getGameCharacter());
    for (int i = 0; i < enemies.size(); i++) {
        window->draw(enemies[i]->getGameCharacter());
    }
    window->draw(powerUpGui.getPowerUpSprite());
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
    background.setSize(sf::Vector2f(600, 600));
    background.setPosition(sf::Vector2f(xL1, 0));
    textureB.loadFromFile("assets/background.png");
    background.setTexture(&textureB);


    background2.setSize(sf::Vector2f(600, 600));
    background2.setPosition(sf::Vector2f(xL2, 0));
    background2.setTexture(&textureB);

    //CREAZIONE DEGLI OGGETTI DI GIOCO
    //CREAZIONE DELLO SCORE
    score.setFont(font);
    score.setString("METERS: 0");
    score.setFillColor(sf::Color::White);
    score.setCharacterSize(20);
    score.setPosition(15, 15);
    score.setOutlineColor(sf::Color::Black);
    score.setOutlineThickness(2.5);

    //CREAZIONE DEL RECORD


    std::cout << strApp.length();

    recordT.setFont(font);
    recordT.setString("RECORD= "+strApp);
    recordT.setFillColor(sf::Color::White);
    recordT.setCharacterSize(20);
    recordT.setPosition(280, 15);
    recordT.setOutlineColor(sf::Color::Black);
    recordT.setOutlineThickness(2.5);

    //SWORD GUI INFO
    swords_texture.loadFromFile("assets/sword_sprite.png");
    swords[0].setTextureRect(rectSourceSpriteSwords);
    swords[0].setTextureRect(rectSourceSpriteSwords);
    swords[0].setTextureRect(rectSourceSpriteSwords);

    swords[0].setTexture(swords_texture);
    swords[1].setTexture(swords_texture);
    swords[2].setTexture(swords_texture);

    swords[0].scale(2.0, 2.0);
    swords[1].scale(2.0, 2.0);
    swords[2].scale(2.0, 2.0);


    swords[0].setPosition(0, 30);
    swords[1].setPosition(55, 30);
    swords[2].setPosition(105, 30);

    //Texture
    z.loadFromFile("assets/ZombieToast.png");
    b.loadFromFile("assets/Bat.png");
    potion.loadFromFile("assets/potion.png");
    trophy.loadFromFile("assets/trophy.png");

    /* Realizzazione del trofeo per gli achievement

    achievementTrophy.setSize(sf::Vector2f(20, 20));
    achievementTrophy.setPosition(sf::Vector2f(380, 5));
    achievementTrophy.setTexture(&trophy);

     */
}

const bool GameData::running() {
    return this->window->isOpen();
}

bool GameData::isInGame() const {
    return inGame;
}

void GameData::backgroundLoop() {
    xL1 -= objectVelX * c.getElapsedTime().asSeconds();
    xL2 -= objectVelX * c.getElapsedTime().asSeconds();
    if((int)xL1 == -600){
        xL1 = 0;
        xL2 = 600;
    }
    background.setPosition(sf::Vector2f(xL1,0));
    background2.setPosition(sf::Vector2f(xL2,0));
    c.restart();
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
    if(meters > 200 && meters<=300){
        if(countE != 1){
            countE--;
        }else{
            if(rand()%10 <= 3) {
                countE = 1;
            }else{
                countE = 2;
            }
            enemySpawn.restart();
        }
    }else if(meters > 300){
        if(countE != 1){
            countE--;
        }else{
            if(rand()%15 <= 1) {
                countE = 1;
            }else if(rand()%15 > 1 && rand()%15 <= 8){
                countE = 2;
            }else{
                countE = 3;
            }
        }
    }
    enemySpawn.restart();
    if(meters >= 30) {
        if(rand()%15==0) {
            enemies.push_back(std::unique_ptr<Bat>(new Bat(500,enemyVX,b)));
        }else {
            enemies.push_back(std::unique_ptr<ZombieToast>(new ZombieToast(enemyVX,z)));
        }
    }else{
        enemies.push_back(std::unique_ptr<ZombieToast>(new ZombieToast(enemyVX,z)));
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
    achievementTxt.setFillColor(sf::Color::White);
    achievementTxt.setOutlineColor(sf::Color::Black);
    achievementTxt.setOutlineThickness(2.5);
    achievementTxt.setCharacterSize(25);

    //TESTO AL CENTRO
    sf::FloatRect textRect = achievementTxt.getLocalBounds();
    achievementTxt.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    achievementTxt.setPosition(window->getView().getCenter());

}

void GameData::setObjectVelocity() {
    contr = false;
    switch (meters) {
        case 0:
            objectVelX = 60;
            contr = true;
            break;
        case 2:
            objectVelX = 90;
            contr = true;
            break;
        case 4:
            objectVelX = 120;
            rangeSpawn = 1.8;
            contr = true;
            break;
            /*case 40:
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
                break;*/

    }
    if(contr){
        enemyVX = -(objectVelX / 100) - 1;
        powerUpGui.setVelocityX(objectVelX);
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i]->setVelocityX(enemyVX);
        }
    }

}

int GameData::getCountSp() const {
    return countSP;
}

int GameData::getCountPp() const {
    return countPP;
}
