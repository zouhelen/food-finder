#include "recipeStorage.h"
#include <fstream>
#include <sstream>

void recipeStorage::readFile() {
    /* read file in */
    std::ifstream data("../testData.csv");

    // check if file opened successfully
    if (!data.is_open()) {
        std::cerr << "Error opening test file.\n";
    }

    // read first line with no recipe data
    string scrapLine;
    std::getline(data, scrapLine);
    std::cout << scrapLine << std::endl;

    // read all other recipe lines
    string line;
    string cell;
    while (std::getline(data, line)) {
        std::stringstream lineStream(line); // put line into a string stream
        // load title + save as var
        // load ing with measurements
        // load directions
        // load link
        // load source
        // load NER aka ingredients + add to ingredient-recipe map
        std::cout << line << std::endl;
    }
    data.close();
}

