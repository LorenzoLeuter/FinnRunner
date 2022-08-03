//
// Created by lorenzoleuter on 06/07/22.
//

#ifndef FINN_RUNNER_GAMEDATA_H
#define FINN_RUNNER_GAMEDATA_H

#include "GameMap.h"

#define max_options 2

class GameData {

    public:

    virtual ~GameData();

    GameData();

    int getMeters() const;

    void setMeters(int meters);

    int getRecord() const;

    void setRecord(int record);

    bool isCharacterAlive() const;

    void setCharacterAlive(bool characterAlive);

    void restartGame();

    void drawMenu();

    void update();

    void render();

    const bool running();

    void renderMenu();

    bool isInGame() const;

private:

        //variables
        int meters;
        int record;
        bool character_alive;
        sf::RenderWindow* window;
        sf::Event event;
        sf::RectangleShape background;
        sf::RectangleShape background2;
        sf::Texture texture;
        sf::Texture titleTexture;
        sf::RectangleShape title;
        sf::Text menuOptions[max_options];
        int menuSelected;
        float xL1;
        float xL2;
        sf::Clock c;
        bool inGame;
        sf::Font font;
        GameMap map;

        //functions

        void initVariables();
        void initWindow();
};


#endif //FINN_RUNNER_GAMEDATA_H
