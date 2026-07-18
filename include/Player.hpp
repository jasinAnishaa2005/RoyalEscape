#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void update(float dt);
    void draw(sf::RenderWindow& window);

    void moveLeft();
    void moveRight();
    void stop();

    sf::Vector2f getPosition() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;

    float speed = 300.f;
    float velocity = 0.f;
};

#endif