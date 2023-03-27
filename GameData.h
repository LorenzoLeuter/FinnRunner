#ifndef FINN_RUNNER_GAMEDATA_H
#define FINN_RUNNER_GAMEDATA_H

#define max_options 2
#define coolDownAttack 0.75

#include <fstream>
#include "Hero.h"
#include "Subject.h"
#include "list"
#include "vector"
#include "ZombieToast.h"
#include "Bat.h"
#include "PowerUpFactory.h"
#include <iostream>


class GameData : public Subject {

public:

    GameData();

    virtual ~GameData();

    int getMeters() const;

    int getRecord();

    int getCountSp() const;

    int getCountPp() const;

    int getCountKill() const;

    bool setRecord();

    bool isInGame() const;

    const bool running();

    void drawMenu();

    void update();

    void renderGame();

    void renderMenu();

    void deathScreen();

    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notifyObservers() const override;

    void setAchievementTxt(std::string achievement);

    int getEnemySize();

    void deleteEnemy(int posList);
    std::vector<std::unique_ptr<GameCharacter>> enemies;

private:

    //variables
    int spawnPUP;
    int meters;
    int menuSelected;
    int countE;
    int countKill; //numero di uccisioni
    int countSP; // numero di spade prese
    int countPP; //numero di pozioni prese
    int x_title = 0, y_title = 0;
    int x_sword = -1200, y_sword = -45;
    float xL1;
    float xL2;
    float rangeSpawn;
    float enemyVX;
    float objectVelX;
    bool inGame;
    bool swordTake;
    bool contr;
    bool contrTakeObj;
    bool sis;
    bool contrSaveR;
    const std::string defaultS;
    std::vector<char> record;
    std::list<Observer *> observers;
    std::FILE *f;
    std::string strApp;
    sf::RenderWindow *window;
    sf::Event event;
    sf::RectangleShape background;
    sf::RectangleShape background2;
    sf::RectangleShape title;
    sf::Font font;
    sf::Texture z;
    sf::Texture b;
    sf::Texture swords_texture;
    sf::Texture potion;
    sf::Texture explosion_txt;
    sf::Texture title_sword_txt;
    sf::Texture textureB;
    sf::Texture titleTexture;
    sf::IntRect rectSourceSpriteSwords{0, 0, 32, 32};
    sf::IntRect rectSourceSprite_sword{32, 0, 32, 32};
    sf::IntRect rectSourceSpriteExplosion{0, 0, 48, 48};
    sf::RectangleShape title_sword;
    sf::Text txt;
    sf::Text deathOptions[2];
    sf::Text metersDeath;
    sf::Text recordDeath;
    sf::Text menuOptions[max_options];
    sf::Text score;
    sf::Text recordT;
    sf::Text achievementTxt;
    sf::Clock clock;
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock attackingTime;
    sf::Clock frameRate;
    sf::Clock enemySpawn;
    sf::Clock c;
    sf::Clock cs;
    sf::Sprite explosion;
    sf::Sprite swords[3];
    sf::Image icon;
    Hero player;
    PowerUpFactory powerUpGui = PowerUpFactory(0);
    PowerUp powerUp;

    //functions
    void initGuiVariables();

    void initWindow();

    void backgroundLoop();

    void scoreUpdate();

    void createEnemy();

    void setObjectVelocity();

    void resetGame();


};


#endif //FINN_RUNNER_GAMEDATA_H
