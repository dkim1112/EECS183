/**
 * arrays.cpp
 *
 * EECS 183
 * Lab 6: Array exercises
 *
 * Dongeun Kim
 * dongeunk
 *
 * It performs various functions on the 1D array,
 * such as negating all the values, checking if the 1D array is sorted,
 * copying positive elments, and even sorting them in numerical order.
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

void negate_all(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * -1;
    }
}

bool is_sorted(const int arr[], int size) {
    bool sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if ((arr[i] > arr [i + 1])) {
            sorted = false;
            break;
        }
    }
    return sorted;
}

void copy_positive_elements(const int source[], int target[], int size) {
    for (int i = 0; i < size; i++) {
        target[i] = 0;
    }

    // Copy the positive elements from source to adjacent locations in target
    int targetIndex = 0; // Tracks the current index in target for positive elements
    for (int i = 0; i < size; i++) {
        if (source[i] > 0) {
            target[targetIndex] = source[i];
            targetIndex++;
        }
    }
}

void sort_array(int arr[], int size) {
    bool condition = is_sorted(arr, size);
    int temp;

    while (!condition) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                condition = is_sorted(arr, size);
            }
        }
    }
}

