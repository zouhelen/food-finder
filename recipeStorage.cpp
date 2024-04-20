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

auto recipeStorage::clickFreqRadix() {
    auto start = std::chrono::high_resolution_clock::now();
    int max = clickFreq[0].second;
    for (pair<string, int> pairItr : clickFreq) {
        max = std::max(max, pairItr.second);
    }

    for (int placeVal = 1; max/placeVal > 0; placeVal *= 10) {
        clickFreqCountingSort(placeVal);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    return duration;
}

void recipeStorage::clickFreqCountingSort(int placeVal) {
    int count[] = {0,0,0,0,0,0,0,0,0,0};
    pair<string, int> output[clickFreq.size()];
    for (int i = 0; i < clickFreq.size(); i++) {
        count[(clickFreq[i].second / placeVal) % 10] = count[(clickFreq[i].second / placeVal) % 10] + 1;
    }
    for (int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }
    for (int k = clickFreq.size()-1; k >= 0; k--) {
        output[count[(clickFreq[k].second / placeVal) % 10] - 1] = clickFreq[k];
        count[(clickFreq[k].second / placeVal) % 10]--;
    }
    for (int l = 0; l < clickFreq.size(); l++) {
        clickFreq[l] = output[l];
    }
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

auto recipeStorage::leastIngRadix() {
    auto start = std::chrono::high_resolution_clock::now();
    int max = leastIng[0].second;
    for (pair<string, int> pairItr : leastIng) {
        max = std::max(max, pairItr.second);
    }

    for (int placeVal = 1; max/placeVal > 0; placeVal *= 10) {
        leastIngCountingSort(placeVal);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    return duration;
}

void recipeStorage::leastIngCountingSort(int placeVal) {
    int count[] = {0,0,0,0,0,0,0,0,0,0};
    pair<string, int> output[leastIng.size()];
    for (int i = 0; i < leastIng.size(); i++) {
        count[(leastIng[i].second / placeVal) % 10] = count[(leastIng[i].second / placeVal) % 10] + 1;
    }
    for (int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }
    for (int k = leastIng.size()-1; k >= 0; k--) {
        output[count[(leastIng[k].second / placeVal) % 10] - 1] = leastIng[k];
        count[(leastIng[k].second / placeVal) % 10]--;
    }
    for (int l = 0; l < leastIng.size(); l++) {
        leastIng[l] = output[l];        
    }
}

auto recipeStorage::leastStepsShell() {
    auto start = std::chrono::high_resolution_clock::now();
    int gap = leastSteps.size();
    while (gap > 0) {
        for (int i = gap; i < leastSteps.size(); i++) {
            pair<string, int> temp = leastSteps[i];
            int j;
            for (j = i; j > gap && leastSteps[j-gap].second > temp.second; j -= gap) {
                leastSteps[j] = leastSteps[j-gap];
            }
            leastSteps[j] = temp;
        }
        gap /= 2;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    return duration;
}

auto recipeStorage::leastStepsRadix() {
    auto start = std::chrono::high_resolution_clock::now();
    int max = leastSteps[0].second;
    for (pair<string, int> pairItr : leastSteps) {
        max = std::max(max, pairItr.second);
    }

    for (int placeVal = 1; max/placeVal > 0; placeVal *= 10) {
        leastIngCountingSort(placeVal);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    return duration;
}

void recipeStorage::leastStepsCountingSort(int placeVal) {
    int count[] = {0,0,0,0,0,0,0,0,0,0};
    pair<string, int> output[leastSteps.size()];
    for (int i = 0; i < leastSteps.size(); i++) {
        count[(leastSteps[i].second / placeVal) % 10] = count[(leastSteps[i].second / placeVal) % 10] + 1;
    }
    for (int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }
    for (int k = leastSteps.size()-1; k >= 0; k--) {
        output[count[(leastSteps[k].second / placeVal) % 10] - 1] = leastSteps[k];
        count[(leastSteps[k].second / placeVal) % 10]--;
    }
    for (int l = 0; l < leastSteps.size(); l++) {
        leastSteps[l] = output[l];        
    }
}

auto recipePercentShell() {

}

auto recipePercentRadix() {

}

/* read a segment starting with '[' and ending with ']' */
string recipeStorage::readBrackSeg(std::istream& input) {
    std::string result;
    char ch;
    while (input.get(ch) && ch != '['); // read until '['
    while (input.get(ch) && ch != ']') {
        result += ch;
    }
    return result;
}

/* read a segment starting with '[' and ending with ']' */
string recipeStorage::readQuoteSeg(std::istringstream& inputStream) {
    std::string result = "";
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
    std::getline(data, line);
        string name;
        std::stringstream lineStream(line); // put line into a string stream
        recipeData* recipe = new recipeData; // new recipe struc allocated to heap

        /* load title + save as var (comma to comma) */

        std::getline(lineStream, scrap, ',');
        std::getline(lineStream, name, ',');
        recipe->recipeName = name;
        std::cout << "recipe name: " << recipe->recipeName << std::endl;

        /* load ingredients including measurements */

        string fullIng = readBrackSeg(lineStream);
        std::istringstream fullIngStream(fullIng);

        bool moreIng = true;
        while(moreIng) { // keep adding ingredients until end
            string oneIng;
            oneIng = readQuoteSeg(fullIngStream);

            if(oneIng.empty()) {
                moreIng = false;
            }
            else {
                recipe->ingMeasurements.push_back(oneIng);
            }
        }
        std::cout << "ingredients: \n";
        for (string ing: recipe->ingMeasurements) {
            std::cout << ing << std::endl;
        }

        /* load directions */
        string fullDir = readBrackSeg(lineStream);
        std::istringstream dirStream(fullDir);

        bool moreSteps = true;
        int i = 1;
        while(moreSteps) {
            string oneStep;
            oneStep = readQuoteSeg(dirStream);
            // keep adding steps until the end
            if(oneStep.empty()) {
                moreSteps = false;
            }
            else {
                string labeledStep = "(" + std::to_string(i ) + ") " + oneStep;
                recipe->directions.push_back(labeledStep);
            }
            i++;
        }
        std::cout << "directions: \n";
        for (string step: recipe->directions) {
            std::cout << step << std::endl;
        }

        /* load NER aka ingredients and
         * add to ingredient-recipe map */
        string ingList = readBrackSeg(lineStream);
        std::istringstream ingStream(ingList);

        bool moreIngredients = true;
        while(moreIngredients) { // keep adding ingredients until end
            string oneIng;
            oneIng = readQuoteSeg(ingStream);

            if(oneIng.empty()) {
                moreIngredients = false;
            }
            else {
                recipe->ingList.push_back(oneIng);
                // add recipe to corresponding ingredient map
                if (ingredientMap.find(oneIng) != ingredientMap.end()) {
                    vector<string> recipeList;
                    recipeList.push_back(recipe->recipeName);
                    ingredientMap[oneIng] = recipeList;
                }
                else {
                    ingredientMap[oneIng].push_back(recipe->recipeName);
                }
            }
        }
        std::cout << "ingredients: \n";
        for (string ing: recipe->ingList) {
            std::cout << ing << std::endl;
        }

        for (auto& pair: ingredientMap) {
            std::cout << "ingredient: " << pair.first << "\n";
            std::cout << "recipes: ";
            for (string recipe: pair.second) {
                std::cout << recipe << ", ";
            }
            std::cout << "\n\n";
        }
        //std::cout << line << std::endl;
    }
    data.close();
}

