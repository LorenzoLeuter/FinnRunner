#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "Achievement.h"

#include <thread>
#include <ctime>
#include <chrono>

int main() {

    GameData gd;
    Achievement a = Achievement(&gd);
    gd.drawMenu();

    int FPS = 30;
    int MS_PER_FRAME = 1 / FPS;

    //GAME LOOP
    while (gd.running()){ //CONTROLLO DELLA FINESTRA DI GIOCO SE E' APERTA
        double start = clock() / CLOCKS_PER_SEC;
        gd.update(); //IL CORPO DEL GIOCO
        if(gd.isInGame()){ //SE IL PLAYER STA GIOCANDO OPPURE NO
            gd.renderGame();
        }else{
            gd.renderMenu();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds((int) start + MS_PER_FRAME - (clock() / CLOCKS_PER_SEC)));
    }
}
