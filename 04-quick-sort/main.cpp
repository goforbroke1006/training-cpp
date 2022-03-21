//
// Created by goforbroke on 21.03.2022.
//

#include <iostream>

#include "solution.h"

int main() {
    std::cout << "Enter array length: ";
    int length;
    std::cin >> length;

    std::cout << "Enter array elements: ";
    int *arr = new int[length];
    for (int i = 0; i < length; ++i) {
        std::cin >> arr[i];
    }

    quick_sort(arr, 0, length - 1);

    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}