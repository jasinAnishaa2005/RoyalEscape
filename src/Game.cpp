#include "../include/Game.hpp"
#include <optional>

Game::Game()
    : window(sf::VideoMode({1280, 720}), "Royal Escape")
{
    window.setFramerateLimit(60);
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update()
{
}

void Game::render()
{
    window.clear();

    // ===== Night Sky =====
    sf::RectangleShape sky({1280.f,720.f});
    sky.setFillColor(sf::Color(12,16,40));
    window.draw(sky);
    // ================= MOON =================
sf::CircleShape moon(45.f);
moon.setFillColor(sf::Color(250, 250, 220));
moon.setPosition({980.f, 70.f});

window.draw(moon);

// ================= STARS =================
for (int i = 0; i < 80; i++)
{
    sf::CircleShape star(1.5f);

    star.setFillColor(sf::Color::White);

    float x = rand() % 1280;
    float y = rand() % 220;

    star.setPosition({x, y});

    window.draw(star);
}

// ================= FOREST =================
for(int i=0;i<22;i++)
{
    sf::CircleShape leaves(45);

    leaves.setFillColor(sf::Color(20,70,20));

    leaves.setPosition({i*65.f,230.f});

    window.draw(leaves);

    sf::RectangleShape trunk({18.f,80.f});

    trunk.setFillColor(sf::Color(80,40,10));

    trunk.setPosition({i*65.f+35.f,270.f});

    window.draw(trunk);
}

// ================= RIVER =================
sf::RectangleShape river({1280.f,110.f});

river.setPosition({0.f,540.f});

river.setFillColor(sf::Color(35,90,180));

window.draw(river);

// ================= ROAD =================
sf::ConvexShape road;

road.setPointCount(4);

road.setPoint(0,{510.f,720.f});
road.setPoint(1,{770.f,720.f});
road.setPoint(2,{700.f,260.f});
road.setPoint(3,{580.f,260.f});

road.setFillColor(sf::Color(120,120,120));

window.draw(road);

// ================= CASTLE =================
sf::RectangleShape castle({170.f,140.f});

castle.setPosition({555.f,120.f});

castle.setFillColor(sf::Color(90,90,100));

window.draw(castle);



    window.display();
}