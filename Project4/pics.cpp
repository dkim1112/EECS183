/**
 * pics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * <Think of this class as the main palette.
 * The drawing for different shapes happens here, by loading
 * and writing on the files. We can also identify what the shape
 * of the drawing is.>
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character:
 *              1. clears drawer 
 *              2. prints "[Error in input file: " << character already read
 *                     "]" << endl;
 *              3. close file
 *              4. return
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded filename]"
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cin, cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

void coolPics()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
    
    return;
}

void writeFile(const Graphics& drawer)
{
    string fileName;
    cin >> fileName;
    fileName += ".bmp";

    drawer.writeFile(fileName);
    cout << "[Wrote " << fileName << "]" << endl;
}

void loadFile(Graphics& drawer)
{
    ifstream inFS;
    string file = openFile(inFS);

    // Cleaning up the canvas to start from blank.
    drawer.clear();
    char shape;
    
    // Using first character to determine what shape it is.
    while (inFS >> shape) {
        if (shape == 'L') {
            Line line;
            inFS >> line;
            line.draw(drawer);
        }
        else if (shape == 'C') {
            Circle circle;
            inFS >> circle;
            circle.draw(drawer);
        }
        else if (shape == 'T') {
            Triangle triangle;
            inFS >> triangle;
            triangle.draw(drawer);
        }
        else if (shape == 'R') {
            Rectangle rectangle;
            inFS >> rectangle;
            rectangle.draw(drawer);
        }
        else {
            drawer.clear();
            cout << "[Error in input file: " << shape << "]" << endl;
            inFS.close();
            return;
        }
    }

    inFS.close();
    cout << "[Loaded " << file << "]" << endl;
}

string tolower(string str)
{
    for (int i = 0; i < str.length(); i++) {
        str.at(i) = tolower(str.at(i));
    }

    return str;
}

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
