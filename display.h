#include <SFML/Graphics.hpp>
#include <functional>
#include "button.h"
#include "dropdown.h"
#ifndef FOOD_FINDER_DISPLAY_H
#define FOOD_FINDER_DISPLAY_H
class Display{
    sf::VideoMode video;
    sf::RenderWindow window;
    sf::Font font;
    sf::Event ev;
    sf::Image icon;

    enum Current{
        W,
        Q,
        R
    };

    Current cPage = W;

    std::vector<std::string> sortOptions = {"Most Popular", "Ingredient Number", "Step Number", "% Ingredient Match"};
    std::vector<std::string> menuOptions = {"Quiz", "Your Reccs", "Browse"};

    std::function<void(void)> swapPage();

    sf::Color bgGreen;
    sf::Color fontC;
    sf::Color borderBlue;

    Button enter;
    Button banana;
    Button beef;
    Button carrot;
    Button cheese;
    Button chicken;
    Button coconut;
    Button cucumber;
    Button egg;
    Button milk;
    Button mushroom;
    Button pb;
    Button pork;
    Button potato;
    Button strawberry;
    Button tomato;

    dropdown d1;
    dropdown d2;

    void welcome();
    void quiz();
    void reccs();
    //void browse(); // implement last
public:
    Display(): bgGreen(201, 201, 201), fontC(95, 90, 98), borderBlue(131, 125, 135), enter(swapPage()), banana(swapPage()), beef(swapPage()), carrot(swapPage()), cheese(swapPage()), chicken(swapPage()), coconut(swapPage()), cucumber(swapPage()), egg(swapPage()), milk(swapPage()), mushroom(swapPage()), pb(swapPage()), pork(swapPage()), potato(swapPage()), strawberry(swapPage()), tomato(swapPage()),d1(window, sortOptions, 500.f, 500.f, "images/sort by.png"), d2(window, menuOptions, 5.f, 5.f, "images/menu.png")
    {
    };
    void render(); // combine everything?
    std::vector<std::string> choices = {"banana", "beef", "carrot", "cheese", "chicken", "coconut", "cucumber", "egg", "milk", "mushroom", "pork", "potato", "peanut butter", "strawberry", "tomato"};
};
#endif //FOOD_FINDER_DISPLAY_H