#include "../include/Player.hpp"

Player::Player()
{
    body.setSize(sf::Vector2f(50.f,50.f));
    body.setFillColor(sf::Color::Blue);
    body.setPosition(100.f,300.f);

    speed = 250.f;
}

void Player::handleInput(float dt)
{
    // Move Left (A or Left Arrow)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        body.move(-speed * dt, 0);
    }

    // Move Right (D or Right Arrow)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        body.move(speed * dt, 0);
    }

    // Move Up (W or Up Arrow)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        body.move(0, -speed * dt);
    }

    // Move Down (S or Down Arrow)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        body.move(0, speed * dt);
    }

    // Keep player inside window
    if(body.getPosition().x < 0)
        body.setPosition(0, body.getPosition().y);

    if(body.getPosition().y < 0)
        body.setPosition(body.getPosition().x, 0);

    if(body.getPosition().x > 1230)
        body.setPosition(1230, body.getPosition().y);

    if(body.getPosition().y > 670)
        body.setPosition(body.getPosition().x, 670);
}
void Player::draw(sf::RenderWindow& window)
{
    sf::RectangleShape shadow;

shadow.setSize(sf::Vector2f(45.f,10.f));
shadow.setFillColor(sf::Color(0,0,0,90));

shadow.setPosition(
body.getPosition().x+4,
body.getPosition().y+42
);

window.draw(shadow);

window.draw(body);
    window.draw(body);
}

sf::FloatRect Player::getBounds() const
{
    return body.getGlobalBounds();
}

void Player::setPosition(float x,float y)
{
    body.setPosition(x,y);
}