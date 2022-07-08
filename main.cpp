#include <SFML/Graphics.hpp>
#include "GameData.h"

int main() {

    GameData gd;

    while (gd.running()){
        gd.update();
        gd.render();
    }
}
