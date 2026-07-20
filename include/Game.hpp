#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Player.hpp"

class Game
{
private:
    sf::RenderWindow window;

    // HUD
    sf::Font font;
    sf::Text scoreText;
    sf::Text diamondText;
    sf::Text levelText;
    sf::Text livesText;
    sf::SoundBuffer collectBuffer;
    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer levelBuffer;
    sf::SoundBuffer gameOverBuffer;
    sf::Music music;
    sf::Sound collectSound;
    sf::Sound hitSound;
    sf::Sound levelSound;
    sf::Sound gameOverSound;
    // Game
    Player player;

    std::vector<sf::CircleShape> diamonds;
    std::vector<sf::RectangleShape> obstacles;

    int score;
    int diamondsCollected;
    int level;
    int lives;
    int requiredDiamonds;

    bool gameOver;
    bool gameWon;

    void processEvents();
    void update(float dt);
    void render();

    void createDiamonds();
    void createObstacles();
    void checkCollision();
    void restart();

public:
    Game();
    void run();
};
#endif