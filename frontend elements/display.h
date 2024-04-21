#include <SFML/Graphics.hpp>
#include <functional>
#include "button.h"
#include "dropdown.h"
#include <map>

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
        R,
        B
    };

    enum SortCurrent{
        LeastIngre,
        LeastSteps,
        Percent
    };

    Current cPage = W;
    SortCurrent cSort = Percent;

    std::vector<std::string> sortOptions = {"Least Ingredients Used", "Lowest Number of Steps", "% Ingredient Match"};
    std::vector<std::string> menuOptions = {"Quiz", "Your Reccs", "Browse"};

    std::function<void(void)> swapQuiz();
    std::function<void(void)> changeIngre(int i);
    std::function<void(void)> submitB();


    sf::Color bgGreen;
    sf::Color fontC;
    sf::Color borderBlue;

    Button submit;
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
    void browse(); // implement last

public:
    Display(): bgGreen(201, 201, 201), fontC(95, 90, 98), borderBlue(131, 125, 135), enter(swapQuiz()), submit(submitB()), banana(changeIngre(0)), beef(changeIngre(1)), carrot(changeIngre(2)), cheese(changeIngre(3)), chicken(changeIngre(4)), coconut(changeIngre(5)), cucumber(changeIngre(6)), egg(changeIngre(7)), milk(changeIngre(8)), mushroom(changeIngre(9)), pb(changeIngre(10)), pork(changeIngre(11)), potato(changeIngre(12)), strawberry(changeIngre(13)), tomato(changeIngre(14)),d1(window, sortOptions, 500.f, 500.f, "images/sort by.png"), d2(window, menuOptions, 5.f, 5.f, "images/menu.png")
    {
    };

    bool quizDone = false;

    std::map<std::string, int> choices = {{"banana", 0}, {"beef", 1}, {"carrot", 2}, {"cheese", 3}, {"chicken", 4}, {"coconut", 5}, {"cucumber", 6}, {"egg", 7}, {"milk", 8}, {"mushroom", 9}, {"pork", 10}, {"potato", 11}, {"peanut butter", 12}, {"strawberry", 13}, {"tomato", 14}};
    std::vector<bool> added = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    std::vector<bool> removed = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    void render(); // combine everything
};
#endif //FOOD_FINDER_DISPLAY_H