/**
 * lab4.cpp
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Lab 4
 *
 * Testing functions for your future Project 2 rps.cpp implementation.
 * Holds the definitions of required testing functions.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You will implement the following functions in rps.cpp for Project 2
//************************************************************************

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character:
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);

/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is empty, prints a message indicating the round
 *           is a draw. Otherwise, prints a congratulatory message to the
 *           winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_announceRoundWinner();

int main() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    test_announceRoundWinner();

    return 0;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * announceRoundWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "Valid Inputs: " << endl;
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl << endl;
    
    cout << "Invalid Inputs: " << endl;
    cout << "'1': Expected: 0, Actual: " << isMoveGood('1') << endl << endl;
    return;
}

void test_announceRoundWinner() {
    cout << "Now testing function announceRoundWinner()" << endl;
    cout << "Valid Inputs: " << endl;
    cout << "Expected: This round is a draw!, Actual: ";
    announceRoundWinner("");
    cout << "Expected: Daniel wins the round!, Actual: ";
    announceRoundWinner("Daniel");
    cout << endl;

    cout << "Invalid Inputs: " << endl;
    cout << "Anything can go in, as long it's a string type.";
    return;
}

// DO NOT ALTER THE CODE BELOW THIS LINE IN ANY WAY
// WRITE YOUR CODE IN THE FUNCTIONS ABOVE

#if defined(DEBUG) || defined(_DEBUG)
bool isMoveGood(char move) {
    
    // this (incorrect) implementation returns false to avoid compile error
    // you DO NOT need to implement this function as part of the lab
    // you will implement this function for Project 2 RPS
    return false;
}

void announceRoundWinner(string winnerName) {
    
    // you DO NOT need to implement this function as part of the lab
    // you will implement this function for Project 2 RPS
    return;
}
#endif


