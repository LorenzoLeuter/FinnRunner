#include <SFML/Graphics.hpp>
#include "GameData.h"

int main() {

    GameData gd;
    gd.drawMenu();
    //GAME LOOP
    while (gd.running()){ //CONTROLLO DELLA FINESTRA DI GIOCO SE E' APERTA
        gd.update(); //IL CORPO DEL GIOCO
        if(gd.isInGame()){ //SE IL PLAYER STA GIOCANDO OPPURE NO
            gd.renderGame();
        }else{
            gd.renderMenu();
        }

    }
}
