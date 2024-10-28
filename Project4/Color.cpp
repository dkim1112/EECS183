/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Color.h"

// TODO: implement first checkRange, then two constructors, setRed, getRed,
//       setGreen, getGreen, setBlue, getBlue, read, write.
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

Color::Color() {
   red = 0;
   green = 0;
   blue = 0;
}

Color::Color(int rV, int gV, int bV) {
   red = checkRange(rV);
   green = checkRange(gV);
   blue = checkRange(bV);
}

void Color::setRed(int rV) {
   red = checkRange(rV);
}

int Color::getRed() {
   return red;
}

void Color::setGreen(int gV) {
   green = checkRange(gV);
}

int Color::getGreen() {
   return green;
}

void Color::setBlue(int bV) {
   blue = checkRange(bV);
}

int Color::getBlue() {
   return blue;
}

void Color::read(istream& ins) {
    int red, blue, green;
    
    // >> automatically ignores spaces " "
    ins >> red >> green >> blue;
    red = checkRange(red);
    green = checkRange(green);
    blue = checkRange(blue);
}

void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue;
}

// Don't change the implementations below!

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
