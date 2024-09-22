/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 2
 * Fall 2024
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();

//************************************************************************
// Testing additional function declarations, not for autograder.
//************************************************************************
void test_getName();
void test_getMenuChoice();
void test_getMove();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_doRound();
void test_announceWinner();

void startTests() {
    cout << "\nExecuting your test cases\n" << endl;

    // Graded ones for autograder.
    test_isMoveGood();
    test_isRoundWinner();
    test_announceRoundWinner();
    test_announceWinner();
    
    // ADDITIONAL TEST:
    test_getName();
    test_getMenuChoice();
    
    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

// Testing the functionality of isMoveGood method
void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "Valid Inputs: " << endl;
    // For boolean, true = 1 & false = 0.
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;
    cout << "'s': Expected: 1, Actual: " << isMoveGood('s') << endl;
    cout << "'R': Expected: 1, Actual: " << isMoveGood('R') << endl;
    cout << "'O': Expected: 1, Actual: " << isMoveGood('O') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl << endl;
    
    cout << "Invalid Inputs: " << endl;
    cout << "'1': Expected: 0, Actual: " << isMoveGood('1') << endl << endl;
    cout << "'.': Expected: 0, Actual: " << isMoveGood('.') << endl << endl;
    cout << "'!': Expected: 0, Actual: " << isMoveGood('!') << endl << endl;
    cout << "' ': Expected: 0, Actual: " << isMoveGood(' ') << endl << endl;
    cout << "'@': Expected: 0, Actual: " << isMoveGood('@') << endl << endl;

    return;
}

// Testing the functionality of isRoundWinner method
void test_isRoundWinner() {
    cout << "Now testing function isRoundWinner()" << endl;
    cout << "Valid Inputs: " << endl;
    cout << "Expected: 1, Actual: " << isRoundWinner('r', 's') << endl;
    cout << "Expected: 1, Actual: " << isRoundWinner('p', 'R') << endl;
    cout << "Expected: 1, Actual: " << isRoundWinner('S', 'p') << endl;
    cout << "Expected: 0, Actual: " << isRoundWinner('r', 'p') << endl << endl;
    
    cout << "Invalid Inputs: " << endl;
    cout << "Expected: 0, Actual: " << isRoundWinner('1', '2') << endl << endl;
    return;
}

// Testing the functionality of announceRoundWinner method
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

// Testing the functionality of announceWinner method
void test_announceWinner() {
    cout << "Now testing function announceWinner()" << endl;
    cout << "Valid Inputs: " << endl;
    cout << "Expected: No winner!, Actual: ";
    announceWinner("");
    cout << "Expected: Congratulations Daniel! You won EECS 183 Rock-Paper-Scissors!, Actual: ";
    announceWinner("Daniel");
    cout << endl;

    cout << "Invalid Inputs: " << endl;
    cout << "Anything can go in, as long it's a string type." << endl << endl;
    return;
}

// 2 methods below are ADDITIONAL.
void test_getName() {
    cout << "Now testing function getName()\n";
    cout << "Valid Inputs: " << endl;
    cout << getName(1) << endl;
    cout << getName(2) << endl << endl;

    cout << "Invalid Inputs: " << endl;
    cout << "An invalid input would be just pressing enter." << endl << endl;
    return;
}

void test_getMenuChoice() {
    cout << "Now testing function getMenuChoice()\n";
    cout << "Valid Inputs: " << endl;
    // good inputs would be 1, 2, or 3
    cout << getMenuChoice() << endl;
    cout << getMenuChoice() << endl;
    cout << getMenuChoice() << endl << endl;

    cout << "Invalid Inputs: " << endl;
    // invalid input would be other numbers, like 5 or -1
    cout << getMenuChoice() << endl;
    return;
}
