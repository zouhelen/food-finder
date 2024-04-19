#include "recipeStorage.h"
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

auto clickFreqRadix() {

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

auto leastIngRadix();

auto leastStepsShell();
auto leastRadix();