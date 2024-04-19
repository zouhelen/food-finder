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
        string recipeName;
        vector<string> ingredients;
        vector<string> directions;
        vector<string> ingList;
    };

    // public variables
    unordered_map<string, recipeData> recipeMap;
    unordered_map<string, recipeData> ingredientMap;

    unordered_set<string> chosenIng;
    unordered_set<string> restrictedIng;
    set<string> chosenRecipe;

    vector<pair<string, int>> freq; // pair: ingredient name, frequency
    vector<pair<string, string>> leastIngre; // pair: ingredient name,
    vector<pair<string, string>> leastSteps; // pair: ingredient name,

    // methods
    void readFile();

    
};