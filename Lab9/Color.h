#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    /**
    * Requires: Nothing.
    * Modifies: Nothing.
    * Effects:  Default (empty) constructor. 
    */
    Color();
    
    /**
    * Requires: redVal, greenVal, blueVal all in range [0,255]
    * Modifies: red, green, blue.
    * Effects:  Constructor that sets RGB values.
    */
    Color(int redVal, int greenVal, int blueVal);
    
    /**
    * Requires: Nothing.
    * Modifies: Nothing.
    * Effects:  Returns true if and only if 
    *             red, green, and blue
    *             all have a value of 0.
    *           Returns false otherwise.
    */
    bool isBlack();
    
private:
    int red;
    int green;
    int blue;
};

#endif
