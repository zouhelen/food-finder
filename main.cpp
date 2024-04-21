#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "recipeStorage.h"

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

    return 0;
}