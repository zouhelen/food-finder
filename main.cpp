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

    Display display;
    display.render();
    return 0;
}