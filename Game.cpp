//
// Created by radekk on 25.03.2020.
//

#include "Game.h"

// private functions
void Game::initVariables() {
    this->window = nullptr;
    this->title = "SimCity 2137";
    this->gui_scale_factor = 2.0f;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), this->title);
    this->window->setVerticalSyncEnabled(true);
    ImGui::SFML::Init(*this->window);

    ImGui::GetStyle().ScaleAllSizes(this->gui_scale_factor);
    ImGui::GetIO().FontGlobalScale = this->gui_scale_factor;
}

void Game::initPlayer() {
    this->player = new Player();
}

void Game::initTextures() {
    this->textures["BUILDING"] = new sf::Texture();
    this->textures["BUILDING"]->loadFromFile("../Textures/buildings/building_1/building_8.png");
    this->textures["GRASS"] = new sf::Texture();
    this->textures["GRASS"]->loadFromFile("../Textures/land/land_1.png");
    this->textures["TREE"] = new sf::Texture();
    this->textures["TREE"]->loadFromFile("../Textures/decor/tree_1.png");
    this->textures["STONE"] = new sf::Texture();
    this->textures["STONE"]->loadFromFile("../Textures/decor/stones_1.png");
}

void Game::initMap() {
    this->nMapWidth = 64;
    this->nMapHeight = 64;
    this->sMap += "................................................................";
    this->sMap += "................................................................";
    this->sMap += "................................................................";
    this->sMap += "......#................#######..................................";
    this->sMap += "......................#.........#.#.............................";
    this->sMap += "...................####.........#.#.............................";
    this->sMap += "...........##############.......................................";
    this->sMap += ".#############################.##################..#####........";
    this->sMap += ".............................#.#..................#.............";
    this->sMap += ".............................#.#.................#..............";
    this->sMap += ".............................#.#................#...............";
    this->sMap += ".........................#####.#...............#................";
    this->sMap += ".........................#.....#..............#.................";
    this->sMap += ".........................#.#####.............#..................";
    this->sMap += ".........................#..................#...................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###.....###########....................";
    this->sMap += ".........................###.....###########....................";
    this->sMap += ".........................###.....###########....................";
    this->sMap += ".........................###.....###########....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................#########.......###....................";
    this->sMap += ".........................#########.......###....................";
    this->sMap += ".........................#########.......###....................";
    this->sMap += ".........................#########.......###....................";
    this->sMap += ".........................#########.......###....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###........########....................";
    this->sMap += ".........................###........########....................";
    this->sMap += ".........................###........########....................";
    this->sMap += ".........................###........########....................";
    this->sMap += ".........................###........########....................";
    this->sMap += ".........................###........########....................";
    this->sMap += ".........................###........########....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###########......##....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###################....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###.......#########....................";
    this->sMap += ".........................###################....................";
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        ImGui::SFML::ProcessEvent(this->event);
        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }
        if (this->event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
        }
    }
}

// ctors & dtors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initTextures();
    this->initPlayer();
    this->initMap();
}

Game::~Game() {
    ImGui::SFML::Shutdown();
    delete this->window;
    delete this->player;

    for (const auto &i : textures) {
        delete i.second;
    }

    for (const auto &i : game_objects) {
        delete i;
    }
}

// accessors

// public functions
void Game::run() {
    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}

void Game::update() {
    this->pollEvents();
    this->updateInput();
    this->updateObjects();
    this->updateMap();
    ImGui::SFML::Update(*this->window, this->deltaClock.restart());
}

void Game::updateInput() {
    this->fPlayerVelX = 0.f;
    this->fPlayerVelY = 0.f;

    // move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->fPlayerVelY = -1.f;
    //this->player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->fPlayerVelY = 1.f;
    //this->player->move(0.f, 1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->fPlayerVelX = -1.f;
    //this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->fPlayerVelX = 1.f;
    //this->player->move(1.f, 0.f);

    fPlayerPosX = fPlayerPosX + fPlayerVelX * 0.2f;
    fPlayerPosY = fPlayerPosY + fPlayerVelY * 0.2f; // TODO: get elapsed time here

//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//        this->game_objects.push_back(new Object(this->textures["BUILDING"], sf::Mouse::getPosition(*this->window).x,
//                                           sf::Mouse::getPosition(*this->window).y, 0.f, 0.f, 1.f));
//    }

    fCameraPosX = fPlayerPosX;
    fCameraPosY = fPlayerPosY;
}

void Game::updateObjects() {
    for (auto *obj : this->game_objects) {
        obj->update();
    }
}

void Game::updateMap() {
    // lambda for accessing string as a 2d array
    auto GetTile = [&](int x, int y) {
        if (x >= 0 && x < nMapWidth && y >= 0 && y < nMapHeight)
            return sMap[y * nMapWidth + x];
        else
            return ' ';
    };

    auto SetTile = [&](int x, int y, char c) {
        if (x >= 0 && x < nMapWidth && y >= 0 && y < nMapHeight)
            sMap[y * nMapWidth + x] = c;
    };

    int nTileWidth = 32;
    int nTileHeight = 32;
    int nVisibleTilesX = this->window->getSize().x / nTileWidth;
    int nVisibleTilesY = this->window->getSize().y / nTileHeight;

    // leftmost tile position
    float fOffsetX = fCameraPosX - (float) nVisibleTilesX / 2.0f;
    float fOffsetY = fCameraPosY - (float) nVisibleTilesY / 2.0f;

    // clamp camera to game bounds
    if (fOffsetX < 0) fOffsetX = 0;
    if (fOffsetY < 0) fOffsetY = 0;
    if (fOffsetX > nMapWidth - nVisibleTilesX) fOffsetX = nMapWidth - nVisibleTilesX;
    if (fOffsetY > nMapHeight - nVisibleTilesY) fOffsetY = nMapHeight - nVisibleTilesY;

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(nTileWidth, nTileHeight));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(2);

    this->window->clear(sf::Color::White);
    // draw visible tile map TODO: rozdzielic renderowanie od aktualizowania
    for (int x = -1; x < nVisibleTilesX + 1; ++x) {
        for (int y = -1; y < nVisibleTilesY + 1; ++y) {
            char tileID = GetTile(x + fOffsetX, y + fOffsetY);
            rectangle.setPosition(x * nTileWidth, y * nTileHeight);
            switch (tileID) {
                case '.':
                    rectangle.setFillColor(sf::Color::Cyan);
                    this->window->draw(rectangle);
                    break;
                case '#':
                    rectangle.setFillColor(sf::Color::Red);
                    this->window->draw(rectangle);
                    break;
                case 'T':
                    rectangle.setFillColor(sf::Color::Green);
                    this->window->draw(rectangle);
                    break;
                default:
                    break;
            }
        }
    }

    // draw player
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setPosition((fPlayerPosX - fOffsetX) * nTileWidth, (fPlayerPosY - fOffsetY) * nTileHeight);
    this->window->draw(rectangle);

}

void Game::render() {

    //this->window->clear(sf::Color::White); TODO:uncomment and remove it from update()

    // render objects here
    this->player->render(*this->window);

    for (auto *obj : this->game_objects) {
        obj->render(*this->window);
    }

    ImGui::Begin("Panel misji"); // begin window
    for (size_t idx = 1; auto &[str, state] : this->plans) {
        ImGui::Checkbox((std::to_string(idx) + std::string(": ") + str).c_str(), &state);
        ++idx;
    }
    ImGui::Button("Ukoncz misje");
    ImGui::End(); // end window

    ImGui::SFML::Render(*this->window);
    this->window->display();
}







