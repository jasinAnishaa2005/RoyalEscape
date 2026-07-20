#include "../include/Player.hpp"

Player::Player()
{
    body.setSize(sf::Vector2f(35.f,35.f));
    body.setFillColor(sf::Color(30,30,220));
    body.setPosition(100.f,300.f);

    speed = 350.f;
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
    sf::RectangleShape shadow(sf::Vector2f(40,8));
    shadow.setFillColor(sf::Color(0,0,0,70));
    shadow.setPosition(body.getPosition().x+2, body.getPosition().y+35);

    window.draw(shadow);

    // Head
    sf::CircleShape head(8);
    head.setFillColor(sf::Color(255,220,180));
    head.setPosition(body.getPosition().x+9, body.getPosition().y);

    // Body
    sf::RectangleShape torso(sf::Vector2f(18,20));
    torso.setFillColor(sf::Color(40,120,40));
    torso.setPosition(body.getPosition().x+8, body.getPosition().y+12);

    // Legs
    sf::RectangleShape leg1(sf::Vector2f(5,12));
    leg1.setFillColor(sf::Color::Black);
    leg1.setPosition(body.getPosition().x+10, body.getPosition().y+30);

    sf::RectangleShape leg2(sf::Vector2f(5,12));
    leg2.setFillColor(sf::Color::Black);
    leg2.setPosition(body.getPosition().x+20, body.getPosition().y+30);

    // Bag
    sf::RectangleShape bag(sf::Vector2f(6,14));
    bag.setFillColor(sf::Color(120,70,20));
    bag.setPosition(body.getPosition().x+1, body.getPosition().y+15);

    window.draw(head);
    window.draw(torso);
    window.draw(bag);
    window.draw(leg1);
    window.draw(leg2);
}



sf::FloatRect Player::getBounds() const
{
    return sf::FloatRect(body.getPosition().x,
                         body.getPosition().y,
                         35.f,
                         42.f);
}


void Player::setPosition(float x,float y)
{
    body.setPosition(x,y);
}