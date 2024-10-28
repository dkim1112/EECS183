/**
 * Graphics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * <This class is a representation of pixels in an image
 * that we treat it like a 2D-Array, and assign colors to each boxes.>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

#include "Graphics.h"
#include "bmp.h"

using namespace std;

// Initializing all the elements in the 2D-array pixelData to color black.
void Graphics::initArray() {
    Color black;

    // DIMENSION is a const declared in utility.h
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            pixelData[i][j] = black;
        }
    }
}

// Default constructor.
Graphics::Graphics() {
    initArray();
}

// Resetting the pixelData array through initArray method.
void Graphics::clear() {
    initArray();
}

// Setting a particular pixel to a certain color.
void Graphics::setPixel(int x, int y, Color col) {
    // Checking if the pixel selected is actually 
    // within the boundary of the pixelData 2D array.
    if ((x >= 0 && x < DIMENSION) && (y >= 0 && y < DIMENSION)) {
        pixelData[y][x] = col;
    }
}

void Graphics::writeFile(string fileName) const
{
    ofstream outFile;
    outFile.open(fileName, ios::binary);

    // determine padding
    int padding = (4 - (DIMENSION * 3) % 4) % 4;

    // BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    bf.bfType = 0x4d42; // type of file = bitmap
    bf.bfSize = DIMENSION * (DIMENSION + padding) * 3 + 54; // TODO
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = 54; // location of pixels

    // BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    bi.biSize = 40; // header size
    bi.biWidth = DIMENSION;
    bi.biHeight = -DIMENSION;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = 0;
    bi.biSizeImage = bi.biWidth * bi.biHeight * 3;
    bi.biXPelsPerMeter = 2834;
    bi.biYPelsPerMeter = 2834;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    // write output BITMAPFILEHEADER
    outFile.write((char*)&bf, sizeof(BITMAPFILEHEADER));

    // write output BITMAPINFOHEADER
    outFile.write((char*)&bi, sizeof(BITMAPINFOHEADER));

    // iterate over lines
    for (int i = 0; i < DIMENSION; i++)
    {
        // iterate over pixels in line
        for (int j = 0; j < DIMENSION; j++)
        {
            // temporary storage
            Color pixel = pixelData[i][j];

            // write RGB triple to outfile
            outFile << (BYTE) pixel.getBlue() << (BYTE) pixel.getGreen()
            << (BYTE) pixel.getRed();
        }

        // write padding to outfile
        for (int k = 0; k < padding; k++)
        {
            outFile << 0;
        }
    }

    // close file
    outFile.close();
}
