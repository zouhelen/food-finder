#include "recipeStorage.h"
#include <fstream>
#include <sstream>


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
    int indexTest=0;
    while (std::getline(data, line)) {
        //std::getline(data, line);
        string name;
        std::stringstream lineStream(line); // put line into a string stream
        recipeData* recipe = new recipeData; // new recipe struc allocated to heap

        /* load title + save as var (comma to comma) */

        std::getline(lineStream, scrap, ',');
        std::getline(lineStream, name, ',');
        recipe->recipeName = name;
        //recipe name test
        //std::cout << indexTest << ": recipe name: " << recipe->recipeName << std::endl;


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
        /* ingredients testing
        std::cout << "ingredients: \n";
        for (string ing: recipe->ingMeasurements) {
            std::cout << ing << std::endl;
        }
         */

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
        /* directions testing
        std::cout << "directions: \n";
        for (string step: recipe->directions) {
            std::cout << step << std::endl;
        }
         */

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
                recipe->ingList.insert(oneIng);
                // add recipe to corresponding ingredient map
                if (ingredientMap.find(oneIng) == ingredientMap.end()) {
                    unordered_set<string> recipeList;
                    recipeList.insert(recipe->recipeName);
                    ingredientMap[oneIng] = recipeList;
                }
                else {
                    //if(ingredientMap[oneIng])
                    ingredientMap[oneIng].insert(recipe->recipeName);
                }
            }
        }

        /* ingredient testing
        std::cout << "ingredients: \n";
        for (string ing: recipe->ingList) {
            std::cout << ing << std::endl;
        }
         */
        recipeMap[recipe->recipeName] = recipe;
        indexTest++;
        //std::cout << line << std::endl;
    }

    /*
    // print out ingredient map to test
    for (auto& pair: ingredientMap) {
        std::cout << "ingredient: " << pair.first << "\n";
        std::cout << "recipes: ";
        for (string recipe: pair.second) {
            std::cout << recipe << ", ";
        }
        std::cout << "\n\n";
    }
     */

    data.close();
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


void recipeStorage::addChosenIngre(string ingredient) {
    chosenIng.insert(ingredient);
}
void recipeStorage::chooseIngreUpdater() {
    //updates the other functions for every chosen ingredient
    for (string ingredient : chosenIng) {
        //for chosenRecipe
        for (string recipe: ingredientMap[ingredient]) {
            chosenRecipe.insert(recipe);
        }


        //set containing recipes needing this ingredient
        unordered_set<string> recipes;
        for (string recipe : ingredientMap[ingredient]) {
            recipes.insert(recipe);
        }
        //for leastIng, leastSteps, and recipePercent
        //removes the recipes from recipes (the set) that are already in leastIng/leastSteps/recipePercent so only new values are added
        //for shell sort
        for (pair<string, int> recipePair : leastIngS) {
            if (recipes.find(recipePair.first) != recipes.end()) {
                recipes.erase(recipePair.first);
            }
        }
        //for radix sort
        for (pair<string, int> recipePair : leastIngR) {
            if (recipes.find(recipePair.first) != recipes.end()) {
                recipes.erase(recipePair.first);
            }
        }
        //adds the recipes containing the ingredient and the value the vectors are sorted by
        //for every recipe that's not added yet, add it to each vector
        for (string aRecipe : recipes) {
            //for shell sort
            leastIngS.push_back(pair<string, int> (aRecipe, recipeMap[aRecipe]->ingList.size()));
            leastStepsS.push_back(pair<string, int> (aRecipe, recipeMap[aRecipe]->directions.size()));
            //number of ingredients in a recipe that have been chosen
            int chosenCounter = 0;
            for (string ingre : recipeMap[aRecipe]->ingList) {
                if (chosenIng.find(ingre) != chosenIng.end())
                    chosenCounter++;
            }
            recipePercentS.push_back(pair<string, int> (aRecipe, (100*(chosenCounter))/(recipeMap[aRecipe]->ingList.size())));
            //for radix sort
            leastIngR.push_back(pair<string, int> (aRecipe, recipeMap[aRecipe]->ingList.size()));
            leastStepsR.push_back(pair<string, int> (aRecipe, recipeMap[aRecipe]->directions.size()));
            //number of ingredients in a recipe that have been chosen
            recipePercentR.push_back(pair<string, int> (aRecipe, (100*(chosenCounter))/(recipeMap[aRecipe]->ingList.size())));
        }
    }
}

void recipeStorage::addRestrictIngre(string ingredient) {
    restrictedIng.insert(ingredient);
}
void recipeStorage::restrictIngreUpdater() {
    for (string ingredient: restrictedIng) {
        //for chosenRecipe
        for (string recipe: ingredientMap[ingredient]) {
            chosenRecipe.erase(recipe);
        }

        //set containing recipes needing this ingredient
        unordered_set<string> recipes;
        for (string recipe: ingredientMap[ingredient]) {
            recipes.insert(recipe);
        }
        //for leastIng, leastSteps, and recipePercent
        //removes the recipes containing the ingredient and the value the vectors are sorted by
        for (string aRecipe: recipes) {
            //shell sort vectors
            for (vector<pair<string, int>>::iterator iter = leastIngS.begin(); iter < leastIngS.end(); iter++) {
                if (aRecipe == (*iter).first)
                    leastIngS.erase(iter);
            }
            for (vector<pair<string, int>>::iterator iter = leastStepsS.begin(); iter < leastStepsS.end(); iter++) {
                if (aRecipe == (*iter).first)
                    leastStepsS.erase(iter);
            }
            for (vector<pair<string, int>>::iterator iter = recipePercentS.begin();
                 iter < recipePercentS.end(); iter++) {
                if (aRecipe == (*iter).first)
                    recipePercentS.erase(iter);
            }
            //radix sort vectors
            for (vector<pair<string, int>>::iterator iter = leastIngR.begin(); iter < leastIngR.end(); iter++) {
                if (aRecipe == (*iter).first)
                    leastIngR.erase(iter);
            }
            for (vector<pair<string, int>>::iterator iter = leastStepsR.begin(); iter < leastStepsR.end(); iter++) {
                if (aRecipe == (*iter).first)
                    leastStepsR.erase(iter);
            }
            for (vector<pair<string, int>>::iterator iter = recipePercentR.begin();
                 iter < recipePercentR.end(); iter++) {
                if (aRecipe == (*iter).first)
                    recipePercentR.erase(iter);
            }
        }
    }
    // initialize empty elements for sorted recipes vector
    sortedRecipes.resize(leastIngS.size());
}

void recipeStorage::generateRecipeSubset(vector<bool> chosenIngre, vector<bool> restrictedIngre) {
    // order of ingredients
    // 0.banana, 1.beef,  2.carrot, 3.cheese,  4.chicken, 5.coconut, 6.cucumber,
    // 7.egg, 8.milk, 9.mushroom, 10.pork, 11.potato, 12.peanut butter, 13.strawberry, 14.tomato
    chosenIngre.clear();
    restrictedIngre.clear();
    if (chosenIngre[0]) {
        this->addChosenIngre("bananas");
    }
    if (chosenIngre[1]) {
        this->addChosenIngre("beef");
        this->addChosenIngre("ground beef");
        this->addChosenIngre("corned beef");
    }
    if (chosenIngre[2]) {
        this->addChosenIngre("carrot");
        this->addChosenIngre("carrots");
        this->addChosenIngre("carrot chunks");
    }
    if (chosenIngre[3]) {
        this->addChosenIngre("cheese");
        this->addChosenIngre("Cheddar cheese");
        this->addChosenIngre("cheddar cheese");
        this->addChosenIngre("Parmesan cheese");
        this->addChosenIngre("Mozzarella cheese");
        this->addChosenIngre("Ricotta cheese");
        this->addChosenIngre("American cheese");
        this->addChosenIngre("sharp cheese");
        this->addChosenIngre("grated cheese");
        this->addChosenIngre("cottage cheese");
    }
    if (chosenIngre[4]) {
        this->addChosenIngre("chicken");
        this->addChosenIngre("chicken breasts");
        this->addChosenIngre("chicken cutlets");
    }
    if (chosenIngre[5]) {
        this->addChosenIngre("coconut");
        this->addChosenIngre("moist coconut");
        this->addChosenIngre("flaked coconut");
    }
    if (chosenIngre[6]) {
        this->addChosenIngre("cucumbers");
    }
    if (chosenIngre[7]) {
        this->addChosenIngre("egg");
        this->addChosenIngre("eggs");
        this->addChosenIngre("egg yolk");
        this->addChosenIngre("egg white");
    }
    if (chosenIngre[8]) {
        this->addChosenIngre("milk");
        this->addChosenIngre("condensed milk");
        this->addChosenIngre("buttermilk");
    }
    if (chosenIngre[9]) {
        this->addChosenIngre("mushrooms");
        this->addChosenIngre("fresh mushrooms");
        this->addChosenIngre("cream of mushroom soup");
    }
    if (chosenIngre[11]) {
        this->addChosenIngre("pork");
    }
    if (chosenIngre[12]) {
        this->addChosenIngre("potatoes");
    }
    if (chosenIngre[10]) {
        this->addChosenIngre("peanut butter");
    }
    if (chosenIngre[13]) {
        this->addChosenIngre("strawberry");
        this->addChosenIngre("strawberries");
        this->addChosenIngre("strawberry jello");
    }
    if (chosenIngre[14]) {
        this->addChosenIngre("tomato");
        this->addChosenIngre("tomatoes");
        this->addChosenIngre("tomato paste");
        this->addChosenIngre("tomato juice");
        this->addChosenIngre("tomato sauce");
        this->addChosenIngre("Italian tomatoes");
    }


    // restricted ingredients
    if (restrictedIngre[0]) {
        this->addRestrictIngre("bananas");
    }
    if (restrictedIngre[1]) {
        this->addRestrictIngre("beef");
        this->addRestrictIngre("ground beef");
        this->addRestrictIngre("corned beef");
        this->addRestrictIngre("beef stock");
        this->addRestrictIngre("beef bouillon");
        this->addRestrictIngre("Armour dried beef");
    }
    if (restrictedIngre[2]) {
        this->addRestrictIngre("carrot");
        this->addRestrictIngre("carrots");
        this->addRestrictIngre("carrot chunks");
    }
    if (restrictedIngre[3]) {
        this->addRestrictIngre("cheese");
        this->addRestrictIngre("Cheddar cheese");
        this->addRestrictIngre("cheddar cheese");
        this->addRestrictIngre("Parmesan cheese");
        this->addRestrictIngre("Mozzarella cheese");
        this->addRestrictIngre("Ricotta cheese");
        this->addRestrictIngre("American cheese");
        this->addRestrictIngre("sharp cheese");
        this->addRestrictIngre("grated cheese");
        this->addRestrictIngre("cottage cheese");
    }
    if (restrictedIngre[4]) {
        this->addRestrictIngre("cream of chicken soup");
        this->addRestrictIngre("chicken broth");
        this->addRestrictIngre("chicken");
        this->addRestrictIngre("chicken breasts");
        this->addRestrictIngre("chicken cutlets");
    }
    if (restrictedIngre[5]) {
        this->addRestrictIngre("coconut");
        this->addRestrictIngre("moist coconut");
        this->addRestrictIngre("flaked coconut");
    }
    if (restrictedIngre[6]) {
        this->addRestrictIngre("cucumbers");
    }
    if (restrictedIngre[7]) {
        this->addRestrictIngre("egg");
        this->addRestrictIngre("eggs");
        this->addRestrictIngre("egg yolk");
        this->addRestrictIngre("egg white");
    }
    if (restrictedIngre[8]) {
        this->addRestrictIngre("milk");
        this->addRestrictIngre("condensed milk");
        this->addRestrictIngre("buttermilk");
    }
    if (restrictedIngre[9]) {
        this->addRestrictIngre("mushrooms");
        this->addRestrictIngre("fresh mushrooms");
        this->addRestrictIngre("cream of mushroom soup");
    }
    if (restrictedIngre[10]) {
        this->addRestrictIngre("pork");
    }
    if (restrictedIngre[11]) {
        this->addRestrictIngre("potatoes");
    }
    if (restrictedIngre[12]) {
        this->addRestrictIngre("peanut butter");
    }
    if (restrictedIngre[13]) {
        this->addRestrictIngre("strawberry");
        this->addRestrictIngre("strawberries");
        this->addRestrictIngre("strawberry jello");
    }
    if (restrictedIngre[14]) {
        this->addRestrictIngre("tomato");
        this->addRestrictIngre("tomatoes");
        this->addRestrictIngre("tomato paste");
        this->addRestrictIngre("tomato juice");
        this->addRestrictIngre("tomato sauce");
        this->addRestrictIngre("Italian tomatoes");
    }

    this->chooseIngreUpdater();

    this->restrictIngreUpdater();
}
// all the sorts
double recipeStorage::leastIngShell() {
    //start the clock
    auto start = std::chrono::high_resolution_clock::now();
    //the gap starts at the vector size
    int gap = leastIngS.size()/2;
    while (gap > 0) {
        //does an insertions sort for this gap size
        for (int i = gap; i < leastIngS.size(); i++) {
            pair<string, int> temp = leastIngS[i];
            int j;
            //second condition in the second statement makes it least to greatest
            for (j = i; j >= gap && leastIngS[j-gap].second > temp.second; j -= gap) {
                leastIngS[j] = leastIngS[j-gap];
            }
            leastIngS[j] = temp;
        }
        //gap halves through every passthrough
        gap /= 2;
    }
    //stops the clock
    auto stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count();
    // updates general sorted recipes list
    for (int i = 0; i < leastIngS.size(); i++) {
        sortedRecipes[i] = leastIngS[i].first;
    }
    return duration; // returns time for sorting
}

double recipeStorage::leastIngRadix() {
    //start the clock
    auto start = std::chrono::high_resolution_clock::now();
    //finds the maximum number
    int max = leastIngR[0].second;
    for (pair<string, int> pairItr : leastIngR) {
        max = std::max(max, pairItr.second);
    }

    // run helper sort function for each place of each recipe's number of ingredients
    for (int placeVal = 1; max/placeVal > 0; placeVal *= 10) {
        leastIngCountingSort(placeVal);
    }
    //stops the clock
    auto stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count();
    //returns the sorted time
    return duration;
}

void recipeStorage::leastIngCountingSort(int placeVal) {
    int count[] = {0,0,0,0,0,0,0,0,0,0}; // one slot for each digit 0-9
    // initialize array of same size and type of leastIng - used to temporarily store sorted results
    //will be used to store the ouput that goes into leastFreq
    pair<string, int> output[leastIngR.size()];
    //gets the count of every element
    for (int i = 0; i < leastIngR.size(); i++) {
        count[(leastIngR[i].second / placeVal) % 10] = count[(leastIngR[i].second / placeVal) % 10] + 1; // increment count at the index of the digit
    }
    //makes the cumulative count and sorts the elements; this is where greatest to least or vice versa is decided
    for (int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }
    //elements are placed into the sorted order
    for (int k = leastIngR.size()-1; k >= 0; k--) {
        output[count[(leastIngR[k].second / placeVal) % 10] - 1] = leastIngR[k];
        count[(leastIngR[k].second / placeVal) % 10]--;
    }
    //transfers output to leastIng
    for (int l = 0; l < leastIngR.size(); l++) {
        leastIngR[l] = output[l];
    }
}

double recipeStorage::leastStepsShell() {
    //start the clock
    auto start = std::chrono::high_resolution_clock::now();
    //the gap starts at the vector size
    int gap = leastStepsS.size();
    while (gap > 0) {
        //does an insertions sort for this gap size
        for (int i = gap; i < leastStepsS.size(); i++) {
            pair<string, int> temp = leastStepsS[i];
            int j;
            //second condition in the second statement makes it least to greatest
            for (j = i; j > gap && leastStepsS[j-gap].second > temp.second; j -= gap) {
                leastStepsS[j] = leastStepsS[j-gap];
            }
            leastStepsS[j] = temp;
        }
        //gap halves through every passthrough
        gap /= 2;
    }
    //stops the clock
    auto stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count();
    // updates general sorted recipes list
    for (int i = 0; i < leastStepsS.size(); i++) {
        sortedRecipes[i] = leastStepsS[i].first;
    }
    return duration; // returns time for sorting
}

double recipeStorage::leastStepsRadix() {
    //start the clock
    auto start = std::chrono::high_resolution_clock::now();
    //finds the maximum number
    int max = leastStepsR[0].second;
    for (pair<string, int> pairItr : leastStepsR) {
        max = std::max(max, pairItr.second);
    }

    // run helper sort function for each place of each recipe's number of ingredients
    for (int placeVal = 1; max/placeVal > 0; placeVal *= 10) {
        leastIngCountingSort(placeVal);
    }
    //stops the clock
    auto stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count();
    //returns the sorted time
    return duration;
}

void recipeStorage::leastStepsCountingSort(int placeVal) {
    int count[] = {0,0,0,0,0,0,0,0,0,0}; // one slot for each digit 0-9
    // initialize array of same size and type of leastIng - used to temporarily store sorted results
    //will be used to store the ouput that goes into leastSteps
    pair<string, int> output[leastStepsR.size()];
    //gets the count of every element
    for (int i = 0; i < leastStepsR.size(); i++) {
        count[(leastStepsR[i].second / placeVal) % 10] = count[(leastStepsR[i].second / placeVal) % 10] + 1;
    }
    //makes the cumulative count and sorts the elements; this is where greatest to least or vice versa is decided
    for (int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }
    //elements are placed into the sorted order
    for (int k = leastStepsR.size()-1; k >= 0; k--) {
        output[count[(leastStepsR[k].second / placeVal) % 10] - 1] = leastStepsR[k];
        count[(leastStepsR[k].second / placeVal) % 10]--;
    }
    //transfers output to leastSteps
    for (int l = 0; l < leastStepsR.size(); l++) {
        leastStepsR[l] = output[l];
    }
}

double recipeStorage::recipePercentShell() {
    //start the clock
    auto start = std::chrono::high_resolution_clock::now();
    //the gap starts at the vector size
    int gap = recipePercentS.size();
    while (gap > 0) {
        //does an insertions sort for this gap size
        for (int i = gap; i < recipePercentS.size(); i++) {
            pair<string, int> temp = recipePercentS[i];
            int j;
            //second condition in the second statement makes it greatest to least
            for (j = i; j >= gap && recipePercentS[j-gap].second < temp.second; j -= gap) {
                recipePercentS[j] = recipePercentS[j-gap];
            }
            recipePercentS[j] = temp;
        }
        //gap halves through every passthrough
        gap /= 2;
    }
    //stops the clock
    auto stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count();
    // updates general sorted recipes list
    for (int i = 0; i < recipePercentS.size(); i++) {
        sortedRecipes[i] = recipePercentS[i].first;
    }
    return duration; // returns the time for sorting

}

double recipeStorage::recipePercentRadix() {
    //start the clock
    auto start = std::chrono::high_resolution_clock::now();
    //finds the maximum number
    int max = recipePercentR[0].second;
    for (pair<string, int> pairItr : recipePercentR) {
        max = std::max(max, pairItr.second);
    }

    // run helper sort function for each place of each recipe's number of ingredients
    for (int placeVal = 1; max/placeVal > 0; placeVal *= 10) {
        recipePercentCountingSort(placeVal);
    }
    //stops the clock
    auto stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count();
    //returns the sorted time
    return duration;

}

void recipeStorage::recipePercentCountingSort(int placeVal) {
    //initializes count
    int count[] = {0,0,0,0,0,0,0,0,0,0}; // one slot for each digit 0-9
    // initialize array of same size and type of recipePercent - used to temporarily store sorted results
    //will be used to store the ouput that goes into recipePercent
    pair<string, int> output[recipePercentR.size()];
    //gets the count of every element
    for (int i = 0; i < recipePercentR.size(); i++) {
        count[(recipePercentR[i].second / placeVal) % 10] = count[(recipePercentR[i].second / placeVal) % 10] + 1; // increment count at the index of the digit
    }
    //makes the cumulative count and sorts the elements; this is where greatest to least or vice versa is decided
    for (int j = 8; j >= 0; j--) {
        count[j] += count[j+1];
    }
    //elements are placed into the sorted order
    for (int k = recipePercentR.size()-1; k >= 0; k--) {
        output[count[(recipePercentR[k].second / placeVal) % 10] - 1] = recipePercentR[k];
        count[(recipePercentR[k].second / placeVal) % 10]--;
    }
    //transfers output to recipePercent
    for (int l = 0; l < recipePercentR.size(); l++) {
        recipePercentR[l] = output[l];
    }

}

string recipeStorage::recipeDetails(string recipeName) {
    string details = "";

    details += recipeName + "\n\n";
    details += "Ingredients\n";
    for (string ingredient : recipeMap[recipeName]->ingMeasurements) {
        details += ingredient + "\n";
    }
    details += "\nDirections\n";
    for (string direction : recipeMap[recipeName]->directions) {
        details += direction + "\n";
    }
    return details;
}
string recipeStorage::halfRecipeDetails(string recipeName){
    string details = "";
    details += recipeName + "\n\n";
    details += "Ingredients\n";
    int count = 0;
    for (string ingredient : recipeMap[recipeName]->ingMeasurements) {
        if(count > 3){
            break;
        }
        while (ingredient.length() > 30) {
            details += ingredient.substr(0, 30) + "\n";
            ingredient = ingredient.substr(30);
        }

        details += ingredient + "\n";
        count ++;
    }
    return details;
}
