#include "recipeStorage.h"
#include <fstream>
#include <sstream>
#include <chrono>


auto recipeStorage::clickFreqShell() {
    auto start = std::chrono::high_resolution_clock::now();
    int gap = clickFreq.size();
    while (gap > 0) {
        for (int i = gap; i < clickFreq.size(); i++) {
            pair<string, int> temp = clickFreq[i];
            int j;
            for (j = i; j > gap && clickFreq[j-gap].second > temp.second; j -= gap) {
                clickFreq[j] = clickFreq[j-gap];
            }
            clickFreq[j] = temp;
        }
        gap /= 2;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    return duration;
}

auto clickFreqRadix() {

}


auto recipeStorage::leastIngShell() {
    auto start = std::chrono::high_resolution_clock::now();
    int gap = leastIng.size();
    while (gap > 0) {
        for (int i = gap; i < leastIng.size(); i++) {
            pair<string, int> temp = leastIng[i];
            int j;
            for (j = i; j > gap && leastIng[j-gap].second > temp.second; j -= gap) {
                leastIng[j] = leastIng[j-gap];
            }
            leastIng[j] = temp;
        }
        gap /= 2;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    return duration;
}

auto leastIngRadix();

auto leastStepsShell();
auto leastRadix();

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
string readQuoteSeg(std::istream& input) {
    std::string result;
    char ch;
    while (input.get(ch) && ch != '"'); // read until '['
    input.get(ch); // read second '"'
    while (input.get(ch) && ch != '"') {
        result += ch;
    }
    input.get(ch); // read second '"'
    return result;
}

/* read file in */
void recipeStorage::readFile() {
    std::ifstream data("../testData.csv");

    // check if file opened successfully
    if (!data.is_open()) {
        std::cerr << "Error opening test file.\n";
    }

    // read first line with no recipe data
    string scrap;
    std::getline(data, scrap);
    std::cout << scrap << std::endl;

    // read all other recipe lines
    string line;
    string cell;
    while (std::getline(data, line)) {
        string segment;
        std::stringstream lineStream(line); // put line into a string stream
        recipeData* recipe = new recipeData;

        // load title + save as var (comma to comma)
        std::getline(lineStream, scrap, ',');
        std::getline(lineStream, segment, ',');
        recipe->recipeName = segment;

        // load ingredients with measurements

        // load directions
        // load link
        // load source
        // load NER aka ingredients + add to ingredient-recipe map
        std::cout << line << std::endl;
    }
    data.close();
}

