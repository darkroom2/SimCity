cmake_minimum_required(VERSION 3.15)
project(SimCity)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimCity main.cpp Game.cpp Game.h Player.cpp Player.h Object.cpp Object.h UserInterface.cpp UserInterface.h)

find_package(ImGui-SFML REQUIRED)
target_link_libraries(SimCity PRIVATE ImGui-SFML::ImGui-SFML)