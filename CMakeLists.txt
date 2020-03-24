cmake_minimum_required(VERSION 3.15)
project(SimCity)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimCity main.cpp)

find_package(ImGui-SFML REQUIRED)
target_link_libraries(SimCity PRIVATE ImGui-SFML::ImGui-SFML)