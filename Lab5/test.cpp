/**
 * test.cpp
 *
 * EECS 183
 * Lab 5: loops exercises
 *
 * Dongeun Kim
 * dongeunk
 *
 * This serves as a place to test the functionality of each functions
 * that has been made in the loops.cpp file.
 */

// This allows us to access the functions we have made in the loops.cpp to test my code.
#include "loops.h"

#include <iostream>
using namespace std;

void testPrintRectangle();
void testPrintRight();
void testPrintRightJustified();
void testPrintIsosceles();

int main() {
    testPrintRectangle();
    testPrintRight();
    testPrintRightJustified();
    testPrintIsosceles();
    return 0;
}

void testPrintRectangle() {
    cout << "Testing printRectangle()" << endl;
    printRectangle(8, 8);
}

void testPrintRight() {
    cout << "Testing printRight()" << endl;
    printRight(3);
}

void testPrintRightJustified() {
    cout << "Testing printRightJustified()" << endl;
    printRightJustified(3);
}

void testPrintIsosceles() {
    cout << "Testing printIsosceles()" << endl;
    printIsosceles(3);
}



