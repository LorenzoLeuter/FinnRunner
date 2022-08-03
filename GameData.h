//
// Created by lorenzoleuter on 06/07/22.
//

#ifndef FINN_RUNNER_GAMEDATA_H
#define FINN_RUNNER_GAMEDATA_H

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
        sf::RectangleShape backgroundGame;
        sf::Texture texture;
        sf::Texture titleTexture;
        sf::Texture gameTexture;
        sf::RectangleShape title;
        sf::Text menuOptions[max_options];
        int menuSelected;
        bool inGame;
        sf::Font font;



        //functions

        void initVariables();
        void initWindow();
};


#endif //FINN_RUNNER_GAMEDATA_H
