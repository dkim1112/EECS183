/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;

// Tested ones on Autograder.
void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Circle();
    test_Color();
    test_Line();
    test_Point();
    test_Rectangle();
    test_Triangle();    
    
    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);
    
    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    
    p1.read(cin);
    cout << p1 << endl;
}

void test_Circle() {
    Color color(0, 255, 0);
    Point center(4, 4);
    int r = 2;
    Circle c1;
    Circle (center, 5, color);
}

void test_Color() {
    Color color;
    Color color2(255, 255, 255);

    color.setRed(22);
    color.setGreen(23);
    color2.setBlue(55);

    cout << color.getRed() << color.getGreen() << color.getBlue() << endl;
    cin >> color;
    cout << color << endl;
}

void test_Line() {
    Color color(255, 0, 0);
    Point start(1, 2);
    Point end(3, 4);
    Line ln;
    Line ln1(start, end, color);

    Point newStart(5, 5);
    ln.setStart(newStart);
    ln.setEnd(newStart);
    ln.setColor(color);

    ln1.getStart();
    ln1.getEnd();
    ln1.getColor();    

    ln1.read(cin);
}

void test_Rectangle() {
    Point pt1;
    Point pt2(12, 10);
    Point pt3(24, 25);
    Color color1;
    Color color2(25, 25, 25);
    Color color3(1, 2, 3);
    Color color4(99, 23, 45);

    Rectangle rec;
    Rectangle rec1(pt1, pt2, color1, color2, color3, color4);

    rec.setStart(pt3);
    rec.setEnd(pt3);
    rec1.setColor(color2);
    rec1.setColor(color4);
    rec1.setColorTopLeft(color1);
    rec1.setColorTopRight(color2);
    rec1.setColorBottomRight(color3);
    rec1.setColorBottomLeft(color4);

    cout << rec1.getStart() << rec1.getEnd()
        << rec1.getColorTopLeft() << rec1.getColorBottomRight()
        << rec1.getColorBottomLeft() << rec1.getColorTopRight();
}

void test_Triangle() {
    Point v1(0, 1);
    Point v2(3, 9);
    Point v3(23, 1);
    Color color1(100, 100, 100);
    Color color2(255, 10, 255);
    Color color3(10, 10, 10);

    Triangle t1;
    Triangle t3(v1, color1, v2, color2, v3, color3);

    t1.setVertexOne(v1);
    t1.setVertexTwo(v2);
    t1.setVertexThree(v3);
    t3.setVertexOneColor(color3);
    t1.setVertexTwoColor(color2);
    t3.setVertexThreeColor(color1);

    cout << t1.getVertexOne() << " " << t1.getVertexOneColor() << " "
        << t1.getVertexTwo() << " " << t1.getVertexTwoColor() << " "
        << t1.getVertexThree() << " " << t1.getVertexThreeColor() << endl;

    t1.read(cin);
}

