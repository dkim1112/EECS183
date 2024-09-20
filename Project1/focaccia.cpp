/**
 * focaccia.cpp
  * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 1
 * Fall 2024
 * 
 * This program creates a list and number of ingredients needed to bake the focaccia based on the amount of people needed to be served. Ingredients for focaccia bread includes bags of flour, packages of yeast, canisters of salt, and bottles of olive oil (water is disregarded). After computing the number needed for each ingredients, it then computes the total cost considering each price.
 *
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string pluralize(string singular, string plural, int number);

int main() {
    // intializing an integer variable needed to save user's input
    int people;
    
    // Asking the user for the number of people being served with focaccia bread
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    // Calculating amount of focaccia loaves needed, as each serve upto 4 people
    int loaves = ceil(people / 4.0);
    
    // Displaying the amount of loaf/loaves needed as a result
    cout << "You need to make: " << loaves << " " << pluralize("loaf", "loaves", loaves) << " of focaccia" << endl << endl;
    
    // Starting to display each amount of ingredients needed, what's called the shopping list
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;

    // Stores how much each ingredient is needed per loaf & how much it contains per package
    const double FLOUR_CUPS_PER_LOAF = 5.0;
    const double YEAST_PER_LOAF = 1.75;
    const double SALT_PER_LOAF = 1.875;
    const double OLIVE_OIL_PER_LOAF = 2.0;
    const double FLOUR_CUPS_PER_BAG = 20.0;
    const double YEAST_TEASPOONS_PER_PACKAGE = 2.25;
    const double SALT_TEASPOONS_PER_CANISTER = 6.0;
    const double OIL_TABLESPOONS_PER_BOTTLE = 33.783;

    // Calculating the number of each ingredients needed, based on values saved above
    int flourBags = ceil((loaves * FLOUR_CUPS_PER_LOAF) / FLOUR_CUPS_PER_BAG);
    int yeastPackages = ceil((loaves * YEAST_PER_LOAF) / YEAST_TEASPOONS_PER_PACKAGE);
    int saltCanisters = ceil((loaves * SALT_PER_LOAF) / SALT_TEASPOONS_PER_CANISTER);
    int oliveOilBottle = ceil((loaves * OLIVE_OIL_PER_LOAF) / OIL_TABLESPOONS_PER_BOTTLE);
    
    // After calculation, displaying the amount of ingredients needed for each
    // Calls the pluralize function to check if ingredient is more than 1
    cout << flourBags << " " << pluralize("bag", "bags", flourBags) << " of flour" << endl;
    cout << yeastPackages << " " << pluralize("package", "packages", yeastPackages) << " of yeast" << endl;
    cout << saltCanisters << " " << pluralize("canister", "canisters", saltCanisters) << " of salt" << endl;
    cout << oliveOilBottle << " " << pluralize("bottle", "bottles", oliveOilBottle) << " of olive oil" << endl << endl;
    
    // Calculating the price of each ingredients based on how much they were needed
    double flourBagsCost = flourBags * 2.69;
    double yeastPackagesCost = yeastPackages * 0.4;
    double saltCanistersCost = saltCanisters * 0.49;
    double oliveOilBottleCost = oliveOilBottle * 6.39;
    
    // For readability of code, separate variable totalCost saves total cost calculated above
    double totalCost = flourBagsCost + yeastPackagesCost + saltCanistersCost + oliveOilBottleCost;
    
    // Displays the total cost of all the ingredients in sum
    cout << "Total expected cost of ingredients: $" << totalCost << endl << endl;
    
    // Closing message and indicates that the program has completed successfully
    cout << "Have a great party!" << endl;
    
    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
