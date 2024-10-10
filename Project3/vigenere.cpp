/*
 * vigenere.cpp
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
#include "caesar.h"
#include "vigenere.h"
#include <iostream>
#include <cctype>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    // TODO: implement
    
    string newOriginal = removeNonAlphas(original);
    int counter = 0;
    string result = "";

    // Converting all letters in keywords to upper case.
    string newKeyword = removeNonAlphas(keyword);
    for (int i=0; i<newKeyword.length(); i++) {
        newKeyword.at(i) = toupper(newKeyword.at(i));
    }
    
    while (counter < newOriginal.length()) {
        for (int i=0; i<original.length(); i++) {
            if (isalpha(original.at(i))) {
                int shifter = newKeyword.at(counter % newKeyword.length()) - 'A';
                
                // If upper case character
                if (isupper(original.at(i))) {
                    if (encrypt) {
                        result += ((original.at(i) - 'A' + shifter) % 26) + 'A';
                    }
                    else {
                        result += ((original.at(i) - 'A' - shifter + 26) % 26) + 'A';

                    }
                }
            
                // If lower case character
                else if (islower(original.at(i))) {
                    if (encrypt) {
                        result += ((original.at(i) - 'a' + shifter) % 26) + 'a';
                    }
                    else {
                        result += ((original.at(i) - 'a' - shifter + 26) % 26) + 'a';
                    }
                }
                counter++;
                result += original.at(i);
            }
            else {
                result += original.at(i);
            }
        }
    }
    return result;
}
