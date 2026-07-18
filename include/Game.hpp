#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"

enum class GameState
{
    MENU,
    PLAYING,
    GAMEOVER
};

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    sf::View camera;

    GameState state;

    Player player;

    sf::Texture bgTexture;
    sf::Sprite background;
};

#endif