#ifndef PICTURE_H
#define PICTURE_H

#include "Color.h"
#include <string>

using namespace std;

const int DIMENSION = 100;

class Picture {
public:

    /**
    * Requires: Nothing.
    * Modifies: canvas
    * Effects:  Default constructor.
    *           Sets all pixels to black, that is, Color(0, 0, 0)
    */
    Picture();

    /**
    * Requires: Nothing.
    * Modifies: Nothing.
    * Effects:  Counts the number of pixels in canvas
    *           that are black, i.e., Color(0, 0, 0)
    *
    * NOTE: Your solution *must* call Color::isBlack
    */
    int countBlackPixels();
    
    /**
    * Requires: Nothing.
    * Modifies: canvas, cout
    * Effects:  If row and col are within the bounds of array canvas,
    *           i.e., between 0 and DIMENSION - 1, inclusive, sets the
    *           element of canvas at [row][col] to pixelColor.
    *           Otherwise does not modify canvas and prints the
    *           message "Out of bounds"
    */
    void drawPixel(int row, int col, Color pixelColor);

    /**
    * Requires: {startRow, startCol, endRow, endCol}
    *           all between 0 to DIMENSION - 1, inclusive, i.e., they
    *           are all valid indices of canvas
    *           endRow >= startRow && endCol >= startCol
    * Modifies: canvas
    * Effects:  Draws a solid block of pixels pixelColor
    *           in a rectangle defined by the points [startRow][startCol]
    *           to [endRow][endCol] in canvas
    *
    * NOTE: Your solutiuon *must* call drawPixel
    */
    void drawRectangle(int startRow, int startCol,
                       int endRow, int endCol, Color pixelColor);
                       
    /**
    * Requires: {row, col}
    *           between 0 to DIMENSION - 1, inclusive, i.e., they
    *           are valid indices of canvas 
    * Modifies: Nothing.
    * Effects:  Returns pixel in canvas at row, col
    */
    Color getPixel(int row, int col);
                       
    /**
    * Requires: Nothing.
    * Modifies: caption
    * Effects:  Sets caption to newCaption
    */
    void setCaption(string newCaption);

    /**
    * Requires: Nothing.
    * Modifies: Nothing.
    * Effects:  Returns caption
    */
    string getCaption();
    
private:
    Color canvas[DIMENSION][DIMENSION];
    string caption;
};

#endif
