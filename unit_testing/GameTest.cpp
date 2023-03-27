#include "gtest/gtest.h"
#include "../GameData.h"

class GameTest : public ::testing::Test{
protected:
    GameData gdt;
    int x = 2;
};

TEST_F(GameTest, testDeleteEnemy) {
    ASSERT_EQ(x, 2);
    for (int i = 0; i < gdt.getEnemySize(); i++) {
        if (gdt.enemies[i]->getPositionX() == 130) {
            gdt.deleteEnemy(i);
        }
    }
}
