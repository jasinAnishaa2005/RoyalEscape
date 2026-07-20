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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        body.move(-speed*dt,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        body.move(speed*dt,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        body.move(0,-speed*dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        body.move(0,speed*dt);

    if(body.getPosition().x<0)
        body.setPosition(0,body.getPosition().y);

    if(body.getPosition().y<0)
        body.setPosition(body.getPosition().x,0);

    if(body.getPosition().x>1230)
        body.setPosition(1230,body.getPosition().y);

    if(body.getPosition().y>670)
        body.setPosition(body.getPosition().x,670);
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