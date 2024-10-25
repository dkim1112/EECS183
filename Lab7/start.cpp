/**
 * start.cpp
 *
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Lab 7
 * Taken from Project 4: CoolPics
 *
 * main function to call test cases
 */

#include <iostream>
#include <string>

using namespace std;

//********************************************************
// Function declaration. 
// Function definition in test.cpp
//********************************************************
void startTests();

int main() {
    
    cout << "-------------------------------" << endl
         << "  EECS 183 Lab 7 Menu Options  " << endl
         << "-------------------------------" << endl;
    cout << "1) Execute testing functions in test.cpp" << endl;    
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    if (choice == 1) {
        startTests();
    }
    
    return 0;
}
