//
// Created by goforbroke on 21.03.2022.
//

#ifndef LEARN_CPP_SOLUTION_H
#define LEARN_CPP_SOLUTION_H

#include <iostream>

int swap_calls = 0;

void swap(int &el1, int &el2) {
    int tmp = el1;
    el1 = el2;
    el2 = tmp;

    ++swap_calls;
}

int partition(int *arr, int start, int end) {
    int pivot = arr[start];

    // Find good position for pivot
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }

        i++;
        j--;
    }

    return pivotIndex;
}

void quick_sort(int *arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
}

#endif //LEARN_CPP_SOLUTION_H
