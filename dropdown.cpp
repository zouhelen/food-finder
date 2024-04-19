#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "dropdown.h"

dropdown::dropdown(sf::RenderWindow& window, const std::vector<std::string>& options, float x, float y): window(window), options(options), m_isOpen(false) {
        menu.setSize(sf::Vector2f(150.f, 30.f));
        menu.setFillColor(sf::Color::White);
        menu.setOutlineColor(sf::Color::Black);
        menu.setOutlineThickness(1.f);
        menu.setPosition(x, y);

        this -> font.loadFromFile("Cave-Story.ttf");
        select.setFont(font);
        select.setCharacterSize(16);
        select.setFillColor(sf::Color::Black);
        select.setString("Select an option");
        select.setPosition(x + 5.f, y + 5.f);

        float optionHeight = 30.f;
        for (size_t i = 0; i < options.size(); ++i) {
            sf::RectangleShape optionRect(sf::Vector2f(150.f, optionHeight));
            optionRect.setFillColor(sf::Color::White);
            optionRect.setOutlineColor(sf::Color::Black);
            optionRect.setOutlineThickness(1.f);
            optionRect.setPosition(x, y + (i + 1) * optionHeight);

            sf::Text optionText(options[i], font, 16);
            optionText.setFillColor(sf::Color::Black);
            optionText.setPosition(x + 5.f, y + (i + 1) * optionHeight + 5.f);

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