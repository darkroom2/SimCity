//
// Created by radekk on 25.03.2020.
//

#ifndef SIMCITY_GAME_H
#define SIMCITY_GAME_H

#include <map>
#include "Player.h"
#include "Object.h"

/*
 * Class that acts as the game engine.
 * Wrapper for SFML stuff.
 */
class Game {
    // private variables
    sf::RenderWindow *window = nullptr;

    std::map<char, std::string> my_map = {
            {'#', "STONE"},
            {'T', "TREE"},
            {'.', "GRASS"}
    };

    std::map<std::string, sf::Texture *> textures;

    sf::Event event{};
    std::string title;
    sf::Clock deltaClock;
    float gui_scale_factor = 0.0f;

    // game objects
    Player *player;
    std::vector<Object *> game_objects;
    // map object
    std::vector<sf::Texture *> vMap;
    std::string sMap;

    int nMapWidth;
    int nMapHeight;

    float fPlayerPosX = 0.0f;
    float fPlayerPosY = 0.0f;

    float fPlayerVelX = 0.0f;
    float fPlayerVelY = 0.0f;

    float fCameraPosX = 0.0f;
    float fCameraPosY = 0.0f;

    std::vector<std::tuple<std::string, bool>> plans = {{"Jakies",  false},
                                                        {"Bzdety",  false},
                                                        {"Glupoty", false}};

    // private functions
    void initVariables();

    void initWindow();

    void initTextures();

    void initPlayer();

    void initMap();

    void pollEvents();

    void updateInput();

    void updateObjects();

    void updateMap(); // TODO: this updates camera (change name)
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