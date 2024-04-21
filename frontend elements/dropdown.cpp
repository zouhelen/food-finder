#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "dropdown.h"

dropdown::dropdown(sf::RenderWindow& window, const std::vector<std::string>& options, float x, float y, std::string icon): window(window), options(options), m_isOpen(false) {
    sf::Color dblue(77, 208, 225);
    sf::Color lblue(178, 235, 242);

    menu.setSize(sf::Vector2f(175.f, 75.f));
    sf::Texture* top = new sf::Texture();
    top -> loadFromFile(icon);
    menu.setTexture(top);
    menu.setPosition(x,y);

    this -> font.loadFromFile("Cave-Story.ttf");

    for (size_t i = 0; i < options.size(); ++i) {
        sf::RectangleShape optionRect(sf::Vector2f(175.f, 75.f));
        optionRect.setFillColor(lblue);
        optionRect.setOutlineColor(dblue);
        optionRect.setOutlineThickness(1.f);
        optionRect.setPosition(x, y + (i + 1) * 75.f);

        sf::Text optionText(options[i], font, 27);
        optionText.setFillColor(dblue);
        optionText.setOrigin(optionText.getLocalBounds().width / 2.f, optionText.getLocalBounds().height / 2.f);

        sf::FloatRect textBounds = optionText.getLocalBounds();
        optionText.setPosition(optionRect.getPosition().x + optionRect.getSize().x / 2.f, optionRect.getPosition().y + optionRect.getSize().y / 2.f - textBounds.height / 2.f);

        rects.push_back(optionRect);
        optionsText.push_back(optionText);
    }
}

void dropdown::draw() {
    window.draw(menu);
    window.draw(select);

    if (m_isOpen) {
        for (const auto& rect : rects) {
            window.draw(rect);
        }
        for (const auto& text : optionsText) {
            window.draw(text);
        }
    }
}

void dropdown::toggle() {
    m_isOpen = !m_isOpen;
}

bool dropdown::isOpen() const {
    return m_isOpen;
}