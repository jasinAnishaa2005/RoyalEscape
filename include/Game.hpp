#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

enum class GameState
{
    MENU,
    INTRO,
    PLAYING,
    GAMEOVER
};

class Game
{
private:

    sf::RenderWindow window;

    GameState gameState;

    sf::Font font;

public:

    Game();

    void run();

private:

    void processEvents();

    void update();

    void render();
};

#endif