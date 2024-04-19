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
    unordered_map<string, recipeData> recipeMap; //contains all the recipes and their data
    unordered_map<string, recipeData> ingredientMap; //contains all ingredients and vectors of the recipes the ingredients are in

    unordered_set<string> chosenIng; //set of the chosen ingredients
    unordered_set<string> restrictedIng;
    set<string> chosenRecipe;

    //contains the names of the ingredients that are chosen
    vector<pair<string, int>> clickFreq; //pair: ingredient name, click frequency 
    vector<pair<string, int>> leastIng; //pair: recipe name, least ingredients
    vector<pair<string, int>> leastSteps; //pair: recipe name,  least steps
    
    vector<string> hadIngre; //contains the names of the ingredients that are chosen    

    // methods
    void readFile();

    //sorts all the vectors with the corresponding algorithm
    //returns the length of time the function took
    auto clickFreqShell();
    auto clickFreqRadix();

    auto leastIngShell();
    auto leastIngRadix();
    
    auto leastStepsShell();
    auto leastRadix();

private:
    string readBrackSeg(std::istream& input);
    string readQuoteSeg(std::string& input);
};