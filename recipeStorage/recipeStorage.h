#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::unordered_map;
using std::map;
using std::set;
using std::pair;

class recipeStorage {
public:
    struct recipeData {
        string recipeName; //name of each recipe
        vector<string> ingredients; //vector of ingredients and their amounts for each recipe
        vector<string> directions; //vector of directions/steps for each recipe
        vector<string> ingList; //vector of just the ingredients for each recipe
    };
    unordered_map<string, recipeData> recipeList; //contains all the recipes and their data
    map<string, vector<recipeData>> ingredientList; //contains all ingredients and vectors of the recipes the ingredients are in

    set<string> chosenIngre; //set of the chosen ingredients

    //contains the names of the ingredients that are chosen
    vector<pair<string, int>> clickFreq; //pair: ingredient name, click frequency 
    vector<pair<string, int>> leastIng; //pair: recipe name, least ingredients
    vector<pair<string, int>> leastSteps; //pair: recipe name,  least steps

    vector<string> hadIngre; //contains the names of the ingredients that are chosen    

private:
    void readFile();
    
    //sorts all the vectors with the corresponding algorithm
    //returns the length of time the function took
    auto clickFreqShell();
    auto clickFreqRadix();

    auto leastIngShell();
    auto leastIngRadix();
    
    auto leastStepsShell();
    auto leastRadix();
    
};