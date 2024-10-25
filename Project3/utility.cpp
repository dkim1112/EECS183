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
 * This is a program for utilities.
 * The pre-built tools here can be used for
 * efficient coding of 3 different ciphers.
 * They are composed of commonly used tools while ciphering texts.
 */

#include "utility.h"
#include <iostream>
#include <cctype>

string toUpperCase(string original) {
    string upString = "";
    
    // Upper casing each character.
    for (int i = 0; i < original.length(); i++) {
        upString += toupper(original.at(i));
    }
    return upString;
}


string removeNonAlphas(string original) {
    string newStr;
    
    for (int i = 0; i < original.size(); i++) {
        // While running through the entire text until its length,
        // It adds character-by-chracter to a new string newStr
        // If it is an alphabet (a~z OR A~Z).
        if (isalpha(original.at(i))) {
            newStr += original.at(i);
        }
    }
    return newStr;
}


int charToInt(char original) {
    int integer = 0;
    
    // Manually converting char to integer type.
    integer = original - '0';
    return integer;
}


string removeDuplicate(string original) {
    string noOverLap = "";
    
    for (int i = 0; i < original.length(); i++) {
        char cur = original.at(i);
        bool isDuplicate = false;
        
        for (int j = 0; j < noOverLap.length(); j++) {
            if (cur == noOverLap.at(j)) {
                isDuplicate = true;
                break;
            }
        }
        
        // Only add to the new string if there are no duplicates.
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
