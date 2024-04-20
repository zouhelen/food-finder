#include <SFML/Graphics.hpp>

#ifndef FOOD_FINDER_DISPLAY_H
#define FOOD_FINDER_DISPLAY_H
class Display{
    sf::VideoMode video;
    sf::RenderWindow window;
    sf::Font font;
    sf::Event ev;
    std::vector<std::string> sortOptions = {"Most Popular", "Ingredient Number", "Step Number", "% Ingredient Match"};
    std::vector<std::string> menuOptions = {"Quiz", "Your Reccs", "Browse"};
public:
    Display(){};
    void render();
};
#endif //FOOD_FINDER_DISPLAY_H