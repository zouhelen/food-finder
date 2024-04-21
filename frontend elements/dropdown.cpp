#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "dropdown.h" // include statements

dropdown::dropdown(sf::RenderWindow& window, const std::vector<std::string>& options, float x, float y, std::string icon): window(window), options(options), is_Open(false) {
    sf::Color dblue(77, 208, 225); // initializes colors
    sf::Color lblue(178, 235, 242);

    menu.setSize(sf::Vector2f(175.f, 75.f)); // set size, texture, and position of dropdown
    sf::Texture* top = new sf::Texture();
    top -> loadFromFile(icon);
    menu.setTexture(top);
    menu.setPosition(x,y);

    this -> font.loadFromFile("Cave-Story.ttf"); // load font

    for (size_t i = 0; i < options.size(); ++i) { // for every option
        sf::RectangleShape optionR(sf::Vector2f(175.f, 75.f)); // create an option rectangle the size of the menu, set colors and position
        optionR.setFillColor(lblue);
        optionR.setOutlineColor(dblue);
        optionR.setOutlineThickness(1.f);
        optionR.setPosition(x, y + (i + 1) * 75.f); // justifies in a row under first option

        sf::Text optionT(options[i], font, 27); // set option text, color, font, size, and origin
        optionT.setFillColor(dblue);
        optionT.setOrigin(optionT.getLocalBounds().width / 2.f, optionT.getLocalBounds().height / 2.f);

        sf::FloatRect textBounds = optionT.getLocalBounds(); // set text position based on bounds
        optionT.setPosition(optionR.getPosition().x + optionR.getSize().x / 2.f, optionR.getPosition().y + optionR.getSize().y / 2.f - textBounds.height / 2.f);

        rects.push_back(optionR); // push both back into the vectors storing the menu options
        optionsText.push_back(optionT);
    }
}

void dropdown::draw() {
    window.draw(menu); // draw everything

    if (is_Open) { // draw options with for loop if its open
        for (const auto& rect : rects) {
            window.draw(rect);
        }
        for (const auto& text : optionsText) {
            window.draw(text);
        }
    }
}

void dropdown::toggle() {
    is_Open = !is_Open; // set is open to the opposite
}

bool dropdown::isOpen() const {
    return is_Open; // return if open
}