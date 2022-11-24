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
        int spawnPUP;
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
        float rangeSpawn;
        sf::Clock enemySpawn;
        sf::Text achievementTxt;
        float enemyVX;
        sf::Clock attackingTime;
        sf::Clock frameRate;
        sf::Sprite swords[3];
        int sword_counter = 3;
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
