#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "recipeStorage.h"

int main() {
    recipeStorage recipes = recipeStorage();

    recipes.readFile();

    recipes.addChosenIngre("egg");
    recipes.addChosenIngre("tomato");
    recipes.addChosenIngre("brown sugar");
    recipes.addChosenIngre("chicken");

    return 0;
}