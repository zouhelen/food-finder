#include <SFML/Graphics.hpp>
#include <functional>
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
    //void browse(); // implement last
public:
    Display(): bgGreen(201, 201, 201), fontC(95, 90, 98), borderBlue(131, 125, 135){
    };
    void render(); // combine everything?
    std::vector<std::string> choices = {"banana", "beef", "carrot", "cheese", "chicken", "coconut", "cucumber", "egg", "milk", "mushroom", "pork", "potato", "peanut butter", "strawberry", "tomato"};
};
#endif //FOOD_FINDER_DISPLAY_H