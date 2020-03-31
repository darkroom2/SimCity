cmake_minimum_required(VERSION 3.15)
project(SimCity)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    set(ImGui-SFML_DIR "C:/Users/Radek/Libraries/imgui_sfml/lib/cmake/ImGui-SFML")
    set(SFML_DIR "C:/Users/Radek/Libraries/SFML-2.5.1/lib/cmake/SFML")
    find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
endif ()

add_executable(SimCity main.cpp Game.cpp Game.h Player.cpp Player.h Object.cpp Object.h UserInterface.cpp UserInterface.h)

find_package(ImGui-SFML REQUIRED)
target_link_libraries(SimCity PRIVATE ImGui-SFML::ImGui-SFML)