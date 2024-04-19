#include <SFML/Graphics.hpp>
#include "button.h"
#include "dropdown.h"
#include "recipe.h"

#ifndef FOOD_FINDER_DISPLAY_H
#define FOOD_FINDER_DISPLAY_H
class Display{
private:
    std::vector<std::string> sortOptions = {"Ingredient Number", "% Ingredient Match", "Instruction Number", "Most Popular"};
    std::vector<std::string> menuOptions = {"Quiz", "Your Suggestions", "Browse"};
    sf::Font font;
    sf::Text text;
    sf::RenderWindow window;
    sf::Event ev;
    sf::VideoMode video;
public:
    Display(){};
    void render();
};
#endif
