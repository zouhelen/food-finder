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

    std::function<void(void)> swapPage();

    void welcome();
    void quiz();
    void reccs();
    void browse(); // implement last
public:
    Display(){};
    void render(); // combine everything?
};
#endif //FOOD_FINDER_DISPLAY_H