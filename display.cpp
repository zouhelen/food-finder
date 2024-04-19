#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <iostream>
#include "display.h"
#include "dropdown.h"

// create methods for each page. submit button reloads to reccs, then a quiz retake option, a see reccs option, and a browse option
void Display::render(){ // puts everything together, onclick stuff
    video = sf::VideoMode::getDesktopMode();

    this -> window.create(this -> video, "Food Finder", sf::Style::Titlebar | sf::Style::Close);


    this -> font.loadFromFile("Cave-Story.ttf");

    dropdown d1(window, sortOptions, 100.f, 100.f, "Sort By");
    dropdown d2(window, menuOptions, 200.f, 200.f, "Menu");


    while(this -> window.isOpen()) {
        while (this -> window.pollEvent(this -> ev)) {
            if (ev.type == sf::Event::Closed) {
                this -> window.close();
                break;
            }
            else if(ev.type == sf::Event::KeyPressed){
                if(ev.key.code == sf::Keyboard::Escape){
                    this -> window.close();
                }
                break;
            }
            else if (ev.type == sf::Event::MouseButtonPressed) {
                if (ev.mouseButton.button == sf::Mouse::Left) {
                    // Check if the mouse click is inside the menu rectangle
                    if (d1.isOpen()) {
                        d1.toggle();
                    } else if (ev.mouseButton.x >= d1.menu.getPosition().x && ev.mouseButton.x <= d1.menu.getPosition().x + d1.menu.getSize().x &&
                               ev.mouseButton.y >= d1.menu.getPosition().y && ev.mouseButton.y <= d1.menu.getPosition().y + d1.menu.getSize().y) {
                        d1.toggle();
                    }

                    if (d2.isOpen()) {
                        d2.toggle();
                    } else if (ev.mouseButton.x >= d2.menu.getPosition().x && ev.mouseButton.x <= d2.menu.getPosition().x + d2.menu.getSize().x &&
                               ev.mouseButton.y >= d2.menu.getPosition().y && ev.mouseButton.y <= d2.menu.getPosition().y + d2.menu.getSize().y) {
                        d2.toggle();
                    }
                }
            }
        }
        this -> window.clear();
        d1.draw();
        d2.draw();
        this -> window.display();
    }
}

int main() {
    Display display;
    display.render();
}