#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::set;
using std::pair;

class recipeStorage {
public:
    // recipe structure
    struct recipeData {
        string recipeName; //name of each recipe
        vector<string> ingMeasurements; //vector of ingredients and their amounts for each recipe
        vector<string> directions; //vector of directions/steps for each recipe
        vector<string> ingList; //vector of just the ingredients for each recipe
    };

    // public variables
    unordered_map<string, recipeData> recipeMap; // contains all the recipes and their data
    unordered_map<string, vector<string>> ingredientMap; // contains all ingredients and vectors of the recipes the ingredients are in

    //unordered_set<string> chosenIng; //set of the chosen ingredients
    unordered_set<string> restrictedIng;
    set<string> chosenRecipe;

    //contains the names of the ingredients that are chosen
    vector<pair<string, int>> clickFreq; //pair: ingredient name, click frequency (greater first)
    vector<pair<string, int>> leastIng; //pair: recipe name, least ingredients (lesser first)
    vector<pair<string, int>> leastSteps; //pair: recipe name,  least steps (lesser first)
    //percentage of recipes' ingredients that are chosen
    vector<pair<string, int>> recipePercent; //pair: recipe, percent chosen (greater first)
    
    vector<string> hadIngre; //contains the names of the ingredients that are chosen    
    

    // methods
    void readFile();
    string readBrackSeg(std::istream& input); // short for read segment surrounded by brackets
    string readQuoteSeg(std::istringstream& input); // short for segment surrounded by quotes



    //sorts all the vectors with the corresponding algorithm
    //returns the length of time the function took
    auto clickFreqShell(); //performs shell sort on clickFreq
    auto clickFreqRadix(); //performs radix sort on clickFreq
    void clickFreqCountingSort(int placeVal); //helper function for radix sort

    auto leastIngShell();
    auto leastIngRadix();
    void leastIngCountingSort(int placeVal);
    
    auto leastStepsShell();
    auto leastStepsRadix();
    void leastStepsCountingSort(int placeVal);

    auto recipePercentShell();
    auto recipePercentRadix();
    void recipePercentCountingSort(int placeVal);


};