#include <functional>
#include <SFML/Graphics.hpp>

#ifndef FOOD_FINDER_BUTTON_H
#define FOOD_FINDER_BUTTON_H

class Button{ // constructor for button
    sf::Vector2f position; // position, sprite, onclick function
    sf::Sprite* sprite;
    std::function<void(void)> click;
public:
    Button(sf::Vector2f _position, std::function<void(void)> _onClick); // public constructor
    sf::Vector2f getPosition(); // returns position
    sf::Sprite* getSprite(); // returns sprite
    void setSprite(sf::Sprite* _sprite); // sets sprite
    void onClick(); // onclick function
};

#endif //FOOD_FINDER_BUTTON_H


