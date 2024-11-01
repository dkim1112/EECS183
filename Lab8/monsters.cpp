/**
 * monsters.cpp
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * EECS 183: Lab Exam 2 Practice
 *
 * Function to utilize your MonsterArmy.cpp implementations.
 * We have stubbed the required functions for you.
 *
 * NOTE: You WILL submit this file to the autograder
 */

#include "Monster.h"
#include "MonsterArmy.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Requires: size > 0
 * Modifies: army, ins, cout
 * Effects:  extracts type and points for each monster from the ins
 *           input stream. The number of monsters to enter is given by
 *           the size parameter.
 */
void buildArmy(MonsterArmy & army, int size, istream & ins) {
    cout << "Enter " << size << " monster types and hit points\n";
    cout << "Each on a new line\n";
    string type;
    int hitPoints = 0;
    int count = 0; 
    while (count < size && ins >> type >> hitPoints) {
        if (army.spawnMonster(type, hitPoints)) {
            count++;
        } else {
            return;
        }
    }
    return;
}

void monsters() {	
    int armySize = 5;
	
    cout << "Enter army size (>0): ";
	
    cin >> armySize;
	
    MonsterArmy army;
	
    buildArmy(army, armySize, cin);
	
    int totalHitPoints = army.pointsByType("demogorgon");
	
    cout << "Your army of darkness is " << totalHitPoints;
	
    cout << " demogorgon hit points strong!" << endl;	
    
    return;
}
