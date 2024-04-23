<h1> COP3530 Project 3 - Food Finder</h1>

Food Finder is a program that lists recipes based on what ingredients you have and what ingredients you can't use.

Say you have an allergy; it can filter out recipes that use these ingredients.

Food Finder uses three methods to sort the recipes: 
 - recipe with the least amount of ingredients, 
 - recipe with the least amount of steps, and 
 - recipe with the highest percent of ingredients chosen. 

Each of those methods were sorted by both Shell Sort and Radix Sort, allowing their effeciencies to be compared.

Whenever an ingredient is chosen, all recipes containing that ingredient will be added to a subset. When a blacklisted ingredient is chosen, all recipes containing this ingredient will be removed.

Happy cooking :) 


<h3>Setup</h3>

* Clone the respository

	```git clone https://github.com/zouhelen/food-finder```

* Download [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) 2.5.1 (Visual C++ 15 (2017) - 64-bit) and unzip the .zip folder

<h3>Running</h3>

* Open the food-finder project in an IDE of your choice (CLion is recommended)

* Run the program in your IDE