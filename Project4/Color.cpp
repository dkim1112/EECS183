/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * <This class is all about the colors (RGB). It can manipulate red, green,
 * and blue to our needs. It also checks if it is a valid color.>
 */

#include "Color.h"

// Checking if the color (RGB) is in the valid range.
// If not, either assign 0 or 255 depending on where
// the number is closer to.
int Color::checkRange(int val) {
    if ((val >= 0) && (val <= 255)) {
        return val;
    }
    else if (val < 0){
        return 0;
    }
    else {
        return 255;
    }
}

// Default constructor, initializing red, green, blue to 0's.
Color::Color() {
   red = 0;
   green = 0;
   blue = 0;
}

// Overloaded constructor.
Color::Color(int rV, int gV, int bV) {
   red = checkRange(rV);
   green = checkRange(gV);
   blue = checkRange(bV);
}

// Setting color to a different red.
void Color::setRed(int rV) {
   red = checkRange(rV);
}

// Printing out red.
int Color::getRed() {
   return red;
}

// Setting color to a different green.
void Color::setGreen(int gV) {
   green = checkRange(gV);
}

// Printing out green.
int Color::getGreen() {
   return green;
}

// Setting color to a different blue.
void Color::setBlue(int bV) {
   blue = checkRange(bV);
}

// Printing out blue.
int Color::getBlue() {
   return blue;
}

// Reading in the 3 different colors for file.
void Color::read(istream& ins) {
   int redRed, blueBlue, greenGreen;
    
   // >> automatically ignores spaces (" ")
   ins >> redRed >> greenGreen >> blueBlue;

   // Using setter, giving each red, green, and blue certain values.
   setRed(redRed);
   setGreen(greenGreen);
   setBlue(blueBlue);
}

// Printing the output in red green blue format.
void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue;
}

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
