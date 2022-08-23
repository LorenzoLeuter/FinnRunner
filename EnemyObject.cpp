//
// Created by lorenzoleuter on 06/07/22.
//

#include "EnemyObject.h"


EnemyObject::EnemyObject(int enemy_type) {
    switch (enemy_type) {
        case 0:
            texture.loadFromFile("C:\\Users\\gabri\\CLionProjects\\FinnRunner\\assets\\ZombieToast.png");
            enemy_object.setTexture(texture);
            enemy_object.setPosition(10, 500);
            enemy_object.scale(2.5, 2.5);
            break;
        case 1:
            texture.loadFromFile("C:\\Users\\gabri\\CLionProjects\\FinnRunner\\assets\\BatMovement.png");
            enemy_object.setTexture(texture);
            enemy_object.setPosition(positionX, positionY);
            enemy_object.scale(2.5, 2.5);
            break;
    }
}

void EnemyObject::update() {
    positionX += velocityX * clock.getElapsedTime().asSeconds();

    enemy_object.setPosition(positionX, positionY);

}

void EnemyObject::animation(int enemy_type) {
    if (clock.getElapsedTime().asSeconds() > 0.06){
        switch (enemy_type) {
            case 0:
                if(rectSourceSprite_toast.left == 192) {
                    rectSourceSprite_toast.left = 64;
                }else {
                    rectSourceSprite_toast.left += 32;
                }
                enemy_object.setTextureRect(rectSourceSprite_toast);
                break;
            case 1:
                if(rectSourceSprite_toast.left == 160) {
                    rectSourceSprite_toast.left = 0;
                }else {
                    rectSourceSprite_toast.left += 32;
                }
                enemy_object.setTextureRect(rectSourceSprite_toast);
                break;
        }
        clock.restart();
    }

}