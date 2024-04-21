#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "recipeStorage.h"
#include "display.h"

int main() {
    recipeStorage recipes = recipeStorage();

    recipes.readFile();

    recipes.addChosenIngre("eggs");
    recipes.addChosenIngre("tomatoes");
    recipes.addChosenIngre("bananas");
    recipes.addChosenIngre("chicken");
    recipes.chooseIngreUpdater();

    std::cout << recipes.leastIngShell();
    for (int i = 0; i < recipes.leastIng.size(); i++) {
        std::cout << recipes.leastIng[i].first << " " << recipes.leastIng[i].second << std::endl;
    }

    recipes.leastIng.push_back({"a", 4});
    recipes.leastIng.push_back({"b", 12});
    recipes.leastIng.push_back({"c", 123});
    recipes.leastIng.push_back({"d", 23423});
    recipes.leastIng.push_back({"e", 4});
    recipes.leastIng.push_back({"f", 9});
    recipes.leastIng.push_back({"g", 10});
    recipes.leastIng.push_back({"h", 10});

    for (int i = 0; i < recipes.leastIng.size(); i++) {
        std::cout << i << ": " << recipes.leastIng[i].second << "\n";
    }
    std::cout << "time taken for least ing by shell: " << recipes.leastIngShell() << "\n";
    for (int i = 0; i < recipes.leastIng.size(); i++) {
        std::cout << i << ": " << recipes.leastIng[i].second << "\n";
    }

    string ingredient = "eggs";
    std::cout << ingredient << " testing\n";
    int i = 1;
    for (string recipe: recipes.ingredientMap[ingredient]) {
        std::cout << i << ": " << recipe << "\n";
        i++;
    }
    //Display display;
    //display.render();
    return 0;
}