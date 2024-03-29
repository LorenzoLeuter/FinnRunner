#include "Achievement.h"

Achievement::Achievement(GameData *gameData) : g(gameData), score(0), cSP(0), cPP(0), cK(0) {
    g->registerObserver(this);
}

Achievement::~Achievement() {
    g->removeObserver(this);
}

void Achievement::update() {
    score = g->getMeters();
    cSP = g->getCountSp();
    cPP = g->getCountPp();
    cK = g->getCountKill();
    draw();
}


void Achievement::draw() {
    //SCORE ACHIEVEMENT
    if (score == 100) {
        g->setAchievementTxt("VELOCISTA ESPERTO");
        achivmentGui.restart();
    } else if (score == 300) {
        g->setAchievementTxt("MAESTRO DELLA VELOCITA'");
        achivmentGui.restart();
    } else if (score == 500) {
        g->setAchievementTxt("ESSERE VELOCITA'");
        achivmentGui.restart();
    }

    //ARMI PRESE

    if (cSP == 1 && achievementNotActiveS) {
        g->setAchievementTxt("PLAYER DALLE PRIME ARMI");
        achievementNotActiveS = false;
        achivmentGui.restart();
    } else if (cSP == 5 && achievementNotActiveS) {
        g->setAchievementTxt("FABBRO");
        achievementNotActiveS = false;
        achivmentGui.restart();
    } else if (cSP == 10 && achievementNotActiveS) {
        g->setAchievementTxt("FABBRO ESPERTO");
        achievementNotActiveS = false;
        achivmentGui.restart();
    } else if (cSP != 1 && cSP != 5 && cSP != 10) {
        achievementNotActiveS = true;
    }

    //POZIONI PRESE

    if (cPP == 1 && achievementNotActiveP) {
        g->setAchievementTxt("PRIMO VOLO");
        achievementNotActiveP = false;
        achivmentGui.restart();
    } else if (cPP == 5 && achievementNotActiveP) {
        g->setAchievementTxt("ESPERTO NEL SALTO IN ALTO");
        achievementNotActiveP = false;
        achivmentGui.restart();
    } else if (cPP == 10 && achievementNotActiveP) {
        g->setAchievementTxt("CONIGLIO ALCHIMISTA");
        achievementNotActiveP = false;
        achivmentGui.restart();
    } else if (cPP != 1 && cPP != 5 && cPP != 10) {
        achievementNotActiveP = true;
    }

    //NUMERO DI UCCISIONI EFFETTUATE

    if (cK == 1 && achievementNotActiveK) {
        g->setAchievementTxt("PRIMO SANGUE");
        achievementNotActiveK = false;
        achivmentGui.restart();
    } else if (cK == 5 && achievementNotActiveK) {
        g->setAchievementTxt("SANGUINARIO");
        achievementNotActiveK = false;
        achivmentGui.restart();
    } else if (cK == 10 && achievementNotActiveK) {
        g->setAchievementTxt("SENZA PIETA'");
        achievementNotActiveK = false;
        achivmentGui.restart();
    } else if (cK == 15 && achievementNotActiveK) {
        g->setAchievementTxt("SENZA ANIMA");
        achievementNotActiveK = false;
        achivmentGui.restart();
    } else if (cK == 20 && achievementNotActiveK) {
        g->setAchievementTxt("INSTANCABILE");
        achievementNotActiveK = false;
        achivmentGui.restart();
    } else if (cK != 1 && cK != 5 && cK != 10 && cK != 15 && cK != 20) {
        achievementNotActiveK = true;
    }

    if (achivmentGui.getElapsedTime().asSeconds() > 1.40) {
        g->setAchievementTxt("");
    }
}
