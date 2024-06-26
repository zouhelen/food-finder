#include <SFML/Graphics.hpp>
#include <functional>
#include "button.h"
#include "dropdown.h"
#include <map> // include statements
#include "../recipeStorage.h"

#ifndef FOOD_FINDER_DISPLAY_H
#define FOOD_FINDER_DISPLAY_H
class Display{ // toolbox class used to help display
    sf::VideoMode video; // default videomode, window, font, event object, and icon for the app
    sf::RenderWindow window;
    sf::Font font;
    sf::Event ev;
    sf::Image icon;

    enum Current{ // tracks which page the user is on
        W,
        Q,
        R,
        Recipe
    };

    enum SortCurrent{ // tracks which sorting method is being used
        LeastIngre,
        LeastSteps,
        Percent
    };

    Current cPage = W; // vars to keep track of previous 2 enums , default = welcome and percent
    SortCurrent cSort = Percent;

    std::vector<std::string> sortOptions = {"Least Ingred Used", "Lowest Steps", "% Ingredient Match"}; // options for sorting and menu
    std::vector<std::string> menuOptions = {"Quiz", "Your Reccs"};

    std::string currentR;

    std::function<void(void)> swapQuiz(); // lambda functions for button functions
    std::function<void(void)> swapReccs();
    std::function<void(void)> changeIngre(int i);
    std::function<void(void)> submitB();


    sf::Color bg; // default colors
    sf::Color fontC;
    sf::Color borderBlue;

    Button submit; // button creation
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
    Button backB;

    dropdown d1; // dropdown creation
    dropdown d2;

    int current = 0; // tracks current page

    std::vector<sf::RectangleShape> rectangles; // vector of recipe rectangles for recc display page

    void displayRecipe(std::string currentR); // button that renders the recipe page, takes in the name of the recipe to be rendered
    void welcome(); // welcome page
    void quiz(); // quiz page
    void reccs(int currentPage); // page showing the user's recommendations
public:
    recipeStorage recipes = recipeStorage(); // create recipeStorage instance
    // constructor, set all variables initialized with member initializer lists
    Display(): bg(240, 250, 242), fontC(129, 132, 233), borderBlue(131, 163, 219), enter(swapQuiz()), submit(submitB()), banana(changeIngre(0)), beef(changeIngre(1)), carrot(changeIngre(2)), cheese(changeIngre(3)), chicken(changeIngre(4)), coconut(changeIngre(5)), cucumber(changeIngre(6)), egg(changeIngre(7)), milk(changeIngre(8)), mushroom(changeIngre(9)), pb(changeIngre(10)), pork(changeIngre(11)), potato(changeIngre(12)), strawberry(changeIngre(13)), tomato(changeIngre(14)), backB(swapReccs()), d1(window, sortOptions, 1735.f, 5.f, "images/sort by.png"), d2(window, menuOptions, 5.f, 5.f, "images/menu.png"){
        recipes.readFile();
    };

    bool quizDone = false; // tracks when the user is done with quiz
    // tracks the indexes of each of the choices to make it easier for backend
    std::map<std::string, int> choices = {{"banana", 0}, {"beef", 1}, {"carrot", 2}, {"cheese", 3}, {"chicken", 4}, {"coconut", 5}, {"cucumber", 6}, {"egg", 7}, {"milk", 8}, {"mushroom", 9}, {"pb", 10}, {"pork", 11}, {"potato", 12}, {"strawberry", 13}, {"tomato", 14}};
    // tracks if each of the options are selected to be something in the users fridge or something they are allergic to
    std::vector<bool> added = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    std::vector<bool> removed = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

    void render(); // loop that runs the app and calls each page
};
#endif //FOOD_FINDER_DISPLAY_H