#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <iostream>
#include "display.h"
#include "dropdown.h"
#include "button.h"

std::function<void(void)> Display::swapPage(){
    return []() {
        std::cout << "Page swapped!" << std::endl;
    };
}

void Display::welcome(){
    sf::Color dark(20, 131, 143);
    sf::Color dblue(28, 168, 184);

    sf::Texture enterB;
    enterB.loadFromFile("enter.png");
    sf::Sprite enterImg;
    enterImg.setTexture(enterB);
    enterImg.scale(.5,.37);
    enterImg.setPosition(window.getSize().x/2 - enterB.getSize().x/4,window.getSize().y/2);

    sf::Text welcomeText("Welcome to Food Finder!", font, 150);
    welcomeText.setFillColor(dark);
    welcomeText.setPosition(window.getSize().x/5,window.getSize().y/4);

    sf::Text secondary("Please click enter to begin your preference quiz.", font, 70);
    secondary.setFillColor(dblue);
    secondary.setPosition(window.getSize().x/5, window.getSize().y/2.5);

    Button enter(swapPage());

    enter.setSprite(enterImg);
    this -> window.draw(welcomeText);
    this -> window.draw(secondary);

    this -> window.draw(enter.getSprite());
}


void Display::quiz() {

}

void Display::reccs() {
}

// create methods for each page. submit button reloads to reccs, then a quiz retake option, a see reccs option, and a browse option
void Display::render(){ // puts everything together, onclick stuff
    sf::Color bgGreen(230, 250, 245);

    sf::Image icon;
    icon.loadFromFile("icon.png");

    video = sf::VideoMode::getDesktopMode();

    this -> window.create(this -> video, "Food Finder", sf::Style::Titlebar | sf::Style::Close);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    this -> font.loadFromFile("Cave-Story.ttf");

    sf::Texture* sortT = new sf::Texture();
    sortT -> loadFromFile("sort by.png");

    dropdown d1(window, sortOptions, 500.f, 500.f, sortT);

    sf::Texture* menuT = new sf::Texture();
    menuT -> loadFromFile("menu.png");
    dropdown d2(window, menuOptions, 5.f, 5.f, menuT);

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
        this -> window.clear(bgGreen);
        welcome();
        d1.draw();
        d2.draw();
        this -> window.display();
    }
}

int main() {
    Display display;
    display.render();
}