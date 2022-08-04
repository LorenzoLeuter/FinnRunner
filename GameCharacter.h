#ifndef FINN_RUNNER_GAMECHARACTER_H
#define FINN_RUNNER_GAMECHARACTER_H
#include <SFML/Graphics.hpp>

class GameCharacter{
public:
    GameCharacter();

    void getKilled();
    void moveAnimation();

    sf::Sprite getGameCharacter(){
        return game_character;
    }

private:
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite game_character;
    sf::Clock clock;
    sf::IntRect rectSourceSprite{0, 0, 32, 32};

};


#endif //FINN_RUNNER_GAMECHARACTER_H