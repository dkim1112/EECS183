
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
 * <#description#>
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

void ciphers() {
    // TODO: implement
    string choice;
    string encDec;
    string original;
    string key;
    int keys;
    
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): " << endl;
    getline(cin, choice);
    choice = toUpperCase(choice);
    
    // If valid input for cipher choice.
    if(choice == "CAESAR" && choice == "C" && choice == "VIGENERE" && choice == "V" && choice == "POLYBIUS" && choice == "P") {
        
        cout << "Encrypt or decrypt: " << endl;
        getline(cin, encDec);
        encDec = toUpperCase(encDec);
        
        // If valid input for encrypt/decrypt
        if(encDec == "ENCRYPT" && encDec == "DECRYPT" && encDec == "E" && encDec == "D") {
            
            cout << "Enter a message: " << endl;
            getline(cin, original);
            
            if(choice == "CAESAR" || choice == "C"){
                cout << "What is your key: " << endl;
                cin >> keys;
                if(encDec == "ENCRYPT" || encDec == "E"){
                    cout << "The encrypted message is: ";
                    cout << caesarCipher(original, keys, 1);
                }
                else{
                    cout << "The decrypted message is: ";
                    cout << caesarCipher(original, keys, 0);
                }
            }
            
            else if(choice == "VIGENERE" || choice == "V"){
                cout << "What is your key: " << endl;
                getline(cin, key);
               
                if(encDec == "ENCRYPT" || encDec == "E"){
                    cout << "The encrypted message is: ";
                    cout << vigenereCipher(original, key, 1) << endl;
                }
                else{
                    cout << "The decrypted message is: ";
                    cout << vigenereCipher(original, key, 0) << endl;
                }
            }
//            else if(choice == "POLYBIUS" || choice == "P"){
//                bool isStr = true;
//                int i = 0;
//                while(i < original.size() && isStr == true){
//                    if((original.at(i) == 32)
//                       || (original.at(i) >= 48 && original.at(i) <= 57)
//                       ||(original.at(i) >= 65 && original.at(i) <= 90)
//                       || (original.at(i) >= 97 && original.at(i) <= 122)){
//                        isStr = true;
//                    }
//                    else{
//                        isStr = false;
//                    }
//                    i++;
//                }
//                for(int k = 0; k < original.size(); k++){
//                    original.at(k) = toupper(original[k]);
//                }
//                if(isStr){
//                    cout << "What is your key: " << endl;
//                    getline(cin, key);
//                    key = toUpperCase(key);
//
//                    if(encDec == "ENCRYPT" || encDec == "E"){
//                        cout << "The encrypted message is: ";
//                        cout << polybiusSquare(grid, key, original, 1) << endl;
//                    }
//                    else{
//                        cout << "The decrypted message is: ";
//                        cout << polybiusSquare(grid, key, original, 0) << endl;
//                    }
//                }
//                else{
//                    cout << "Invalid message!" << endl;
//                }
//            }
            else {
                cout << "Invalid command for encryption/decryption!" << endl;
            }
        }
    }
    else {
        cout << "Invalid cipher option!" << endl;
    }
}

