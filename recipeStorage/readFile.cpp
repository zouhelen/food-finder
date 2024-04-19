#include <fstream>
#include <sstream>

#include "recipeStorage.h"

using std::endl;


void readFile() {
    /* read file in */
    std::ifstream data("../testData.csv");

    // check if file opened successfully
    if (!data.is_open()) {
        std::cerr << "Error opening test file.\n";
    }

    // print out line by line
    string line;
    string cell;
    while (std::getline(data, line)) {
        std::stringstream lineStream(line); // put line into a string stream
        while (std::getline(lineStream, cell, ',')) {

        }
        std::cout << line << endl;
    }
    data.close();
}

