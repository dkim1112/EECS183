/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * <This class is all about the shape rectangle. It performs operations 
 * such as setting the color of the rectangle, getting the start and 
 * end value, and more.>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// Default constructor.
Rectangle::Rectangle() {
}

// Overloaded constructor.
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, 
                    Color cTopRight, Color cBottomRight, 
                    Color cBottomLeft) {
    start = pt1;
    end = pt2;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
}

// Setting the starting point of the rectangle.
void Rectangle::setStart(Point pt) {
    start = pt;
}

// Getting start value.
Point Rectangle::getStart() {
    return start;
}

// Setting the ending point of the rectangle.
void Rectangle::setEnd(Point pt) {
    end = pt;
}

// Getting end value.
Point Rectangle::getEnd() {
    return end;
}

// Setting the color of the rectangle.
void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

// Setting the top left color of the rectangle.
void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

// Getting top left color value.
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

// Setting the top right color of the rectangle.
void Rectangle::setColorTopRight(Color color) {
    colorTopRight= color;
}

// Getting top right color value.
Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

// Setting the bottom right color of the rectangle.
void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

// Getting bottom right color value.
Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

// Setting the bottom left color of the rectangle.
void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
}

// Getting bottom left color value.
Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

// Reading in the file in a certain order written below.
void Rectangle::read(istream& ins) {
    ins >> start >> end >> colorTopLeft >> colorTopRight
        >> colorBottomRight >> colorBottomLeft;
    
    if (ins.fail()) {
        ins.clear();
        colorTopRight = colorTopLeft;
        colorBottomRight = colorTopLeft;
        colorBottomLeft = colorTopLeft;
    }
}

// Printing out all the values.
void Rectangle::write(ostream& outs) {
    outs << " " << start << " " << end << " " 
    << colorTopLeft << " " << colorTopRight 
    << " " << colorBottomRight << " " << colorBottomLeft;
}

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
