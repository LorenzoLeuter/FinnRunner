#ifndef FINNRUNNER_GAMETEST_H
#define FINNRUNNER_GAMETEST_H

#include "gtest/gtest.h"
#include "../GameData.h"
#include <thread>
#include <ctime>
#include <chrono>

class GameTest : public ::testing::Test {
protected:

    void GameRunningTest();

    int FPS = 30;
    int MS_PER_FRAME = 1 / FPS;
    GameData GD;
    Hero cazzo;
};


#endif //FINNRUNNER_GAMETEST_H
