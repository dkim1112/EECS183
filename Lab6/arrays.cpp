/**
 * arrays.cpp
 *
 * EECS 183
 * Lab 6: Array exercises
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the assignment here#>
 */

#include "arrays.h"
#include <iostream>

using namespace std;

void print_array(const int array[], int size) {
    cout << "{" << array[0];
    for (int i = 1; i < size; i++) {
        cout << ", " << array[i];
    }
    cout << "}" << endl;
    return;
}

/** 
 * TODO
 * Implement all arrays.h functions:
 * negate_all, is_sorted, copy_positive_elements, sort_array
 */
