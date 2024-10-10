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
 * <#description#>
 */

#include "caesar.h"
#include <iostream>
#include <cctype>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

char shiftAlphaCharacter(char c, int n) {
    // TODO: implement
    char afterShift;
    
    // Given that we only consider alphabets.
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
    // TODO: implement
    string result = "";
    
    // Turn to encrypted version.
    if (encrypt) {
        for (int i=0; i<original.length(); i++) {
            if (isalpha((original.at(i)))) {
                result += shiftAlphaCharacter(original.at(i), key);
            }
            else {
                result += original.at(i);
            }
        }
    }
    
    // Turn to original version. (un-encrypt)
    else {
        key = -1 * key;
        for (int i=0; i<original.length(); i++) {
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



