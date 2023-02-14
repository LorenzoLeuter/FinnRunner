#ifndef FINN_RUNNER_GAMEDATA_H
#define FINN_RUNNER_GAMEDATA_H

#define max_options 2
#define coolDownAttack 1.5

#include <fstream>
#include "Hero.h"
#include "Subject.h"
#include "list"
#include "vector"
#include "ZombieToast.h"
#include "Bat.h"
#include "PowerUpFactory.h"
//#include "FileMgr.h"


class GameData : public Subject {

    public:

        virtual ~GameData();  //todo FARE IL DISTRUTTORE QUANDO IL PLAYER MUORE E TORNA AL MENU
        GameData();
        int getMeters() const;
        void setMeters(int meters);
        int getRecord();
        bool setRecord();
        bool isCharacterAlive() const;
        void setCharacterAlive(bool characterAlive);
        void restartGame(); //todo FARE IL RESTART GAME
        void drawMenu();
        void update();
        void renderGame();
        const bool running();
        void renderMenu();
        bool isInGame() const;
        void registerObserver(Observer *o) override;
        void removeObserver(Observer *o) override;
        void notifyObservers() const override;
        void setAchievementTxt(std::string achievement);
        int getCountSp() const;
        int getCountPp() const;

    int getCountKill() const;

private:

        //variables
        int spawnPUP;
        int meters;
        std::vector<char> record;
        bool character_alive;
        sf::RenderWindow* window;
        sf::Event event;
        sf::RectangleShape background;
        sf::RectangleShape background2;
        sf::Texture textureB;
        sf::Texture titleTexture;
        sf::Texture trophy;
        sf::RectangleShape title;
        sf::Text menuOptions[max_options];
        sf::Text score;
        sf::Text recordT;
        int menuSelected;
        float xL1;
        float xL2;
        bool inGame;
        sf::Font font;
        sf::Clock c;
        sf::Clock cs;
        Hero player;
        std::list<Observer*> observers;
        std::vector<std::unique_ptr<GameCharacter>> enemies;
        float rangeSpawn;
        sf::Clock enemySpawn;
        sf::RectangleShape achievementTrophy;
        sf::Text achievementTxt;
        float enemyVX;
        sf::Clock attackingTime;
        sf::Clock frameRate;
        sf::Sprite swords[3];
        bool swordTake;
        PowerUpFactory powerUpGui = PowerUpFactory(0);
        PowerUp powerUp;
        sf::Texture z;
        sf::Texture b;
        sf::Texture swords_texture;
        sf::Texture potion;
        sf::IntRect rectSourceSpriteSwords{0, 0, 32, 32};
        sf::IntRect rectSourceSprite_sword{32, 0, 32, 32};
        float objectVelX;
        bool contr;
        int countE;
        bool contrTakeObj;
        bool sis;
        const std::string defaultS;
        int countKill; //numero di uccisioni
        int countSP; // numero di spade prese
        int countPP; //numero di pozioni prese
        std::FILE * f;
        std::string strApp;
        bool contrSaveR;

        //functions
        void initGuiVariables();
        void initWindow();
        void backgroundLoop();
        void scoreUpdate();
        void createEnemy();
        void deleteEnemy(int posList);
        void setObjectVelocity();


};


#endif //FINN_RUNNER_GAMEDATA_H
