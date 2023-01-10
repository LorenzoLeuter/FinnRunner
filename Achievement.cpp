#include "Achievement.h"

Achievement::Achievement(GameData *gameData): g(gameData),score(0) {
    g->registerObserver(this);
}

Achievement::~Achievement() {
    g->removeObserver(this);
}

void Achievement::update() {
    score = g->getMeters();
    draw();
}


void Achievement::draw() {
    if(score == 25){
        g->setAchievementTxt("PARTIRE DALLE BASI");
        achivmentGui.restart();
    }else if(score == 50){
        g->setAchievementTxt("PROCEDERE PER GRADI");
        achivmentGui.restart();
    }else if(score == 100){
        g->setAchievementTxt("VELOCISTA ESPERTO");
        achivmentGui.restart();
    }else if(score == 300){
        g->setAchievementTxt("MAESTRO DELLA VELOCITA'");
        achivmentGui.restart();
    }else if(score == 500){
        g->setAchievementTxt("ESSERE VELOCITA'");
        achivmentGui.restart();
    }
    if(achivmentGui.getElapsedTime().asSeconds() > 2.50){
        g->setAchievementTxt("");
    }
}
