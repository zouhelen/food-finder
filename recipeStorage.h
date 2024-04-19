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
    struct recipeData {
        string recipeName;
        vector<string> ingredients;
        vector<string> directions;
        vector<string> ingList;
    };
    unordered_map<string, recipeData> recipeList;
    map<string, recipeData> ingredientList;

    set<string, recipeData> ingreSet;

    vector<pair<string, int>> freq; //pair: ingredient name, click frequency 
    vector<pair<string, int>> leastIngre; //pair: ingredient name, least ingredients
    vector<pair<string, int>> leastSteps; //pair: ingredient name,  least steps

    vector<string> hadIngre; //contains the name of the ingredients that are chosen
};