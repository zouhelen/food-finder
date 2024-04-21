#include <SFML/Graphics.hpp> // include statements
#include <iostream>
#include <vector>

#ifndef FOOD_FINDER_DROPDOWN_H // header guards
#define FOOD_FINDER_DROPDOWN_H

class dropdown { // dropdown class
public:
    dropdown(sf::RenderWindow& window, const std::vector<std::string>& options, float x, float y, std::string icon); // constructor
    void draw(); // draws the dropdown menu
    void toggle(); // toggle open or close
    bool isOpen() const; // check if open
    sf::RectangleShape menu; // rectangle for the top option
    std::vector<sf::RectangleShape> rects; // vector of rectangles for the option buttons
private:
    std::vector<std::string> options; // option names
    std::vector<sf::Text> optionsText; // the text ver of those option names
    sf::RenderWindow& window; // window that's passed in
    sf::Font font; // font size
    bool is_Open; // bool to keep track of open or closed
};
#endif //FOOD_FINDER_DROPDOWN_H
