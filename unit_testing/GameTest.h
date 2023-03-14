#ifndef FINNRUNNER_GAMETEST_H
#define FINNRUNNER_GAMETEST_H

#include "gtest/gtest.h"
#include "../GameData.h"

class GameTest : public ::testing::Test {
protected:

    void GameRunningTest();
    GameData GD;
};


#endif //FINNRUNNER_GAMETEST_H
