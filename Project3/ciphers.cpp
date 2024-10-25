/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * This is a program that calls all of the 3 cipher options.
 * By receiving what type of cipher, encrypt/decrypt, and message,
 * it successfully outputs the ciphered results.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void ciphers() {
    string choice;
    string encDec;
    string original;

    int key_caesar;
    string key_vigenere;
    string key_polybius;
    
    // Asking user what cipher to try out.
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): " << endl;
    getline(cin, choice);
    choice = toUpperCase(choice);
    
    // If valid input for cipher choice.
    // Since all of them are uppercased already, 
    // no need to worry for lower cases.
    if (choice == "CAESAR" || choice == "C" || choice == "VIGENERE"
       || choice == "V" || choice == "POLYBIUS" || choice == "P") {
        
        // Asking user whether to encrypt or decrypt.
        cout << "Encrypt or decrypt: " << endl;
        getline(cin, encDec);
        encDec = toUpperCase(encDec);
        
        // If valid input for encrypt/decrypt.
        if (encDec == "ENCRYPT" || encDec == "DECRYPT"
           || encDec == "E" || encDec == "D") {
            
            // Asking user for the message to be ciphered.
            // This applies to all 3 cipher programs.
            cout << "Enter a message: " << endl;
            getline(cin, original);
            
            // Option 1: If CAESAR OR C was chosen.
            if (choice == "CAESAR" || choice == "C") {
                cout << "What is your key: " << endl;
                cin >> key_caesar;
                if (encDec == "ENCRYPT" || encDec == "E") {
                    cout << "The encrypted message is: ";
                    // 1 stands for true.
                    cout << caesarCipher(original, key_caesar, 1);
                }
                else {
                    cout << "The decrypted message is: ";
                    // 0 stands for false.
                    cout << caesarCipher(original, key_caesar, 0);
                }
            }
            
            // Option 2: If VIGENERE OR V was chosen.
            else if (choice == "VIGENERE" || choice == "V") {
                cout << "What is your key: " << endl;
                getline(cin, key_vigenere);
                bool isNum = false;
                
                // Checking if there are any part of key that is a digit.
                for (int i = 0; i < key_vigenere.length(); i++) {
                    if (!isdigit(key_vigenere.at(i))) {
                        isNum = true;
                    }
                    else {
                        isNum = false;
                        break;
                    }
                }
               
                // If there was no digit in the key_vigenere.
                if (isNum) {
                    if (encDec == "ENCRYPT" || encDec == "E") {
                        cout << "The encrypted message is: ";
                        cout << vigenereCipher(original, key_vigenere, 1) << endl;
                    }
                    else {
                        cout << "The decrypted message is: ";
                        cout << vigenereCipher(original, key_vigenere, 0) << endl;
                    }
                }
                // If there was digit in the key_vigenere.
                else {
                    cout << "Invalid key!" << endl;
                }
            }
            
            // Option 3: If POLYBIUS OR P was chosen.
            else if (choice == "POLYBIUS" || choice == "P") {
                char grid[6][6];
                bool isStr = false;
                bool keyCond = true;
                
                // Changing all alphabets into uppercase.
                for (int i = 0; i < original.length(); i++) {
                    original.at(i) = toupper(original.at(i));
                }
                
                // Checking if the string is only composed of alphabets, numbers, spaces.
                for (int i = 0; i < original.length(); i++) {
                    if ((isalpha(original.at(i)) || 
                         isdigit(original.at(i)) || isspace(original.at(i)))) {
                        isStr = true;
                    }
                    else {
                        isStr = false;
                        break;
                    }
                }
                
                if (isStr) {
                    cout << "What is your key: " << endl;
                    getline(cin, key_polybius);
                    
                    for (int i = 0; i < key_polybius.length(); i++) {
                        if (!isalpha(key_polybius.at(i)) && 
                            !isdigit(key_polybius.at(i))) {
                            // Set keyCond to false if any invalid character is found.
                            keyCond = false;
                            break;
                        }
                    }
                    
                    if (keyCond) {
                        // Changing all alphabets of the key to uppercase.
                        for (int i = 0; i < key_polybius.length(); i++) {
                            key_polybius.at(i) = toupper(key_polybius.at(i));
                        }
                        if (encDec == "ENCRYPT" || encDec == "E") {
                            cout << "The encrypted message is: ";
                            cout << polybiusSquare(grid, 
                                    key_polybius, original, 1) << endl;
                        }
                        else {
                            cout << "The decrypted message is: ";
                            cout << polybiusSquare(grid, 
                                    key_polybius, original, 0) << endl;
                        }
                    }
                    else {
                        cout << "Invalid key!" << endl;
                    }
                }
                else {
                    cout << "Invalid message!" << endl;
                }
            }
        }
        else {
            cout << "Invalid mode!" << endl;
        }
    }
    else {
        cout << "Invalid cipher!" << endl;
    }
}

