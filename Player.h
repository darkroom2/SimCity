//
// Created by radekk on 25.03.2020.
//

#ifndef SIMCITY_PLAYER_H
#define SIMCITY_PLAYER_H

#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>

#include <iostream>

class Player { // TODO: zmienic nazwe na Camera i usunac Textury
private:
    sf::Texture texture;
    sf::Sprite sprite;

    float moveSpeed = 1.0f;

    // private functions
    void initTexture();

    void initSprite();

public:
    Player();

    virtual ~Player();

    // public functions
    void move(float dirX, float dirY);

    void update();

    void render(sf::RenderTarget &target);

};


#endif //SIMCITY_PLAYER_H
