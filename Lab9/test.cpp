#include "Picture.h"
#include "Color.h"
#include <iostream>
#include <string>
using namespace std;

void startTests();
void testColorisBlack();
void testConstructorandCountBlackPixels();
void testdrawPixel();
void testdrawRectangle();

void startTests() {
    // all testing functions have been made for you
    testColorisBlack();
    testConstructorandCountBlackPixels();
    testdrawPixel();
    testdrawRectangle();

    return;
}

void testColorisBlack() {
    cout << "Testing Color::isBlack" << endl;
    
    // create a Color variable to test
    Color blue(0, 39, 76);
    Color black(0, 0, 0);
    
    // call the function being tested    
    cout << "Expected 0, actual " << blue.isBlack() << endl;
    cout << "Expected 1, actual " << black.isBlack() << endl;
    cout << endl;

    return;
}

void testConstructorandCountBlackPixels() {
    cout << "Testing Picture::Picture" << endl;

    // create a Picture variable to test
    Picture newPic;
    
    // call the function being tested, print the results of the test
    cout << "Expected 10000, actual " << newPic.countBlackPixels() << endl;
    
    cout << endl;
    
    return;
}

void testdrawPixel() {
    cout << "Testing Picture::drawPixel" << endl;
    
    // create a Picture variable to test
    Picture newPic;
    
    // create a row, col, and color for the argument to drawPixel
    int row = 5;
    int col = 10;
    Color blue(0, 39, 76);
    
    // call the function being tested
    newPic.drawPixel(row, col, blue);
    
    // print the results of the test
    // there should be one pixel that is not black    
    cout << "Expected 9999, actual " << newPic.countBlackPixels() << endl;
    
    // the pixel modified should be the same pixel    
    cout << "Expected 0, actual " 
        << newPic.getPixel(row, col).isBlack() << endl;
        
    // this should be "Out of bounds"
    cout << "Expected Out of bounds, actual ";
    newPic.drawPixel(DIMENSION, DIMENSION, blue);
        
    cout << endl << endl;

    return;
}

void testdrawRectangle() {
    cout << "Testing Picture::drawRectangle" << endl;
    
    // create a Picture variable to test
    Picture newPic;
    
    // create arguments to drawRectangle
    int rowStart = 5;
    int colStart = 10;
    int rowEnd = 19;    
    int colEnd = 19;
    Color maize(255, 203, 5);
    
    // call the function being tested
    newPic.drawRectangle(rowStart, colStart, rowEnd, colEnd, maize);
    
    // print the results of the test
    /* Note: this function is difficult to test!
       the rectangle should be 15 x 10 = 150 pixels that are not black
       but there is no single function to call to see if all of the correct
       pixels are modified
    */
    cout << "Expected 9850, actual " << newPic.countBlackPixels() << endl;
    
    // print the corners, they should not be black
    cout << "Expected 0, actual " 
        << newPic.getPixel(rowStart, colStart).isBlack() << endl;
    cout << "Expected 0, actual " 
        << newPic.getPixel(rowEnd, colEnd).isBlack() << endl;
    cout << "Expected 0, actual " 
        << newPic.getPixel(rowStart, colEnd).isBlack() << endl;
    cout << "Expected 0, actual " 
        << newPic.getPixel(rowEnd, colStart).isBlack() << endl;
        
    cout << endl;
    return;
}

