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

    // read first line with no rela
    string scrapLine;
    std::getline(data, scrapLine);
    std::cout << scrapLine << std::endl;

    // print out line by line
    string line;
    string cell;
    while (std::getline(data, line)) {
        std::stringstream lineStream(line); // put line into a string stream
        while (std::getline(lineStream, cell, ',')) {

        }
        std::cout << line << std::endl;
    }
    data.close();
}

