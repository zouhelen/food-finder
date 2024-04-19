#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Font font;
    font.loadFromFile("Cave-Story.ttf");
    sf::Text text("hey", font);
    text.setFillColor(sf::Color::White);

    while(window.isOpen()) {
        sf::Event e;

        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }
}