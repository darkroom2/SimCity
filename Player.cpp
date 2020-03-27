//
// Created by radekk on 25.03.2020.
//

#include "Player.h"

void Player::initTexture() {
    // load texture from file
    if (!this->texture.loadFromFile("../Textures/buildings/building_1/building_1.png")) {
        std::cout << "ERROR::Player::initTexture()::loadFromFile()" << '\n';
    }
}

void Player::initSprite() {
    // set the texture to the sprite
    this->sprite.setTexture(this->texture);

    //resize the sprite
    this->sprite.scale(.2f, .2f);
}

Player::Player() {
    this->initTexture();
    this->initSprite();
}

Player::~Player() {

}

void Player::update() {

}

void Player::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void Player::move(const float dirX, const float dirY) {
    this->sprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}