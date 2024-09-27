/**
 * loops.cpp
 *
 * EECS 183
 * Lab 5: Loops exercises
 *
 * Dongeun Kim
 * dongeunk
 *
 * Utilizing for-loops, we are trying to print various shapes of triangles 
 * based on the values inputted by the users.
 */

#include "loops.h"
#include <iostream>

using namespace std;

void printRectangle(int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

void printRight(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=i; j>0; j--) {
            cout << "*";
        }
        cout << endl;
    }
}

void printRightJustified(int n) {
    for (int i=1; i<=n; i++) {
        int white = n-i;
        for (int j=0; j<white; j++) {
            cout << " ";
        }
        for (int k=0; k<i; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printIsosceles(int n) {
    int e = 1;
    for (int i=1; i<=n; i++) {
        for (int j=n-1; j>=i; j--) {
            cout << " ";
        }
        for (int c=0; c<e; c++) {
            cout << "*";
        }
        cout << endl;
        e+=2;
    }
}


