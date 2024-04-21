#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>

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
        unordered_set<string> ingList; //vector of just the ingredients for each recipe
    };

    // public variables
    unordered_map<string, recipeData*> recipeMap; // contains all the recipes and their data
    unordered_map<string, unordered_set<string>> ingredientMap; // contains all ingredients and vectors of the recipes the ingredients are in

    unordered_set<string> chosenIng; //set of the chosen ingredients
    unordered_set<string> restrictedIng; //set of the restricted ingredients
    set<string> chosenRecipe; //set of recipes containing at least 1 chosen ingredient (and no restricted ingredients)

    //sorted via shell sort
    //contains the names of the ingredients that are chosen
    vector<pair<string, int>> clickFreqS; //pair: ingredient name, click frequency (greater first)
    vector<pair<string, int>> leastIngS; //pair: recipe name, num of ingredients (lesser first)
    vector<pair<string, int>> leastStepsS; //pair: recipe name, num of steps (lesser first)
    //percentage of recipes' ingredients that are chosen
    vector<pair<string, int>> recipePercentS; //pair: recipe, percent chosen (greater first)
    
    //sorted via radix sort
    //contains the names of the ingredients that are chosen
    vector<pair<string, int>> clickFreqR; //pair: ingredient name, click frequency (greater first)
    vector<pair<string, int>> leastIngR; //pair: recipe name, num of ingredients (lesser first)
    vector<pair<string, int>> leastStepsR; //pair: recipe name, num of steps (lesser first)
    //percentage of recipes' ingredients that are chosen
    vector<pair<string, int>> recipePercentR; //pair: recipe, percent chosen (greater first)

    // methods
    void readFile();
    string readBrackSeg(std::istream& input); // short for read segment surrounded by brackets
    string readQuoteSeg(std::istringstream& input); // short for segment surrounded by quotes

    //function that adds to chosenIng
    void addChosenIngre(string ingredient);
    //function called when submit button is pressed to add values from unord_maps to the unord_set, set, and vectors
    void chooseIngreUpdater();
    //function called on click that adds to restrictedIng
    void addRestrictIngre(string ingredient);
    //function called on click to remove values from unord_maps to the unord_set, set, and vectors
    void restrictIngreUpdater();
    // combines above functions to parse selected ingredients from front end
    void updateIngredients(vector<bool> chosenIngre, vector<bool> restrictedIngre);


    //sorts all the vectors with the corresponding algorithm
    //returns the length of time the function took in nanoseconds
    double clickFreqShell(); //performs shell sort on clickFreq
    double clickFreqRadix(); //performs radix sort on clickFreq
    void clickFreqCountingSort(int placeVal); //helper function for radix sort

    double leastIngShell();
    double leastIngRadix();
    void leastIngCountingSort(int placeVal);
    
    double leastStepsShell();
    double leastStepsRadix();
    void leastStepsCountingSort(int placeVal);

    double recipePercentShell();
    double recipePercentRadix();
    void recipePercentCountingSort(int placeVal);

    // used to display recipe to interface
    string recipeDetails(string recipeName);


};