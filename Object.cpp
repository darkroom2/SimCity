//
// Created by radekk on 25.03.2020.
//

#include "Object.h"

Object::Object(sf::Texture *_texture, float _posX, float _posY, float _dirX, float _dirY, float _moveSpeed) {
    this->shape.setTexture(*_texture);
    this->shape.setPosition(_posX, _posY);
    this->direction.x = _dirX;
    this->direction.y = _dirY;
    this->moveSpeed = _moveSpeed;
}

Object::Object() {

}

Object::~Object() {

}

void Object::update() {
    this->shape.move(this->moveSpeed * this->direction);
}

void Object::render(sf::RenderTarget &target) {
    target.draw(this->shape);
}

sf::FloatRect Object::getBounds() const {
    return this->shape.getGlobalBounds();
}