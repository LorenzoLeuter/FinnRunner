#include <SFML/Graphics.hpp>
#include "GameData.h"
#include <iostream>


int GameData::getMeters() const {
    return meters;
}

int GameData::getRecord() {
    f = std::fopen("record.txt", "r");
    std::fread(&record[0], sizeof record[0], record.size(), f);
    for (int j = 0; j < record.size(); j++) {
        if (record[0] < '0' || record[0] > '9') {
            record[0] = '0';
        }
        if (record[j] >= '0' && record[j] <= '9') {
            strApp = strApp + record[j];
        } else {
            j = record.size() + 1;
        }
    }
    std::fclose(f);
}

bool GameData::setRecord() {
    if (meters > std::stoi(strApp)) {
        f = std::fopen("record.txt", "w");
        std::fputs(std::to_string(meters).c_str(), f);
        std::fclose(f);
        strApp = std::to_string(meters);
    }
    return true;
}


GameData::GameData() : meters(0), record(10), inGame(false), xL1(0), xL2(600), rangeSpawn(2),
                       enemyVX(-1.3), spawnPUP(1), objectVelX(30), countE(1), contrTakeObj(false), swordTake(false),
                       defaultS(""),
                       countKill(0), countSP(0), countPP(0), contrSaveR(false) {

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
    title.setSize(sf::Vector2f(750, 450)); //650 200 prima

    //Titolo senza spada
    titleTexture.loadFromFile("assets/title_nosword.png");
    title.setTexture(&titleTexture);

    //Spada titolo
    title_sword_txt.loadFromFile("assets/title_sword.png");
    title_sword.setTexture(&title_sword_txt);
    title_sword.setSize(sf::Vector2f(750, 450));

    //CREAZIONE DEL TASTO PLAY
    menuOptions[0].setFont(font);
    menuOptions[0].setString("PLAY");
    menuOptions[0].setFillColor(sf::Color::White);
    menuOptions[0].setCharacterSize(50);

    sf::FloatRect playRect = menuOptions[0].getLocalBounds();
    menuOptions[0].setOrigin((playRect.left + 300) + playRect.width / 2.0f,
                             (playRect.top - 50) + playRect.height / 2.0f);
    menuOptions[0].setPosition(window->getView().getCenter());


    //CREAZIONE DEL TASTO EXIT
    menuOptions[1].setFont(font);
    menuOptions[1].setString("EXIT");
    menuOptions[1].setFillColor(sf::Color::White);
    menuOptions[1].setCharacterSize(50);

    sf::FloatRect exitRect = menuOptions[1].getLocalBounds();
    menuOptions[1].setOrigin((exitRect.left - 300) + exitRect.width / 2.0f,
                             (exitRect.top - 50) + exitRect.height / 2.0f);
    menuOptions[1].setPosition(window->getView().getCenter());

    //SCELTA NEL MENU A -1
    menuSelected = -1;
}

void GameData::update() {
    while (this->window->pollEvent(this->event)) {
        if (inGame) {
            if (event.type == sf::Event::Closed)
                this->window->close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window->close();

            if (player.getStatus()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    if (swordTake) {
                        if (!player.isAttacking1()) {
                            sis = player.attack();
                            if (sis) {
                                swords[player.getAttackCounter()].setTextureRect(rectSourceSpriteSwords);
                            }
                            attackingTime.restart();
                        }
                    }
                }
            } else {
                //SETTING TAST DEATH SCREEN

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (menuSelected == 0) {
                        resetGame();
                    } else if (menuSelected == 1) {
                        this->window->close();
                    }
                }

                if (sf::Event::MouseMoved) {

                    std::cout << sf::Mouse::getPosition(*window).x << std::endl;
                    std::cout << menuSelected << std::endl;

                    if (event.mouseMove.x >= 816 && event.mouseMove.x <= 976 && event.mouseMove.y >= 274 &&
                        event.mouseMove.y <= 322) {   //exit
                        menuSelected = 1;
                    } else if (event.mouseMove.x >= 208 && event.mouseMove.x <= 392 && event.mouseMove.y >= 274 &&
                               event.mouseMove.y <= 322) {  //play
                        menuSelected = 0;
                    } else {
                        menuSelected = -1;
                    }
                    if (menuSelected == -1) {
                        deathOptions[0].setFillColor(sf::Color::White);
                        deathOptions[1].setFillColor(sf::Color::White);
                    } else {
                        deathOptions[menuSelected].setFillColor(sf::Color::Black);
                    }


                }
            }


        } else {
            if (event.type == sf::Event::Closed)
                this->window->close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window->close();


            //SETTING TASTI MENU INIZIALE

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (menuSelected == 0) {
                    inGame = true;
                    c.restart();

                } else if (menuSelected == 1) {
                    this->window->close();
                }
            }


            if (sf::Event::MouseMoved) {

                std::cout << sf::Mouse::getPosition(*window).y << std::endl;

                if (event.mouseMove.x >= 813 && event.mouseMove.x <= 975 && event.mouseMove.y >= 328 &&
                    event.mouseMove.y <= 370) {   //exit
                    menuSelected = 1;
                } else if (event.mouseMove.x >= 210 && event.mouseMove.x <= 390 && event.mouseMove.y >= 328 &&
                           event.mouseMove.y <= 370) {  //play
                    menuSelected = 0;
                } else {
                    menuSelected = -1;
                }
                if (menuSelected == -1) {
                    for (int i = 0; i < max_options; i++) {
                        menuOptions[i].setFillColor(sf::Color::White);
                    }
                } else {
                    menuOptions[menuSelected].setFillColor(sf::Color::Black);
                }


            }


        }
    }


    if (inGame) {
        if (player.getStatus()) {

            if (attackingTime.getElapsedTime().asSeconds() >= (float) coolDownAttack) {
                player.setIsAttacking(false);
                attackingTime.restart();
            }
            setObjectVelocity();
            backgroundLoop();

            player.update();
            player.animation();
            player.jump();


            for (int i = 0; i < enemies.size(); i++) {
                int x = enemies[i]->getPositionX();
                if (x != -64) {
                    enemies[i]->update();
                    enemies[i]->animation();

                    if (player.isAttacking1()) {
                        countKill = enemies[i]->getKilled(player, countKill);
                    }

                    player.getKilled(*enemies[i]);

                } else {
                    deleteEnemy(i);
                }
            }
            if (enemySpawn.getElapsedTime().asSeconds() > rangeSpawn ||
                (countE != 1 && (1264 - (int) enemies[enemies.size() - 1]->getPositionX()) == 33)) {
                createEnemy();
            }


            if (meters == (20) * spawnPUP) {
                spawnPUP++;
                if ((rand() % 2) == 0) {
                    powerUp.setCurrentPowerUp(1);
                    powerUpGui.setTexture(swords_texture, powerUp);
                    powerUpGui.setPositionX(800);
                } else {
                    powerUp.setCurrentPowerUp(2);
                    powerUpGui.setTexture(potion, powerUp);
                    powerUpGui.setPositionX(800);
                }
            }

            if (powerUp.getCurrentPowerUp() == 1) {
                contrTakeObj = player.collect(powerUp, powerUpGui, 30);
            } else {
                contrTakeObj = player.collect(powerUp, powerUpGui, 29);
            }


            scoreUpdate();


            if (contrTakeObj) {
                powerUpGui.updateCollect();
                if (!swordTake) {
                    swordTake = true;
                }
                if (powerUp.getCurrentPowerUp() == 1) {
                    for (int i = 0; i < 3; i++) {
                        swords[i].setTextureRect(rectSourceSprite_sword);
                    }
                    player.setAttackCounter(3);
                    countSP++;
                } else {
                    countPP++;
                }
            } else {
                powerUpGui.update();
            }


        } else {

            for (int i = 0; i < enemies.size(); i++) {
                int x = enemies[i]->getPositionX();
                if (x != -64) {
                    enemies[i]->update();
                    enemies[i]->animation();

                } else {
                    deleteEnemy(i);
                }
            }

            player.update();
            player.animation();

            if (!contrSaveR) {
                contrSaveR = setRecord();
            }

        }
    }
}

void GameData::deathScreen() {
    //SCRITTA GAME OVER
    txt.setFont(font);
    txt.setString("GAME OVER");
    txt.setFillColor(sf::Color::White);
    txt.setOutlineColor(sf::Color::Black);
    txt.setOutlineThickness(2.5);
    txt.setCharacterSize(70);

    sf::FloatRect txtRect = txt.getLocalBounds();
    txt.setOrigin((txtRect.left) + txtRect.width / 2.0f, (txtRect.top + 120) + txtRect.height / 2.0f);
    txt.setPosition(window->getView().getCenter());
    window->draw(txt);

    //MENU
    deathOptions[0].setFont(font);
    deathOptions[0].setString("PLAY");

    deathOptions[0].setCharacterSize(50);
    sf::FloatRect op1Rect = deathOptions[0].getLocalBounds();
    deathOptions[0].setOrigin((op1Rect.left + 300) + op1Rect.width / 2.0f, op1Rect.top + op1Rect.height / 2.0f);
    deathOptions[0].setPosition(window->getView().getCenter());


    deathOptions[1].setFont(font);
    deathOptions[1].setString("EXIT");
    deathOptions[1].setCharacterSize(50);
    sf::FloatRect op2Rect = deathOptions[1].getLocalBounds();
    deathOptions[1].setOrigin((op2Rect.left - 300) + op2Rect.width / 2.0f, op2Rect.top + op2Rect.height / 2.0f);
    deathOptions[1].setPosition(window->getView().getCenter());

    window->draw(deathOptions[0]);
    window->draw(deathOptions[1]);

    //METERS E RECORD PER IL DEATH SCREEN
    metersDeath.setFont(font);
    metersDeath.setString("METERS: " + std::to_string(meters));
    metersDeath.setFillColor(sf::Color::White);
    metersDeath.setOutlineColor(sf::Color::Black);
    metersDeath.setOutlineThickness(2.5);
    metersDeath.setCharacterSize(30);
    sf::FloatRect metRect = metersDeath.getLocalBounds();
    metersDeath.setOrigin((metRect.left) + metRect.width / 2.0f, (metRect.top - 100) + metRect.height / 2.0f);
    metersDeath.setPosition(window->getView().getCenter());
    window->draw(metersDeath);

    recordDeath.setFont(font);
    recordDeath.setString("RECORD: " + strApp);
    recordDeath.setFillColor(sf::Color::White);
    recordDeath.setOutlineColor(sf::Color::Black);
    recordDeath.setOutlineThickness(2.5);
    recordDeath.setCharacterSize(30);
    sf::FloatRect recRect = recordDeath.getLocalBounds();
    recordDeath.setOrigin((recRect.left) + recRect.width / 2.0f, (recRect.top - 150) + recRect.height / 2.0f);
    recordDeath.setPosition(window->getView().getCenter());
    window->draw(recordDeath);

}

void GameData::renderMenu() {
    window->clear();
    window->draw(background);
    window->draw(title);

    if (title.getSize().x == 750 && title_sword.getPosition().x == 220) {

        titleTexture.loadFromFile("assets/Title.png");

        for (int i = 0; i < max_options; i++) {
            window->draw(menuOptions[i]);
        }

    } else {

        //ANIMAZIONE TITOLO
        window->draw(title_sword);

        if (clock.getElapsedTime().asSeconds() > 0.08) {
            if (title.getSize().x != 750 && title.getSize().y != 450) {
                x_title += 75;
                y_title += 45;
            }

            title.setSize(sf::Vector2f(x_title, y_title));
            sf::FloatRect titleRect = title.getLocalBounds();
            title.setOrigin(titleRect.left + titleRect.width / 2.0f, (titleRect.top + 120) + titleRect.height / 2.0f);
            title.setOrigin(titleRect.left + titleRect.width / 2.0f, (titleRect.top + 120) + titleRect.height / 2.0f);
            title.setPosition(window->getView().getCenter());
            clock.restart();

        }

        if (clock1.getElapsedTime().asSeconds() > 0.04) {

            if (title_sword.getPosition().x != 220) {
                x_sword += 20;
            }


            title_sword.setPosition(x_sword, y_sword);
            clock1.restart();

        }

    }


    window->display();
}

void GameData::renderGame() {
    if (player.getStatus()) {
        window->clear();
        window->draw(background);
        window->draw(background2);
        window->draw(score);
        window->draw(recordT);
        if (swordTake && player.isSwordCollected()) {
            window->draw(swords[0]);
            window->draw(swords[1]);
            window->draw(swords[2]);
        }
        if (achievementTxt.getString() != defaultS) {
            window->draw(achievementTrophy);
            window->draw(achievementTxt);
        }
        window->draw(player.getGameCharacter());
        for (int i = 0; i < enemies.size(); i++) {
            window->draw(enemies[i]->getGameCharacter());
        }
        window->draw(powerUpGui.getPowerUpSprite());
        window->display();
    } else {

        //SCHERMATA MORTE
        window->clear();

        window->draw(background);
        window->draw(background2);

        window->draw(player.getGameCharacter());
        for (int i = 0; i < enemies.size(); i++) {
            window->draw(enemies[i]->getGameCharacter());
        }

        deathScreen();


        window->display();
    }
}

void GameData::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(1200, 600), "FinnRunner", sf::Style::Titlebar | sf::Style::Close);
}

void GameData::initGuiVariables() {
    //INIZIALIZZAZIONE DELLE COMPONENTI GRAFICHE DELLA FINESTRA (MENU E IL GIOCO)

    if (!font.loadFromFile("assets/font.TTF")) //INSERIMENTO DEL FONT
    {
        std::cout << "DON'T IMPORT THE FONT";

    }

    //CREAZIONE DEI 2 BACKGROUND PER LA REALIZZAZIONE DEL BACKGROUND LOOP
    background.setSize(sf::Vector2f(1200, 600));
    background.setPosition(sf::Vector2f(xL1, 0));
    textureB.loadFromFile("assets/background.png");
    background.setTexture(&textureB);


    background2.setSize(sf::Vector2f(1200, 600));
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

    recordT.setFont(font);
    recordT.setString("RECORD: " + strApp);
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
        if ((int) xL1 == -600) {
            xL1 = 0;
            xL2 = 600;
        }
        background.setPosition(sf::Vector2f(xL1, 0));
        background2.setPosition(sf::Vector2f(xL2, 0));
        c.restart();
}

void GameData::scoreUpdate() {
    if (cs.getElapsedTime().asSeconds() > 0.5f) {
        meters += 1;
        score.setString("METERS: " + std::to_string(meters));
        cs.restart();
    }
    notifyObservers();
}

void GameData::createEnemy() {
    if (meters > 30 && meters <= 60) {
        if (countE != 1) {
            countE--;
        } else {
            if (rand() % 10 <= 3) {
                countE = 1;
            } else {
                countE = 2;
            }
            enemySpawn.restart();
        }
    } else if (meters > 60) {
        if (countE != 1) {
            countE--;
        } else {
            if (rand() % 15 <= 1) {
                countE = 1;
            } else if (rand() % 15 > 1 && rand() % 15 <= 8) {
                countE = 2;
            } else {
                countE = 3;
            }
        }
    }
    enemySpawn.restart();
    if (meters >= 30) {
        if (rand() % 15 == 0) {
            enemies.push_back(std::unique_ptr<Bat>(new Bat(500, enemyVX, b)));
        } else {
            enemies.push_back(std::unique_ptr<ZombieToast>(new ZombieToast(enemyVX, z)));
        }
    } else {
        enemies.push_back(std::unique_ptr<ZombieToast>(new ZombieToast(enemyVX, z)));
    }
}

void GameData::deleteEnemy(int posList) {
    enemies.erase(enemies.begin() + posList);
}

void GameData::registerObserver(Observer *o) {
    observers.push_back(o);
}

void GameData::removeObserver(Observer *o) {
    observers.remove(o);
}

void GameData::notifyObservers() const {
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
    achievementTxt.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    achievementTxt.setPosition(window->getView().getCenter());

}

void GameData::setObjectVelocity() {
    contr = false;
    switch (meters) {
        case 0:
            objectVelX = 85;
            contr = true;
            break;
        case 30:
            objectVelX = 150;
            rangeSpawn = 1.5;
            contr = true;
            break;
        case 60:
            objectVelX = 200;
            rangeSpawn = 1.0;
            contr = true;
            break;
        case 100:
            rangeSpawn = 0.95;
            contr = true;
            break;

        case 150:
            rangeSpawn = 0.90;
            contr = true;
            break;

        case 200:
            rangeSpawn = 0.85;
            contr = true;
            break;

        case 250:
            rangeSpawn = 0.8;
            contr = true;
            break;

    }

    if (contr) {
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

int GameData::getCountKill() const {
    return countKill;
}

void GameData::resetGame() {
    player.reset();
    recordT.setString("RECORD: " + strApp);
    meters = 0;
    xL1 = 0;
    xL2 = 600;
    rangeSpawn = 2;
    enemyVX = -1.3;
    spawnPUP = 1;
    objectVelX = 30;
    countE = 1;
    contrTakeObj = false;
    swordTake = false;
    countKill = 0;
    countSP = 0;
    countPP = 0;
    contrSaveR = false;
    powerUpGui.setPositionX(2000);
    c.restart();

    for (int i = 0; i < enemies.size(); i++) {
        deleteEnemy(i);
    }


}
