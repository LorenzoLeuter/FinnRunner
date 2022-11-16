#ifndef FINN_RUNNER_GAMEDATA_H
#define FINN_RUNNER_GAMEDATA_H

#define max_options 2
#define coolDownAttack 1.25

#include "Hero.h"
#include "Subject.h"
#include "list"
#include "vector"
#include "ZombieToast.h"
#include "Bat.h"
#include "PowerUpFactory.h"


class GameData : public Subject {

    public:

        virtual ~GameData();  //todo FARE IL DISTRUTTORE QUANDO IL PLAYER MUORE E TORNA AL MENU
        GameData();
        int getMeters() const;
        void setMeters(int meters);
        int getRecord() const;
        void setRecord(int record);
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

    private:

        //variables
        float gameVelocity;
        int meters;
        int record;
        bool character_alive;
        sf::RenderWindow* window;
        sf::Event event;
        sf::RectangleShape background;
        sf::RectangleShape background2;
        sf::Texture textureB;
        sf::Texture titleTexture;
        sf::RectangleShape title;
        sf::Text menuOptions[max_options];
        sf::Text score;
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
        float blVel;
        float rangeSpawn;
        sf::Clock enemySpawn;
        sf::Text achievementTxt;
        float enemyVX;
        sf::Clock attackingTime;
        sf::Clock frameRate;
        sf::Sprite swords[3];
        sf::Texture swords_texture;
        sf::IntRect rectSourceSpriteSwords{0, 0, 32, 32};
        int sword_counter = 3;
        PowerUpFactory sword;
        sf::Texture z;
        sf::Texture b;


        //functions
        void initGuiVariables();
        void initWindow();
        void backgroundLoop();
        void scoreUpdate();
        void createEnemy();
        void deleteEnemy(int posList);
        void setBackgroundVelocity();
        void setEnemyVelocity();
};


#endif //FINN_RUNNER_GAMEDATA_H
