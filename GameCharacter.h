#ifndef FINN_RUNNER_GAMECHARACTER_H
#define FINN_RUNNER_GAMECHARACTER_H
#include <SFML/Graphics.hpp>

class GameCharacter{
    public:
        GameCharacter();
        void getKilled();
        void setDirection(const sf::Vector2f& dir);
        void Update(float dt);
        sf::Sprite getGameCharacter(){
            return game_character;
        }
    private:
        float speed = 1.0f;
        sf::Vector2f pos;
        sf::Vector2f vel = {0.0f, 0.0f};
        sf::Texture texture;
        sf::Sprite game_character;


};


#endif //FINN_RUNNER_GAMECHARACTER_H
