/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * This is a program that runs Caesar's cipher.
 * From a given alphabet, we move "key" amount of character to the right/left.
 * It is known as a substitution cipher, and can be taught of as alphabet rotation.
 */

#include "caesar.h"
#include <iostream>
#include <cctype>

char shiftAlphaCharacter(char c, int n) {
    char afterShift;
    
    // Given the condition to only consider alphabets.
    // If between the range a ~ z.
    if (c >= 'a' && c <= 'z') {
        afterShift = ((c - 'a' + n) % 26) + 'a';
        // Handling negative cases.
        if (afterShift < 'a') {
            afterShift += 26;
        }
    }
    // If between the range A ~ Z.
    else if (c >= 'A' && c <= 'Z') {
        afterShift = ((c - 'A' + n) % 26) + 'A';
        // Handling negative cases.
        if (afterShift < 'A') {
            afterShift += 26;
        }
    }
    return afterShift;
}


string caesarCipher(string original, int key, bool encrypt) {
    string result = "";
    
    // Turn to encrypted version.
    if (encrypt) {
        for (int i = 0; i < original.length(); i++) {
            // Changing the alphabets for all of them, iterating with a for-loop.
            if (isalpha((original.at(i)))) {
                result += shiftAlphaCharacter(original.at(i), key);
            }
            // If not an alphabet, nothing changes.
            else {
                result += original.at(i);
            }
        }
    }

    // Turn to original version. (decrypt)
    else {
        // By negating, switch the direction of rotation.
        key = -1 * key;
        
        for (int i = 0; i < original.length(); i++) {
            if (isalpha((original.at(i)))) {
                result += shiftAlphaCharacter(original.at(i), key);
            }
            else {
                result += original.at(i);
            }
        }
    }
    return result;
}



