//
// Created by goforbroke on 5/20/23.
//

#include <cstdio> // size_t
#include <ostream>
#include <iostream> // std::cin std:cout

#include "functions.h"

int main() {
    int arr[128];
    size_t arrSize;
    std::cout << "Size: ";
    std::cin >> arrSize;

    for (size_t idx = 0; idx < arrSize; ++idx) {
        std::cin >> arr[idx];
    }

    mergeSort(arr, 0, arrSize);

    printArray(arr, arrSize);
}

