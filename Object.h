//
// Created by radekk on 25.03.2020.
//

#ifndef SIMCITY_OBJECT_H
#define SIMCITY_OBJECT_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Object {
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float moveSpeed;

public:
    Object(sf::Texture *_texture, float _posX, float _poxY, float _dirX, float _dirY, float _moveSpeed);

    Object();

    virtual ~Object();

    // accessors
    sf::FloatRect getBounds() const;

    void update();

    void render(sf::RenderTarget &target);
};


#endif //SIMCITY_OBJECT_H
