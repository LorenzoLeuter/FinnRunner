#include "GameTest.h"

void GameTest::GameRunningTest() {
    while (GD.running()) {
        double start = clock() / CLOCKS_PER_SEC;
        GD.update();
        if (GD.isInGame()) {
            GD.renderGame();
        } else {
            exit(0);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds((int) start + MS_PER_FRAME - (clock() / CLOCKS_PER_SEC)));
    }
}
