//
// Created by radekk on 25.03.2020.
//

#include "Game.h"

// private functions
void Game::initVariables() {
    this->window = nullptr;
    this->title = "SimCity 2137";
    this->scale_factor = 2.0f;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), this->title);
    this->window->setVerticalSyncEnabled(true);
    ImGui::SFML::Init(*this->window);

    ImGui::GetStyle().ScaleAllSizes(this->scale_factor);
    ImGui::GetIO().FontGlobalScale = this->scale_factor;
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
    this->initBuildings();
}

Game::~Game() {
    ImGui::SFML::Shutdown();
    delete this->window;
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
    ImGui::SFML::Update(*this->window, this->deltaClock.restart());
}

void Game::render() {
    ImGui::Begin("Panel misji"); // begin window
    for (size_t idx = 1; auto &[str, state] : this->plans) {
        ImGui::Checkbox((std::to_string(idx) + std::string(": ") + str).c_str(), &state);
        ++idx;
    }
    ImGui::Button("Ukoncz misje");
    ImGui::End(); // end window

    this->window->clear();
    this->window->draw(this->building);
    ImGui::SFML::Render(*this->window);
    this->window->display();
}

void Game::initBuildings() {
    this->building.setPosition(10.f, 10.f);
    this->building.setSize(sf::Vector2f(100.f, 100.f));
    this->building.setFillColor(sf::Color::Red);
    this->building.setOutlineColor(sf::Color::Green);
    this->building.setOutlineThickness(1.f);
}
