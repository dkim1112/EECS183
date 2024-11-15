#include "Color.h"

Color::Color() {
    return;
}

Color::Color(int redVal, int greenVal, int blueVal) {
    red = redVal;
    blue = blueVal;
    green = greenVal;
    return;
}

bool Color::isBlack() {
    bool val = (red == 0 && green == 0 && blue == 0);
    return val;
}



