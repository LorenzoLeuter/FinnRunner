#ifndef FINNRUNNER_ACHIEVEMENT_H
#define FINNRUNNER_ACHIEVEMENT_H

#include "Observer.h"
#include "DisplayElement.h"
#include "GameData.h"


class Achievement : public Observer, public DisplayElement {
public:
    Achievement(GameData *gameData);

    virtual ~Achievement();

    void update() override;

    void draw() override;

protected:
    int score;
    int cSP;
    int cPP;
    int cK;
    bool achievementNotActiveS;
    bool achievementNotActiveP;
    bool achievementNotActiveK;
    sf::Text text;
    sf::Clock achivmentGui;
    GameData *g;

};


#endif //FINNRUNNER_ACHIEVEMENT_H
