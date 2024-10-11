/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * This is a program that runs Polybius' cipher.
 * It utilizes a char type 2D array in which
 * the user message and key is inputed into each boxes.
 * The result is numbers representing rows & cols, but in form of string.
 */

#include "polybius.h"
#include <string>
#include <cctype>
using namespace std;

string mixKey(string key) {
    string newKey = "";
    // After removing duplicates, adding the key value
    // with a const value, ALNUM.
    newKey = removeDuplicate(key + ALNUM);
    
    return newKey;
}


void fillGrid(char grid[SIZE][SIZE], string content) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // For each boxes of 2D array, filling in one character
            // which is from the string content.
            grid[i][j] = content.at(count);
            count++;
        }
    }
}


string findInGrid(char c, char grid[SIZE][SIZE]) {
    string result = "";
    string row = "";
    string col = "";
    
    // Iterating every box of the 2D array through nested for-loops.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // If the character at a certain box is equal to c.
            if (grid[i][j] == c) {
                // Changing each i and j value into char.
                result += (char)(i + '0');
                result += (char)(j + '0');
                // Because of the way it is ordered, it is row + col.
                return result;
            }
        }
    }    
    return result;
}


string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt) {
    string output = "";
    string useKey = "";
    useKey = mixKey(key);
    fillGrid(grid, useKey);
    
    // Encrypt Option
    if (encrypt) {
        for (int i = 0; i < original.length(); i++) {
            // Taking white spaces into consideration, since they are allowed too.
            // White spaces aren't changed in the final output.
            if (isspace(original.at(i))) {
                output += " ";
            }
            // If that character is not a white space.
            else {
                output += findInGrid(original.at(i), grid);
            }
        }
    }
    // Decrypt Option
    else {
        // original.size() - 1 because the col takes one additional index each time.
        for (int i = 0; i < original.size() - 1; i+=2) {
            if (isspace(original.at(i))) {
                output += " ";
                // Since this was just a space (not needed for row & col),
                // need to subtract 1 to view all characters.
                i--;
            }
            else {
                int row = original.at(i) - '0';
                int col = original.at(i + 1) - '0';
                output += grid[row][col];
            }
        }
    }
    return output;
}
