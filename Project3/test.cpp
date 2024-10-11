/*
 * test.cpp
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * This is the test file to check if all the functions implemented work as expected.
 */

#include <stdio.h>
#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarcipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarcipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
    
    return;
}

// From here to the very bottom of the program,
// it is just testing out each of the methods written.
void testToUpperCase() {
    cout << "Testing ToUpperCase()" << endl;
    cout << "Expected: 'DANIEL KIM', Actual: " <<  toUpperCase("Daniel Kim") << endl;
    cout << "Expected: 'EECS183', Actual: " << toUpperCase("EECS183") << endl;
    cout << "Expected: 'WOW!', Actual: " << toUpperCase("Wow!") << endl;
    return;
}


void testRemoveNonAlphas() {
    cout << "Testing RemoveNonAlphas()" << endl;
    cout << "Expected: 'ABCDSEF', Actual: " << removeNonAlphas("123123123ABCDSEF")
    << endl;
    cout << "Expected: 'AbCdE', Actual: "
    << removeNonAlphas("AbC123d1E!!!!#.4 12345 3#3@!") << endl;
    return;
}


void testRemoveDuplicate() {
    cout << "Testing RemoveDuplicate()" << endl;
    cout << "Expected: 012DA, Actual: " << removeDuplicate("0012DDA")
    << endl;
    cout << "Expected: DANIEL, Actual: " << removeDuplicate("DDANIEL")
    << endl;
    return;
}


void testCharToInt() {
    cout << "Testing CharToInt()" << endl;
    cout << "Expected: '5', Actual: " << charToInt('5') << endl;
    return;
}


void testShiftAlphaCharacter() {
    cout << "Testing ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'u', Actual: " << shiftAlphaCharacter('s', 2) << endl;
    cout << "Expectd: 'h', Actual: " << shiftAlphaCharacter('y', 9) << endl;
    cout << "Expected: 'A', Actual: " << shiftAlphaCharacter('A', 0) << endl;
    cout << "Expected: 'S', Actual: " << shiftAlphaCharacter('T', 25) << endl;
    cout << "Expected: 'R', Actual: " << shiftAlphaCharacter('B', -10) << endl;
    cout << "Expected: 'a', Actual: " << shiftAlphaCharacter('c', -2) << endl;
    return;
}


void testCaesarcipher() {
    cout << endl <<"Testing Caesarcipher()" << endl;
   
    cout << "Expected: Cuuj cu qj jxu Tyqw qj 11 f.c., Actual: "
    << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    
    cout << "Expected: Meet me at the Diag at 11 p.m., Actual : "
    << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    return;
}


void testVigenereCipher() {
    cout << "Testing VigenereCipher()" << endl;
    cout << "Expected: U lgp'a os qaoxitk iaz ltvcfqq. Teoafoq ckwhtpd riady qh., Actual: "
    << vigenereCipher("I don't go looking for trouble. Trouble usually finds me."
                      , "Mischief managed.", true) << endl;
    
    cout << "Expected: I don't go looking for trouble. Trouble usually finds me., Actual: "
    << vigenereCipher("U lgp'a os qaoxitk iaz ltvcfqq. Teoafoq ckwhtpd riady qh.", "Mischief managed.", false)
    << endl;
    return;
}


void testFillGrid() {
    char grid[6][6];
    cout << "Testing FillGrid()" << endl;
    cout << "Expected:       0   1   2   3   4   5 \n "
                       "   --- --- --- --- --- --- \n"
                       "0 | P | O | L | Y | B | I |\n"
                       "   --- --- --- --- --- --- \n"
                       "1 | U | S | A | C | D | E |\n"
                       "   --- --- --- --- --- --- \n"
                       "2 | F | G | H | J | K | M |\n"
                       "   --- --- --- --- --- --- \n"
                       "3 | N | Q | R | T | V | W |\n"
                       "   --- --- --- --- --- --- \n"
                       "4 | X | Z | 0 | 1 | 2 | 3 |\n"
                       "   --- --- --- --- --- --- \n"
                       "5 | 4 | 5 | 6 | 7 | 8 | 9 |\n"
                       "   --- --- --- --- --- --- \n"
    ", Actual: ";
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << "0   1   2   3   4   5 \n "
    "   --- --- --- --- --- --- \n"
    "0 | P | O | L | Y | B | I |\n"
    "   --- --- --- --- --- --- \n"
    "1 | U | S | A | C | D | E |\n"
    "   --- --- --- --- --- --- \n"
    "2 | F | G | H | J | K | M |\n"
    "   --- --- --- --- --- --- \n"
    "3 | N | Q | R | T | V | W |\n"
    "   --- --- --- --- --- --- \n"
    "4 | X | Z | 0 | 1 | 2 | 3 |\n"
    "   --- --- --- --- --- --- \n"
    "5 | 4 | 5 | 6 | 7 | 8 | 9 |\n"
    "   --- --- --- --- --- --- \n";
    return;
}


void testMixKey() {
    cout << "Testing MixKey()" << endl;
    cout << "Expected: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789" << endl;
    cout << "Actual  : " << mixKey("POLYBIUS") << endl;
    return;
}


void testFindInGrid() {
    char grid[6][6];
    fillGrid(grid, ALNUM);
    cout << "Testing FindInGrid()" << endl;
    cout << "Expected: '00', Actual: " << findInGrid('P', grid) << endl;
    return;
}


void testPolybiusSquare() {
    char grid[6][6];
    fillGrid(grid, ALNUM);
    cout << "Testing PolybiusSquare()" << endl;
    cout << "Expected: 341503 1433100505153031310333 23200305 1503104043" << endl;
    cout << "Actual  : " << polybiusSquare(grid, "183ECS",
                                       "The grasshopper lies heavy", true) << endl;
    
    cout << "Expected: THE GRASSHOPPER LIES HEAVY" << endl;
    cout << "Actual  : " << polybiusSquare(grid, "183ECS",
                       "341503 1433100505153031310333 23200305 1503104043", false) << endl;
    return;
}
