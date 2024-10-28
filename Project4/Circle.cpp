/**
 * Circle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * <This class is all about the shape circle. It performs operations such as
 * setting the color of the circle, getting the center value, and more. It
 * can ultimately draw circles.>
 */

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;

// Default constructor for Circle class, not receiving any parameters.
Circle::Circle() {
}

// Overloaded constructor.
Circle::Circle(Point pt, int r, Color c) {
    center = pt;
    radius = checkRadius(r);
    color = c;
}

// A type of a setter function, receiving an input through parameter and
// giving a new value to the variable center.
// For the remainder of this program, same applies for setter.
void Circle::setCenter(Point pt) {
    center = pt;
}

// A type of a getter function, simply returning an output
// that is requested, also by ensuring the return type matches
// with the variable. For the remainder of this program,
// same applies for getter.
Point Circle::getCenter() {
    return center;
}

// Setting radius to a new value r.
void Circle::setRadius(int r) {
    radius = checkRadius(r);
}

// Returning the value of the radius.
int Circle::getRadius() {
    return radius;
}

// Setting color to a new color c.
void Circle::setColor(Color c) {
    color = c;
}

// Returning what color the circle is.
Color Circle::getColor() {
    return color;
}

// Reading in the file.
void Circle::read(istream& ins) {
    ins >> center >> radius >> color;
    radius = checkRadius(radius);
}

// Printing out the values in a form of center radius color.
void Circle::write(ostream& outs) {
    outs << center << " " << radius << " " << color;
}

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();

    while (x >= y)
    {
        plot8points(x, y, c, drawer);

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();

    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);

    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
