#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::RectangleShape body;
    float speed;

public:
    Player();

    void handleInput(float dt);
    void draw(sf::RenderWindow& window);

    sf::FloatRect getBounds() const;

    void setPosition(float x, float y);
};

#endif