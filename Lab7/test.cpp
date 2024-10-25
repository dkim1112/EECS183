/**
 * test.cpp
 *
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Lab 7
 * Taken from Project 4: CoolPics
 *
 * Dongeun Kim
 * dongeunk
 *
 * Testing out the functionality of the methods created in Point.cpp
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"

void test_Point();

void startTests() {
    test_Point();

    return;
}

void test_Point() {
    // Testing out the two constructors (default & overloaded)
    Point pt1;
    Point pt2(10, 10);
    
    // Testing out the setters for x and y.
    pt1.setX(15);
    cout << "Expected: (15,0), actual :" << pt1 << endl;
    
    pt1.setY(14);
    cout << "Expected: (15,14), actual: " << pt1 << endl;

    pt2.setX(13);
    cout << "Expected: (13,10), actual :" << pt2 << endl;

    pt2.setY(9);
    cout << "Expected: (13,9), actual :" << pt2 << endl;

    // Testing out the getters for x and y.
    cout << "Expected: 15, actual: " << pt1.getX() << endl;
    cout << "Expected: 14, actual: " << pt1.getY() << endl;
    cout << "Expected: 13, actual: " << pt2.getX() << endl;
    cout << "Expected: 9, actual: " << pt2.getY() << endl;

    // Testing out read.
    ifstream input_file;
    input_file.open("data1.txt");
    pt2.read(input_file);
    cout << "Expected: (15,14), actual :" << pt1 << endl;
    
    // Testing out write.
    ofstream output_file;
    output_file.open("data1.txt");
    pt2.write(output_file);
    cout << "Expected: (15,14), actual :" << pt1 << endl;
  
    return;
}
