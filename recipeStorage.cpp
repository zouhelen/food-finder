#include "recipeStorage.h"
#include <fstream>
#include <sstream>


/* read file in */
void recipeStorage::readFile() {
    //std::ifstream data("../RecipeNLG_dataset.csv");
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


int recipeStorage::percentIngMatch(string recipe) {
    int numChosenIng = 0;
    for (string ingredient : recipeMap[recipe]->ingList) {
        if (chosenIng.find(ingredient) != chosenIng.end()) {
            numChosenIng++;
        }
    }
    return ((100*numChosenIng) / recipeMap[recipe]->ingList.size());
}

void recipeStorage::ingreUpdater() {
    chosenRecipe.clear();

    // updates chosen recipes based on chosen and restricted ingredients
    for (string ingredient : chosenIng) {
        //for chosenRecipe
        for (string recipe: ingredientMap[ingredient]) {
            chosenRecipe.insert(recipe);
            //std::cout << "Inserted" << std::endl;
        }
    }
    for (string ingredient: restrictedIng) {
        //for chosenRecipe
        for (string recipe: ingredientMap[ingredient]) {
            chosenRecipe.erase(recipe);
        }
    }

    // clear all vectors
    leastIngS.clear();
    leastIngR.clear();
    leastStepsS.clear();
    leastStepsR.clear();
    recipePercentS.clear();
    recipePercentR.clear();
    sortedRecipes.clear();

    // sets up vectors for sorting recipes
    for (string recipe : chosenRecipe) {
        // least ingredient vectors
        leastIngS.push_back({recipe, recipeMap[recipe]->ingList.size()});
        leastIngR.push_back({recipe, recipeMap[recipe]->ingList.size()});
        // least steps vectors
        leastStepsS.push_back({recipe, recipeMap[recipe]->directions.size()});
        leastStepsR.push_back({recipe, recipeMap[recipe]->directions.size()});
        // best ingredient percent match vectors
        recipePercentS.push_back({recipe, percentIngMatch(recipe)});
        recipePercentR.push_back({recipe, percentIngMatch(recipe)});
        // general vector
        sortedRecipes.push_back(recipe);
    }
}

void recipeStorage::generateRecipeSubset(vector<bool> chosenIngre, vector<bool> restrictedIngre) {
    // order of ingredients
    // 0.banana, 1.beef,  2.carrot, 3.cheese,  4.chicken, 5.coconut, 6.cucumber,
    // 7.egg, 8.milk, 9.mushroom, 10.pork, 11.potato, 12.peanut butter, 13.strawberry, 14.tomato
    chosenIngre.clear(); // reset quiz choices
    restrictedIngre.clear();

    if (chosenIngre[0]) { // add based off what the user has chosen to either chosen ing or restricted ing
        chosenIng.insert("bananas");
    }
    if (chosenIngre[1]) {
        chosenIng.insert("beef");
        chosenIng.insert("ground beef");
        chosenIng.insert("corned beef");
    }
    if (chosenIngre[2]) {
        chosenIng.insert("carrot");
        chosenIng.insert("carrots");
        chosenIng.insert("carrot chunks");
    }
    if (chosenIngre[3]) {
        chosenIng.insert("cheese");
        chosenIng.insert("Cheddar cheese");
        chosenIng.insert("cheddar cheese");
        chosenIng.insert("Parmesan cheese");
        chosenIng.insert("Mozzarella cheese");
        chosenIng.insert("Ricotta cheese");
        chosenIng.insert("American cheese");
        chosenIng.insert("sharp cheese");
        chosenIng.insert("grated cheese");
        chosenIng.insert("cottage cheese");
    }
    if (chosenIngre[4]) {
        chosenIng.insert("chicken");
        chosenIng.insert("chicken breasts");
        chosenIng.insert("chicken cutlets");
    }
    if (chosenIngre[5]) {
        chosenIng.insert("coconut");
        chosenIng.insert("moist coconut");
        chosenIng.insert("flaked coconut");
    }
    if (chosenIngre[6]) {
        chosenIng.insert("cucumbers");
    }
    if (chosenIngre[7]) {
        chosenIng.insert("egg");
        chosenIng.insert("eggs");
        chosenIng.insert("egg yolk");
        chosenIng.insert("egg white");
    }
    if (chosenIngre[8]) {
        chosenIng.insert("milk");
        chosenIng.insert("condensed milk");
        chosenIng.insert("buttermilk");
    }
    if (chosenIngre[9]) {
        chosenIng.insert("mushrooms");
        chosenIng.insert("fresh mushrooms");
        chosenIng.insert("cream of mushroom soup");
    }
    if (chosenIngre[11]) {
        chosenIng.insert("pork");
    }
    if (chosenIngre[12]) {
        chosenIng.insert("potatoes");
    }
    if (chosenIngre[10]) {
        chosenIng.insert("peanut butter");
    }
    if (chosenIngre[13]) {
        chosenIng.insert("strawberry");
        chosenIng.insert("strawberries");
        chosenIng.insert("strawberry jello");
    }
    if (chosenIngre[14]) {
        chosenIng.insert("tomato");
        chosenIng.insert("tomatoes");
        chosenIng.insert("tomato paste");
        chosenIng.insert("tomato juice");
        chosenIng.insert("tomato sauce");
        chosenIng.insert("Italian tomatoes");
    }

    // restricted ingredients
    if (restrictedIngre[0]) {
        restrictedIng.insert("bananas");
    }
    if (restrictedIngre[1]) {
        restrictedIng.insert("beef");
        restrictedIng.insert("ground beef");
        restrictedIng.insert("corned beef");
        restrictedIng.insert("beef stock");
        restrictedIng.insert("beef bouillon");
        restrictedIng.insert("Armour dried beef");
    }
    if (restrictedIngre[2]) {
        restrictedIng.insert("carrot");
        restrictedIng.insert("carrots");
        restrictedIng.insert("carrot chunks");
    }
    if (restrictedIngre[3]) {
        restrictedIng.insert("cheese");
        restrictedIng.insert("Cheddar cheese");
        restrictedIng.insert("cheddar cheese");
        restrictedIng.insert("Parmesan cheese");
        restrictedIng.insert("Mozzarella cheese");
        restrictedIng.insert("Ricotta cheese");
        restrictedIng.insert("American cheese");
        restrictedIng.insert("sharp cheese");
        restrictedIng.insert("grated cheese");
        restrictedIng.insert("cottage cheese");
    }
    if (restrictedIngre[4]) {
        restrictedIng.insert("cream of chicken soup");
        restrictedIng.insert("chicken broth");
        restrictedIng.insert("chicken");
        restrictedIng.insert("chicken breasts");
        restrictedIng.insert("chicken cutlets");
    }
    if (restrictedIngre[5]) {
        restrictedIng.insert("coconut");
        restrictedIng.insert("moist coconut");
        restrictedIng.insert("flaked coconut");
    }
    if (restrictedIngre[6]) {
        restrictedIng.insert("cucumbers");
    }
    if (restrictedIngre[7]) {
        restrictedIng.insert("egg");
        restrictedIng.insert("eggs");
        restrictedIng.insert("egg yolk");
        restrictedIng.insert("egg white");
    }
    if (restrictedIngre[8]) {
        restrictedIng.insert("milk");
        restrictedIng.insert("condensed milk");
        restrictedIng.insert("buttermilk");
    }
    if (restrictedIngre[9]) {
        restrictedIng.insert("mushrooms");
        restrictedIng.insert("fresh mushrooms");
        restrictedIng.insert("cream of mushroom soup");
    }
    if (restrictedIngre[10]) {
        restrictedIng.insert("pork");
    }
    if (restrictedIngre[11]) {
        restrictedIng.insert("potatoes");
    }
    if (restrictedIngre[12]) {
        restrictedIng.insert("peanut butter");
    }
    if (restrictedIngre[13]) {
        restrictedIng.insert("strawberry");
        restrictedIng.insert("strawberries");
        restrictedIng.insert("strawberry jello");
    }
    if (restrictedIngre[14]) {
        restrictedIng.insert("tomato");
        restrictedIng.insert("tomatoes");
        restrictedIng.insert("tomato paste");
        restrictedIng.insert("tomato juice");
        restrictedIng.insert("tomato sauce");
        restrictedIng.insert("Italian tomatoes");
    }
    this->ingreUpdater();
}

// sorting algorithms
/*
 * used these sources to create the shell sort:
 * https://www.programiz.com/dsa/shell-sort
 *  https://www.geeksforgeeks.org/shellsort/

 * used these sources to create the radix (and counting) sort:
 * https://www.programiz.com/dsa/radix-sort
 * https://www.geeksforgeeks.org/counting-sort/
 */

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
    sortedRecipes.clear();
    sortedRecipes.resize(chosenRecipe.size());
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
    // updates general sorted recipes list
    sortedRecipes.clear();
    sortedRecipes.resize(chosenRecipe.size());
    for (int i = 0; i < leastIngR.size(); i++) {
        sortedRecipes[i] = leastIngR[i].first;
    }
    return duration; // returns time for sorting
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
    sortedRecipes.clear();
    sortedRecipes.resize(chosenRecipe.size());
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
        leastStepsCountingSort(placeVal);
    }
    //stops the clock
    auto stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count();
    // updates general sorted recipes list
    sortedRecipes.clear();
    sortedRecipes.resize(chosenRecipe.size());
    for (int i = 0; i < leastStepsR.size(); i++) {
        sortedRecipes[i] = leastStepsR[i].first;
    }
    return duration; // returns time for sorting
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
    sortedRecipes.clear();
    sortedRecipes.resize(chosenRecipe.size());
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
    // updates general sorted recipes list
    sortedRecipes.clear();
    sortedRecipes.resize(chosenRecipe.size());
    for (int i = 0; i < leastIngR.size(); i++) {
        sortedRecipes[i] = leastIngR[i].first;
    }
    return duration; // returns time for sorting
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

string recipeStorage::recipeDetails(string recipeName) { // formats and returns a selected recipe as one string
    string details = "";

    details += recipeName + "\n\n";
    details += "Ingredients\n";
    for (string ingredient : recipeMap[recipeName]->ingMeasurements) {
        details += ingredient + "\n";
    }
    details += "\nDirections\n";
    for (string direction : recipeMap[recipeName]->directions) {
        while (direction.length() > 70) {
            details += direction.substr(0, 70) + "\n";
            direction = direction.substr(70);
        }
        details += direction + "\n";
    }
    return details;
}
string recipeStorage::halfRecipeDetails(string recipeName){ // formatting for a selected recipe as one string, the half card
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
