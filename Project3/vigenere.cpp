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
 * This is a program that runs Vigenere's cipher.
 * It utilizes a keyword and based on that,
 * determines the rotation amount for each character.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>
#include <cctype>

string vigenereCipher(string original, string keyword, bool encrypt) {
    // To keep track of the keyword index.
    int counter = 0;
    string result = "";

    // Convert the keyword to uppercase w/o removing non-alphabets.
    for (int i = 0; i < keyword.length(); i++) {
        keyword.at(i) = toupper(keyword.at(i));
    }

    // Iterate over each character in the original input string.
    for (int i = 0; i < original.length(); i++) {
        char currentChar = original.at(i);

        if (isalpha(currentChar)) {
            // Skip non-alphabetic characters in the keyword.
            while (!isalpha(keyword[counter % keyword.length()])) {
                counter++;
            }
            
            // Get the corresponding shift amount from the keyword.
            int shifter = keyword[counter % keyword.length()] - 'A';

            // Encrypt or decrypt the character based on its case (if/else).
            // If uppercase.
            if (isupper(currentChar)) {
                if (encrypt) {
                    result += ((currentChar - 'A' + 
                                shifter) % 26) + 'A';
                } else {
                    result += ((currentChar - 'A' - 
                                shifter + 26) % 26) + 'A';
                }
            } 
            // If lowercase.
            else if (islower(currentChar)) {
                if (encrypt) {
                    result += ((currentChar - 'a' + 
                                shifter) % 26) + 'a';
                } else {
                    result += ((currentChar - 'a' - 
                                shifter + 26) % 26) + 'a';
                }
            }

            // Increment the counter only for alphabetic characters.
            counter++;
        } 
        else {
            // Preserve non-alphabetic characters as they are.
            result += currentChar;
        }
    }
    return result;
}
