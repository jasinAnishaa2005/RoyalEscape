cmake_minimum_required(VERSION 3.16)

project(RoyalEscape)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "/usr/local/opt/sfml@2/lib/cmake/SFML")

find_package(SFML 2.6 REQUIRED COMPONENTS
    graphics
    window
    system
    audio
)

include_directories(include)

add_executable(RoyalEscape
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
)

target_link_libraries(RoyalEscape
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)