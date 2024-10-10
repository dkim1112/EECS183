
/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>
#include <cctype>

//************************************************************************
// Implement the functions below this line.
//************************************************************************


/*
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns a copy of original string with all alphabetical
 *           characters converted to uppercase. All other characters (numbers,
 *           symbols, spaces, punctuation marks, etc.) are unchanged.
 */

string toUpperCase(string original) {
    // TODO: implement
    string upString = "";
    for (int i=0; i<original.length(); i++) {
        upString += toupper(original.at(i));
    }
    return upString;
}

string removeNonAlphas(string original) {
    // TODO: implement
    string nonAlpha = "";
    for (int i=0; i<original.length(); i++) {
        if (isalpha(original.at(i))) {
            nonAlpha = original.at(i);
        }
    }
    return nonAlpha;
}

int charToInt(char original) {
    // TODO: implement
    int integer = 0;
    integer = original;
    
    return integer;
}

string removeDuplicate(string original) {
    // TODO: implement
    string noOverLap = "";
    
    for (int i=0; i<original.length(); i++) {
        char cur = original.at(i);
        bool isDuplicate = false;
        
        for (int j=0; j<noOverLap.length(); j++) {
            if (cur == noOverLap.at(j)) {
                isDuplicate = true;
                break;
            }
        }
        
        if (!isDuplicate) {
            noOverLap += cur;
        }
    }
    return noOverLap;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
