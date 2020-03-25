//
// Created by radekk on 25.03.2020.
//

#ifndef SIMCITY_GAME_H
#define SIMCITY_GAME_H

#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

/*
 * Class that acts as the game engine.
 * Wrapper for SFML stuff.
 */
class Game {
private:
    // variables
    sf::RenderWindow *window = nullptr;
    sf::Event event{};
    std::string title;
    sf::Clock deltaClock;
    float scale_factor = 0.0f;

    // game objects
    sf::RectangleShape building;

    std::vector<std::tuple<std::string, bool>> plans = {{"Jakies",  false},
                                                        {"Bzdety",  false},
                                                        {"Glupoty", false}};

    // private functions
    void initVariables();

    void initWindow();

    void initBuildings();

    void pollEvents();

    void update();

    void render();

public:
    // ctors & dtors
    Game();

    virtual ~Game();

    // accessors

    // functions
    void run();
};


#endif //SIMCITY_GAME_H