#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "recipeStorage.h"

int main() {
    recipeStorage recipes = recipeStorage();

    recipes.readFile();

    return 0;
}