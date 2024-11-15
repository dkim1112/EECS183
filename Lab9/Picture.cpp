#include "Picture.h"
#include "Color.h"
#include <iostream>
using namespace std;

Picture::Picture() {
    Color black(0, 0, 0);
    for (int row = 0; row < DIMENSION; row++) {
        for (int col = 0; col < DIMENSION; col++) {
            canvas[row][col] = black;
        }
    }
    return;
}

int Picture::countBlackPixels() {
    int count = 0;
    Color c;
    for (int row = 0; row < DIMENSION; row++) {
        for (int col = 0; col < DIMENSION; col++) {
            if (canvas[row][col].isBlack()) {
                count++;
            }
        }
    }
    return count;
}

void Picture::drawPixel(int row, int col, Color pixelColor) {
    if (row < 0 || row >= DIMENSION || col < 0 || col >= DIMENSION) {
        cout << "Out of bounds";
        return;
    }
    canvas[row][col] = pixelColor;
    return;
}

void Picture::drawRectangle(int startRow, int startCol,
                            int endRow, int endCol, Color pixelColor) {
    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            drawPixel(row, col, pixelColor);
        }
    }
    return;
}
Color Picture::getPixel(int row, int col) {
    return canvas[row][col];
}

void Picture::setCaption(string newCaption) {
    caption = newCaption;
    return;
}
 
string Picture::getCaption() {
    return caption;
}
