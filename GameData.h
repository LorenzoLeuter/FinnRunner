//
// Created by lorenzoleuter on 06/07/22.
//

#ifndef FINN_RUNNER_GAMEDATA_H
#define FINN_RUNNER_GAMEDATA_H


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

private:

        //variables
        int meters;
        int record;
        bool character_alive;
        sf::RenderWindow* window;
        sf::Event event;

        //functions

        void initVariables();
        void initWindow();
};


#endif //FINN_RUNNER_GAMEDATA_H
