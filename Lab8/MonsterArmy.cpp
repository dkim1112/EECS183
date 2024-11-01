/**
 * MonsterArmy.cpp
 *
 * <Dongeun Kim>
 * <dongeunk>
 *
 * EECS 183: Lab Exam 2 Review
 *
 * NOTE: You WILL submit this file to the autograder
 */

#include "Monster.h"
#include "MonsterArmy.h"
#include <iostream>
#include <string>
using namespace std;

MonsterArmy::MonsterArmy() {
    currentSize = 0;
}

bool MonsterArmy::spawnMonster(string type, int points) {
    bool modified = false;

    if (currentSize < MAX_ARMY_SIZE) {
        Monster mons;
        mons.setData(type, points);
        army[currentSize] = mons;
        currentSize++;
        modified = true;
    }

	return modified;
}

int MonsterArmy::pointsByType(string type) {
    int totalPoints = 0;

    for (int i = 0; i < currentSize; i++) {
        if (army[i].getType() == type) {
            totalPoints += army[i].getHitPoints();
        }
    }

    return totalPoints;
}

