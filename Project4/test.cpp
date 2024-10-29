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
    // Default constructor
    Circle p1;
    cout << "Expected: (0,0) 0 0 0 0, actual: " << p1 << endl;

    // Non-default constructor
    Point point1(30, 50);
    Color color1(235, 240, 120);
    Circle p2(point1, -25, color1);
    cout << p2;

    // test of setCenter(), setRadius(), setColor()
    Point point2(30, 30);
    Color color2(12, 12, 12);
    p1.setCenter(point2);
    p1.setRadius(-5);
    p1.setColor(color2);

    // test of the getCenter(), getRadius(), getColor()
    cout << p1.getCenter() << " " << p1.getRadius() << " " << p1.getColor() << endl;
}

void test_Color() {
    // Testing color constructors
    Color color;
    Color color2(255, 255, 255);

    // Testing the setter methods of different colors
    color.setRed(22);
    color.setGreen(23);
    color.setBlue(635);

    // Testing the getter methods of different colors
    cout << color.getRed() << color.getGreen() << color.getBlue() << endl;
    cin >> color;
    cout << color << endl;
}

void test_Line() {
cout << "Testing class Line()" << endl;
    // Default constructor
    Line p1;
    cout << "Expected: (0,0) (0,0) 0 0 0, actual: " << p1 << endl;

    // Non-default constructor
    Point point1(5, 5);
    Point point2(20, 20);
    Color color1(100, 200, 500);
    Line p2(point1, point2, color1);
    cout << p2;

    // testing setStart(), setEnd() and setColor()
    Point point3(75, 75);
    Point point4(99, 105);
    Color color2(100, 100, 100);
    p1.setStart(point3);
    p1.setEnd(point4);
    p1.setColor(color2);

    // testing getStart(), getEnd(), getColor()
    cout << p1.getStart() << " " << p1.getEnd() << " " << p1.getColor() << endl;
}

void test_Rectangle() {
 cout << "Testing class Rectangle()" << endl;
    // testing default constructor
    Rectangle p1;
    cout << "Expected: (0,0) (0,0) 0 0 0 0 0 0 0 0 0 0 0 0, actual: " << p1 << endl;

    // test of the non-default constructor
    Point point1(10, 30);
    Point point2(30, 40);
    Color color1(1, 2 ,3);
    Color color2(4, 5, 6);
    Color color3(7, 8, 9);
    Color color4(10, 11, 12);
    Rectangle p2(point1, point2, color1, color2, color3, color4);
    cout << "actual: " << p2 << endl;

    // test of all the set functions
    Point point3(90, 20);
    Point point4(45, 29);
    Color color5(12, 11, 10);
    Color color6(9, 8, 7);
    Color color7(6, 5, 4);
    Color color8(3, 2, 1);
    p1.setStart(point3);
    p1.setEnd(point4);
    p1.setColorTopLeft(color5);
    p1.setColorTopRight(color6);
    p1.setColorBottomRight(color7);
    p1.setColorBottomLeft(color8);

    // test of all the get functions
    cout << "actual: " << p1.getStart() << " " << p1.getEnd() << " " << p1.getColorTopLeft() << " " <<
        p1.getColorTopRight() << " " << p1.getColorBottomRight() << " " << p1.getColorBottomLeft() << endl;
}

void test_Triangle() {
    Triangle t1;
    cout << "Expected: (0,0) 0 0 0 (0,0) 0 0 0 (0,0) 0 0 0, actual: " << t1 << endl;

    // test of the non-default constructor
    Point v1(30, 45);
    Point v2(54, 65);
    Point v3(98, 80);
    Color color1(0, 0, 255);
    Color color2(0, 255, 0);
    Color color3(255, 0, 0);
    Triangle t2(v1, color1, v2, color2, v3, color3);
    cout << "actual: " << t2 << endl;

    t1.setVertexOne(v1);
    t1.setVertexTwo(v2);
    t1.setVertexThree(v3);
    t2.setVertexOneColor(color3);
    t1.setVertexTwoColor(color2);
    t2.setVertexThreeColor(color1);

    cout << t1.getVertexOne() << " " << t1.getVertexOneColor() << " "
        << t1.getVertexTwo() << " " << t1.getVertexTwoColor() << " "
        << t1.getVertexThree() << " " << t1.getVertexThreeColor() << endl;
}

