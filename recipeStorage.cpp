#include "recipeStorage.h"
#include <fstream>
#include <sstream>

/* read a segment starting with '[' and ending with ']' */
string readBrackSeg(std::istream& input) {
    std::string result;
    char ch;
    while (input.get(ch) && ch != '['); // read until '['
    while (input.get(ch) && ch != ']') {
        result += ch;
    }
    return result;
}

/* read a segment starting with '[' and ending with ']' */
string readQuoteSeg(std::string& input) {
    std::string result = "";
    std::istringstream inputStream(input);
    char ch;
    while (inputStream.get(ch) && ch != '"'); // read until '['
    inputStream.get(ch); // read second '"'
    while (inputStream.get(ch) && ch != '"') {
        result += ch;
    }
    inputStream.get(ch); // read second '"'
    return result;
}

/* read file in */
void recipeStorage::readFile() {
    std::ifstream data("../testData.csv");

    // check if file opened successfully
    if (!data.is_open()) {
        std::cerr << "Error opening test file.\n";
    }

    // read and scrap first line which has no recipe data
    string scrap;
    std::getline(data, scrap);
    std::cout << scrap << std::endl;

    // read all other recipe lines
    string line;
    string cell;
    while (std::getline(data, line)) {
        string segment;
        std::stringstream lineStream(line); // put line into a string stream
        recipeData* recipe = new recipeData; // new recipe struc allocated to heap

        // load title + save as var (comma to comma)
        std::getline(lineStream, scrap, ',');
        std::getline(lineStream, segment, ',');
        recipe->recipeName = segment;

        // load ingredients with measurements
        string fullIng = readBrackSeg(lineStream);
        bool moreIng = true;
        while(moreIng) {
            string oneIng = "";
            oneIng = readQuoteSeg(fullIng);
            // if
            if(oneIng == "") {
                moreIng = false;
            }
            else {
                recipe->ingMeasurements.push_back(oneIng);
            }
        }


        // load directions
        // load link
        // load source
        // load NER aka ingredients + add to ingredient-recipe map
        std::cout << line << std::endl;
    }
    data.close();
}

