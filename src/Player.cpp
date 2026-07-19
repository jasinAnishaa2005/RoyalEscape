#include "../include/Player.hpp"
#include <iostream>

Player::Player()
{
    if (!texture.loadFromFile("assets/player/thief_run.png"))
    {
        std::cerr << "Failed to load player texture\n";
    }

    sprite.setTexture(texture);

    // Adjust these if your sprite sheet differs
    sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
    sprite.setScale(0.5f, 0.5f);
    sprite.setPosition(150.f, 450.f);
}

void Player::moveLeft()
{
    velocity = -speed;
}

void Player::moveRight()
{
    velocity = speed;
}

void Player::stop()
{
    velocity = 0.f;
}

void Player::update(float dt)
{
    sprite.move(velocity * dt, 0.f);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}