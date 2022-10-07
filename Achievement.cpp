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
    if(score == 15){
        g->setAchievementTxt("PARTIRE DALLE BASI");
    }else if(score == 21){
        g->setAchievementTxt("");
    }
}
