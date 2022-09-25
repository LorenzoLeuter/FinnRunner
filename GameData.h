#ifndef FINN_RUNNER_GAMEDATA_H
#define FINN_RUNNER_GAMEDATA_H

#define max_options 2

#include "Hero.h"
#include "EnemyObject.h"

class GameData {

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
        float blVel;

        //functions
        void initGuiVariables();
        void initWindow();
        void backgroundLoop();
        void scoreUpdate();
};


#endif //FINN_RUNNER_GAMEDATA_H
