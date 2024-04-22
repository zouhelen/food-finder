#include <fstream>
#include <sstream>
#include "frontend elements/display.h"

int main() {
    Display display;
    display.render();
    std::cout << "Time for radix sort for least ingredient: " << display.recipes.leastIngRadix() << "\n"; // time displays
    std::cout << "Time for shell short for least ingredient: " << display.recipes.leastIngShell() << "\n\n";
    std::cout << "Time for radix sort for least steps: " << display.recipes.leastStepsRadix() << "\n";
    std::cout << "Time for shell short for least steps: " << display.recipes.leastStepsShell() << "\n\n";
    std::cout << "Time for radix sort by highest percent: " << display.recipes.recipePercentRadix() << "\n";
    std::cout << "Time for shell short by highest percent: " << display.recipes.recipePercentShell() << "\n\n";
    return 0;
}