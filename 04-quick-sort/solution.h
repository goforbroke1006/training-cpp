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

int partition(int *arr, int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low;
    int j = high;
    while (true) {
        while (arr[i] < pivot) ++i;
        while (arr[j] > pivot) --j;
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
        ++i;
        --j;
    }
}

void quick_sort(int *arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi);
    quick_sort(arr, pi + 1, high);
}

#endif //LEARN_CPP_SOLUTION_H
