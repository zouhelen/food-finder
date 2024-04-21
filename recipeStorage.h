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

    unordered_set<string> chosenIng; //set of the chosen ingredients
    unordered_set<string> restrictedIng; //set of the restricted ingredients
    set<string> chosenRecipe; //set of recipes containing at least 1 chosen ingredient (and no restricted ingredients)

    //contains the names of the ingredients that are chosen
    vector<pair<string, int>> clickFreq; //pair: ingredient name, click frequency (greater first)
    vector<pair<string, int>> leastIng; //pair: recipe name, num of ingredients (lesser first)
    vector<pair<string, int>> leastSteps; //pair: recipe name, num of steps (lesser first)
    //percentage of recipes' ingredients that are chosen
    vector<pair<string, int>> recipePercent; //pair: recipe, percent chosen (greater first)
    
    vector<string> hadIngre; //contains the names of the ingredients that are chosen    
    

    // methods
    void readFile();
    string readBrackSeg(std::istream& input); // short for read segment surrounded by brackets
    string readQuoteSeg(std::istringstream& input); // short for segment surrounded by quotes

    //function called on click that adds to chosenIng
    void addChosenIngre(string ingredient);
    //function called when submit button is pressed to add values from unord_maps to the unord_set, set, and vectors
    void chooseIngreUpdater();
    //function called on click that adds to restrictedIng
    void addRestrictIngre(string ingredient);
    //function called on click to remove values from unord_maps to the unord_set, set, and vectors
    void restrictIngreUpdater();

    //search recipes
    void search(); //makes sure all restricted ingredients/recipes aren't chosen
    //^would need to go through everything--what if a chosen ingredient was unchosen and then was restricted
    void sortVects(); //sorts all of the vectors

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