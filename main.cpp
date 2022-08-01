#include <SFML/Graphics.hpp>
#include "GameData.h"

int main() {

    GameData gd;
    gd.drawMenu();
    while (gd.running()){
        gd.update();
        if(gd.isInGame()){
            gd.render();
        }else{
            gd.renderMenu();
        }

    }
}
