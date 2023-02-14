#ifndef FINNRUNNER_ACHIEVEMENT_H
#define FINNRUNNER_ACHIEVEMENT_H

#include "Observer.h"
#include "DisplayElement.h"
#include "GameData.h"


class Achievement : public Observer, public DisplayElement{
    public:
        Achievement(GameData * gameData);
        virtual ~Achievement();
        void update() override;
        void draw() override;
    protected:
        int score;
        sf::Text text;
        GameData * g;
        sf::Clock achivmentGui;
};


#endif //FINNRUNNER_ACHIEVEMENT_H
