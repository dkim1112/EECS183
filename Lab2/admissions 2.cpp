/**
 * admissions.cpp
 *
 * Dongeun Kim
 * dongeunk
 * 9/6/24
 *
 * EECS 183: Lab 2
 *
 * After a brief exercise on printing "Hello World!", we moved on to calculating the chances of college admission based on the GPA, SAT, Dem_Interest, Curricum Strength a student has.
 */
 
#include <iostream>
using namespace std;

/* TODO: WHEN COMPLETING THE REFLCTION FORM!
 * change the values for these variables
 * NOTE: in order for the program to work the values must all add up to a
 * number <= 1, otherwise you will get values greater than 100
*/
const double GPA_WEIGHT = 0.4;
const double SAT_WEIGHT = 0.3;
const double DEM_INTREST_WEIGHT = 0.1;
const double CURRICULUM_STRENGTH_WEIGHT = 0.2;

int main() {
    // Task 1 Hello World
    // will be deleted by students when completing Task 2
    // cout << "Hello World!" << endl;


    // Task 2 College Admissions
    // TO-DO: Print "College Admissions Calculator"
    cout << "College Admissions Calculator" << endl;

  
    // TO-DO: Ask user to enter data. Store in variables named:
    // GPA, SAT, and DEM_INTEREST

    double GPA;
    double SAT; // SAT was made as a double b/c when divided by 160, decimal outputs should be considered for a full evaluation of admission chances. It should not round down to an integer.
    int demInt;
    int currStr;
    
    cout << "Please enter your GPA out of 5.0: " << endl;
    cin >> GPA;
    cout << "Please enter your SAT score out of 1600: " << endl;
    cin >> SAT;
    cout << "Please enter your demonstrated interest out of 10: " << endl;
    cin >> demInt;
    cout << "Please enter your high school curriculum strength out of 10: " << endl;
    cin >> currStr;

    /* Formula: gpa_weight * (GPA * 2)
                + sat_weight * (SAT / 160)
                + dem_interested_weight * DEM_INTEREST
                + curriculum_strength_weight * CURRICULUM_STRENGTH
    */
    
    // TO-DO: Create a variable score that equals the expected chance
    // of admission. Use the formula given in the comment above.
    double answer = GPA_WEIGHT * (GPA * 2) + SAT_WEIGHT * (SAT / 160) + (DEM_INTREST_WEIGHT * demInt) + (CURRICULUM_STRENGTH_WEIGHT * currStr); // multiplying the user inputted values with its weights accordingly.

    // TO-DO: Multiply the score by 10
    int final_answer = answer * 10; // multipled by 10 to make it out of 100 in terms of score representation.

    // TO-DO: Announce the score to the user
    cout << "Expected chance of admission: " << final_answer << "/100" << endl; // printing out the final output.

    return 0;
}
