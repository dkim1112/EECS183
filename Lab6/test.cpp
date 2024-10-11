/**
 * test.cpp
 *
 * EECS 183
 * Lab 6: Array exercises
 *
 * Dongeun Kim
 * dongeunk
 *
 * This file serves as a purpose to check if the functions created in arrays.cpp function as expected.
 */

#include "arrays.h"

#include <iostream>
using namespace std;

void test_negate_all();
void test_is_sorted();
void test_copy_positive_elements();
void test_sort_array();

int main() {
    test_negate_all();
    test_is_sorted();
    test_copy_positive_elements();
    test_sort_array();
    return 0;
}

void test_negate_all() {
    int arr[5] = {1,2,3,-4,5};
    cout << "Testing negate_all()" << endl;
    negate_all(arr, 5);
        
}

void test_is_sorted() {
    int arr[5] = {1,2,3,-4,5};
    cout << "Testing is_sorted()" << endl;
    cout << is_sorted(arr, 5);
}

void test_copy_positive_elements() {
    int arr[5] = {1,2,3,-4,5};
    int target[5] = {0, 0, 0, 0, 0};
    cout << "Testing copy_positive_elements()" << endl;
    copy_positive_elements(arr, target, 5);
    
}

void test_sort_array() {
    int arr[5] = {1,2,3,-4,5};
    cout << "Testing sort_array()" << endl;
    sort_array(arr, 5);
}


