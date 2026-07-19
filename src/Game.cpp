
#include "../include/Game.hpp"
#include <SFML/System/Clock.hpp>
#include <optional>

Game::Game()
: window(sf::VideoMode({1280,720}), "Royal Escape"),
  state(GameState::MENU)
{
    window.setFramerateLimit(60);

    bgTexture.loadFromFile("assets/backgrounds/royal_bazaar.png");
    background.setTexture(bgTexture);

    camera = window.getDefaultView();
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

void Game::processEvents()
{
    while(const auto event = window.pollEvent())
    {
        if(event->is<sf::Event::Closed>())
            window.close();

        if(const auto* key = event->getIf<sf::Event::KeyPressed>())
        {
            if(key->scancode == sf::Keyboard::Scancode::Escape)
                window.close();

            if(key->scancode == sf::Keyboard::Scancode::Enter)
                state = GameState::PLAYING;
        }
    }
}

void Game::update(float dt)
{
    if(state != GameState::PLAYING)
        return;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        player.moveLeft();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        player.moveRight();
    else
        player.stop();

    player.update(dt);

    camera.setCenter(player.getPosition());
}

void Game::render()
{
    window.clear();

    if(state == GameState::MENU)
    {
        window.clear(sf::Color(20,20,40));
    }
    else
    {
        window.setView(camera);
        window.draw(background);
        player.draw(window);
    }

    window.display();
}