#include "../include/Game.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
Game::Game()
: window(sf::VideoMode(1280,720), "Royal Escape")
{
    window.setFramerateLimit(60);
    srand(static_cast<unsigned>(time(nullptr)));

    // Game variables
    score = 0;
    diamondsCollected = 0;
    level = 1;
    lives = 3;
    gameOver = false;
    gameWon = false;

    // Load font FIRST
    if(!font.loadFromFile("../assets/arial.ttf"))
    {
        std::cout << "Failed to load font!\n";
    }

    // Score Text
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(20.f, 20.f);
    scoreText.setString("Score : 0");

    // Diamond Text
    diamondText.setFont(font);
    diamondText.setCharacterSize(30);
    diamondText.setFillColor(sf::Color::Yellow);
    diamondText.setPosition(20.f, 60.f);
    diamondText.setString("Diamonds : 0 / 10");

    // Level Text
    levelText.setFont(font);
    levelText.setCharacterSize(30);
    levelText.setFillColor(sf::Color::Cyan);
    levelText.setPosition(20.f, 100.f);
    levelText.setString("Level : 1");

    // Lives Text
livesText.setFont(font);
livesText.setCharacterSize(30);
livesText.setFillColor(sf::Color::Red);
livesText.setPosition(20.f,140.f);
livesText.setString("Lives : 3");

    // Create objects
    createDiamonds();
    createObstacles();
}
void Game::createDiamonds()
{
    diamonds.clear();

    for(int i=0;i<5;i++)
    {
        sf::CircleShape d(12.f);
        d.setFillColor(sf::Color::Cyan);

        d.setPosition(
            rand()%1180+50,
            rand()%620+50
        );

        diamonds.push_back(d);
    }
}

void Game::createObstacles()
{
    obstacles.clear();

    for(int i=0;i<5 + level;i++)
    {
        sf::RectangleShape r;

        r.setSize(sf::Vector2f(70.f,70.f));
        r.setFillColor(sf::Color::Red);

        r.setPosition(
            rand()%1100+80,
            rand()%560+80
        );

        obstacles.push_back(r);
    }
}

void Game::processEvents()
{
    sf::Event event;
  

    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();

        if(event.type == sf::Event::KeyPressed)
        {
            if(gameOver && event.key.code == sf::Keyboard::R)
            {
                restart();
            }
        }
    }
}

void Game::update(float dt)
{
    if(gameOver)
        return;

    player.handleInput(dt);

    checkCollision();

    scoreText.setString("Score : " + std::to_string(score));

diamondText.setString(
    "Diamonds : " +
    std::to_string(diamondsCollected) +
    "/10"
);

levelText.setString(
    "Level : " + std::to_string(level)
);

livesText.setString(
    "Lives : " + std::to_string(lives)
);
}

void Game::checkCollision()
{
    for(auto &d : diamonds)
    {
        if(player.getBounds().intersects(d.getGlobalBounds()))
        {
            score += 10;
            diamondsCollected++;

            d.setPosition(
                rand()%1180+50,
                rand()%620+50
            );
        }
    }

   for(auto &o : obstacles)
{
    if(player.getBounds().intersects(o.getGlobalBounds()))
    {
        lives--;

player.setPosition(100.f,300.f);

createObstacles();

if(lives <= 0)
{
    gameOver = true;
}

break;
    }
}

if(diamondsCollected >= 10)
{
    level++;
    diamondsCollected = 0;

    player.setPosition(100.f,300.f);

    createDiamonds();
    createObstacles();

    if(level > 10)
    {
        gameWon = true;
        gameOver = true;
    }
}
}

void Game::render()
{
    window.clear(sf::Color(40,170,40));

    for(auto &d : diamonds)
        window.draw(d);

    for(auto &o : obstacles)
        window.draw(o);

    player.draw(window);

    window.draw(scoreText);
    window.draw(diamondText);
    window.draw(levelText);
    window.draw(livesText);

    if(gameOver)
    {
        sf::RectangleShape overlay(sf::Vector2f(1280,720));
        overlay.setFillColor(sf::Color(0,0,0,180));
        window.draw(overlay);

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::White);

        if(gameWon)
        {
            text.setString("YOU ESCAPED!\n\nPress R to Play Again");
        }
        else
        {
            text.setString("GAME OVER\n\nPress R to Restart");
        }

        text.setPosition(300.f,250.f);
        window.draw(text);
    }

    window.display();
}

void Game::restart()
{
    score = 0;
    diamondsCollected = 0;
    level = 1;
    lives = 3;

    gameOver = false;
    gameWon = false;

    player.setPosition(100.f,300.f);

    createDiamonds();
    createObstacles();
}

void Game::run()
{
    sf::Clock clock;

    while(window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        processEvents();
        update(dt);
        render();
    }
}