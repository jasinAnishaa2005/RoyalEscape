#include "../include/Game.hpp"
#include <optional>

Game::Game()
: window(sf::VideoMode({1280,720}), "Royal Escape")
{
    window.setFramerateLimit(60);

    gameState = GameState::MENU;
}

void Game::run()
{
    while(window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    while(const std::optional event = window.pollEvent())
    {
        if(event->is<sf::Event::Closed>())
            window.close();

        if(const auto* key = event->getIf<sf::Event::KeyPressed>())
        {
            if(key->scancode == sf::Keyboard::Scancode::Enter)
            {
                if(gameState == GameState::MENU)
                    gameState = GameState::INTRO;
            }
        }
    }
}

void Game::update()
{

}

void Game::render()
{
    switch(gameState)
    {
        case GameState::MENU:
            window.clear(sf::Color(15,20,40));
            break;

        case GameState::INTRO:
            window.clear(sf::Color(60,25,80));
            break;

        case GameState::PLAYING:
            window.clear(sf::Color(20,100,30));
            break;

        case GameState::GAMEOVER:
            window.clear(sf::Color(120,30,30));
            break;
    }

    window.display();
}