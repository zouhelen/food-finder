#include <SFML/Graphics.hpp>
#ifndef FOOD_FINDER_DISPLAY_H
#define FOOD_FINDER_DISPLAY_H
class Display{
    sf::VideoMode video;
    sf::RenderWindow window;
    sf::Font font;
    sf::Event ev;
    sf::Image icon;

    std::vector<std::string> sortOptions = {"Most Popular", "Ingredient Number", "Step Number", "% Ingredient Match"};
    std::vector<std::string> menuOptions = {"Quiz", "Your Reccs", "Browse"};

    std::function<void(void)> swapPage();

    sf::Color bgGreen;
    sf::Color fontC;
    sf::Color borderBlue;

    void welcome();
    void quiz();
    void reccs();
    void browse(); // implement last
public:
    Display(): bgGreen(230, 250, 245), fontC(20, 131, 143), borderBlue(28, 168, 184){
    };
    void render(); // combine everything?
};
#endif //FOOD_FINDER_DISPLAY_H