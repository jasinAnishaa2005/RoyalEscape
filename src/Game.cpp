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
    requiredDiamonds = 10;
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

collectBuffer.loadFromFile("../assets/audio/collect.wav");
hitBuffer.loadFromFile("../assets/audio/hit.wav");
levelBuffer.loadFromFile("../assets/audio/levelup.wav");
gameOverBuffer.loadFromFile("../assets/audio/gameover.wav");

music.openFromFile("../assets/audio/background.wav");

collectSound.setBuffer(collectBuffer);
hitSound.setBuffer(hitBuffer);
levelSound.setBuffer(levelBuffer);
gameOverSound.setBuffer(gameOverBuffer);

music.setLoop(true);
music.setVolume(35);
music.play();

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
    "/" +
    std::to_string(requiredDiamonds)
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
            collectSound.play();
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
        hitSound.play();
player.setPosition(100.f,300.f);

createObstacles();

if(lives <= 0)
{
    gameOver = true;
}

break;
    }
}

if(diamondsCollected >= requiredDiamonds)
{
  level++;
  levelSound.play();

// Reset level progress
score = 0;
diamondsCollected = 0;

// Increase target
requiredDiamonds *= 2;

// Reset player
player.setPosition(100.f,300.f);

// Create new level
createDiamonds();
createObstacles();

if(level > 10)
{
    gameWon = true;
    gameOverSound.play();
    gameOver = true;

}
}
}
void Game::render()
{
    window.clear();

    // Sky
    sf::RectangleShape sky(sf::Vector2f(1280,250));
    sky.setFillColor(sf::Color(120,180,255));
    window.draw(sky);

    // Grass
    sf::RectangleShape grass(sf::Vector2f(1280,470));
    grass.setPosition(0,250);
    grass.setFillColor(sf::Color(60,160,60));
    window.draw(grass);

    // Road
    sf::RectangleShape road(sf::Vector2f(220,720));
    road.setPosition(530,0);
    road.setFillColor(sf::Color(120,90,60));
    window.draw(road);

    // River
    sf::RectangleShape river(sf::Vector2f(150,720));
    river.setPosition(1080,0);
    river.setFillColor(sf::Color(30,140,255));
    window.draw(river);

    // Castle
    sf::RectangleShape castle(sf::Vector2f(1280,80));
    castle.setFillColor(sf::Color(120,120,120));
    window.draw(castle);

    // Towers
    sf::RectangleShape leftTower(sf::Vector2f(80,160));
    leftTower.setPosition(50,90);
    leftTower.setFillColor(sf::Color(100,100,100));
    window.draw(leftTower);

    sf::RectangleShape rightTower(sf::Vector2f(80,160));
    rightTower.setPosition(1150,90);
    rightTower.setFillColor(sf::Color(100,100,100));
    window.draw(rightTower);

    // Clouds
    sf::CircleShape c1(30);
    c1.setFillColor(sf::Color::White);
    c1.setPosition(120,40);

    sf::CircleShape c2(25);
    c2.setFillColor(sf::Color::White);
    c2.setPosition(150,25);

    sf::CircleShape c3(30);
    c3.setFillColor(sf::Color::White);
    c3.setPosition(180,40);

    window.draw(c1);
    window.draw(c2);
    window.draw(c3);

    // Trees
    auto drawTree = [&](float x,float y)
    {
        sf::RectangleShape trunk(sf::Vector2f(20,45));
        trunk.setPosition(x,y);
        trunk.setFillColor(sf::Color(120,70,20));

        sf::CircleShape leaves(28);
        leaves.setFillColor(sf::Color(20,130,20));
        leaves.setPosition(x-18,y-35);

        window.draw(trunk);
        window.draw(leaves);
    };

    drawTree(80,300);
    drawTree(220,500);
    drawTree(930,260);
    drawTree(990,430);

    // Diamonds
    for(auto &diamond : diamonds)
    {
        sf::ConvexShape gem;
        gem.setPointCount(4);

        gem.setPoint(0,{10,0});
        gem.setPoint(1,{20,10});
        gem.setPoint(2,{10,20});
        gem.setPoint(3,{0,10});

        gem.setFillColor(sf::Color::Cyan);
        gem.setOutlineThickness(2);
        gem.setOutlineColor(sf::Color::White);

        gem.setPosition(diamond.getPosition());

        window.draw(gem);
    }

    // Obstacles
    for(auto &o : obstacles)
        window.draw(o);

    // Player
    player.draw(window);

    // HUD
    window.draw(scoreText);
    window.draw(diamondText);
    window.draw(levelText);
    window.draw(livesText);

    // Game Over
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
            text.setString("YOU ESCAPED!\n\nPress R to Play Again");
        else
            text.setString("GAME OVER\n\nPress R to Restart");

        text.setPosition(280,250);
        window.draw(text);
    }

    window.display();
}
void Game::restart()
{
    score = 0;
    diamondsCollected = 0;
    requiredDiamonds = 10;
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