/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * <This class is a representation of a single coordinate on the image.
 * It holds values such as the x and y coordinates.>
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
}

int Point::getX() {
    return x;
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getY() {
    return y;
}

// otherwise returns the closest of 0 OR DIMENSION - 1.
int Point::checkRange(int val) {
    if ((val >= 0) && (val < DIMENSION)) {
        return val;
    }
    else if (val < 0){
        return 0;
    }
    else {
        return DIMENSION - 1;
    }
}

void Point::read(istream& ins) {
    char leftParen, comma, rightParen;
    int xVal, yVal;
    
    ins >> leftParen >> xVal >> comma >> yVal >> rightParen;
    
    // If input fails, set point to origin (0,0)
    if (ins.fail()) {
        x = 0;
        y = 0;
        return;
    }
    
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::write(ostream& outs) {
    outs << '(' << x << ',' << y << ')';
}

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
