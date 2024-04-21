#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "recipeStorage.h"
#include "frontend elements/display.h"

int main() {
//    recipeStorage recipes = recipeStorage();
//
//    recipes.readFile();
//
//    vector<bool> chosenIngreTest = {true, false, false, true, false, false, false, false, false, false, false, false, false, false, false};
//    vector<bool> restrictedIngreTest = {false, true, false, false, false, false, false, false, false, false, false, false, false, false, false};
//    // order of ingredients
//    // 0.banana, 1.beef,  2.carrot, 3.cheese,  4.chicken, 5.coconut, 6.cucumber,
//    // 7.egg, 8.milk, 9.mushroom, 10.pork, 11.potato, 12.peanut butter, 13.strawberry, 14.tomato
//
//    recipes.updateIngredients(chosenIngreTest, restrictedIngreTest);
//
//    std::cout << "chosen ingredients: \n";
//    for (string chosen : recipes.chosenIng) {
//        std::cout << chosen << "\n";
//    }
//    std::cout << "\n";
//    std::cout << "restricted ingredients: \n";
//    for (string restricted : recipes.restrictedIng) {
//        std::cout << restricted << "\n";
//    }
//    std::cout << "\n";
//
//    //std::cout << recipes.recipePercentShell();
//    for (int i = 0; i < recipes.recipePercentS.size(); i++) {
//        std::cout << recipes.recipePercentS[i].first << " " << recipes.recipePercentS[i].second << std::endl;
//    }

    /*recipes.leastIng.push_back({"a", 4});
    recipes.leastIng.push_back({"b", 12});
    recipes.leastIng.push_back({"c", 123});
    recipes.leastIng.push_back({"d", 23423});
    recipes.leastIng.push_back({"e", 4});
    recipes.leastIng.push_back({"f", 9});
    recipes.leastIng.push_back({"g", 10});
    recipes.leastIng.push_back({"h", 10});*/

    /*for (int i = 0; i < recipes.leastIng.size(); i++) {
        std::cout << i << ": " << recipes.leastIng[i].second << "\n";
    }
    std::cout << "time taken for least ing by shell: " << recipes.leastIngShell() << "\n";
    for (int i = 0; i < recipes.leastIng.size(); i++) {
        std::cout << i << ": " << recipes.leastIng[i].second << "\n";
    }*/
//    recipes.addRestrictIngre("eggs");
//    recipes.restrictIngreUpdater();

    Display display;
    display.render();
    /*for (int i = 0; i < recipes.leastIng.size(); i++) {
        std::cout << i << ": " << recipes.leastIng[i].second << "\n";
    }
    std::cout << "time taken for least ing by radix: " << recipes.leastIngRadix() << "\n";
    for (int i = 0; i < recipes.leastIng.size(); i++) {
        std::cout << i << ": " << recipes.leastIng[i].second << "\n";
    }*/
/*
    string ingredient = "eggs";
    std::cout << ingredient << " testing\n";
    int i = 1;
    for (string recipe: recipes.ingredientMap[ingredient]) {
        std::cout << i << ": " << recipe << "\n";
        i++;
    }


    recipes.clickFreq.push_back({"a", 4});
    recipes.clickFreq.push_back({"b", 12});
    recipes.clickFreq.push_back({"c", 123});
    recipes.clickFreq.push_back({"d", 23423});
    recipes.clickFreq.push_back({"e", 4});
    recipes.clickFreq.push_back({"f", 9});
    recipes.clickFreq.push_back({"g", 10});
    recipes.clickFreq.push_back({"h", 10});

    for (int i = 0; i < recipes.clickFreq.size(); i++) {
        std::cout << i << ": " << recipes.clickFreq[i].second << "\n";
    }
    std::cout << "time taken for least ing by radix: " << recipes.clickFreqRadix() << "\n";
    for (int i = 0; i < recipes.clickFreq.size(); i++) {
        std::cout << i << ": " << recipes.clickFreq[i].second << "\n";
    }

    ingredient = "tomatoes";
    std::cout << ingredient << " testing\n";
    i = 1;
    for (string recipe: recipes.ingredientMap[ingredient]) {
        std::cout << i << ": " << recipe << "\n";
        i++;
    }
    */
    //Display display;
    //display.render();
    return 0;
}