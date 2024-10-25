/**
 * test.cpp
 *
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Lab 7
 * Taken from Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
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
    Point pt1;
    pt1.setX(15);
    cout << "Expected: (15,0), actual :" << pt1 << endl;
        
    ifstream input_file;
    input_file.open("data1.txt");
    pt1.read(input_file);
    cout << "Expected: (42,7), actual :" << pt1 << endl;
  
    return;
}
