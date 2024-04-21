#include <functional>
#include <SFML/Graphics.hpp>

#ifndef FOOD_FINDER_BUTTON_H
#define FOOD_FINDER_BUTTON_H

class Button{ // constructor for button
    sf::Sprite sprite;
    std::function<void(void)> click;
public:
    Button(std::function<void(void)> _onClick); // public constructor
    sf::Sprite getSprite(); // returns sprite
    void setSprite(sf::Sprite _sprite); // sets sprite
    void onClick(); // onclick function
};

#endif //FOOD_FINDER_BUTTON_H


