#ifndef FOOD_FINDER_DROPDOWN_H
#define FOOD_FINDER_DROPDOWN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class dropdown {
public:
    dropdown(sf::RenderWindow& window, const std::vector<std::string>& options, float x, float y, const sf::Texture* top);
    void draw();
    void toggle();
    bool isOpen() const;
    sf::RectangleShape menu;
private:
    std::vector<std::string> options;
    sf::Text select;
    std::vector<sf::RectangleShape> rects;
    std::vector<sf::Text> optionsText;
    sf::RenderWindow& window;
    sf::Font font;
    bool m_isOpen;
};
#endif //FOOD_FINDER_DROPDOWN_H