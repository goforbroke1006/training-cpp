//
// Created by goforbroke on 5/21/23.
//

#ifndef LEARN_CPP_SORTING_MERGE_FUNCTIONS_H
#define LEARN_CPP_SORTING_MERGE_FUNCTIONS_H

void mergeSort(int arr[], size_t left, size_t right);

void merge(int arr[], size_t left, size_t middle, size_t right);

void printArray(int arr[], size_t size);

void mergeSort(int arr[], size_t left, size_t right) {
    if (left >= right) { // no enough length to split array again
        return;
    }

    size_t middle = left + (right - left) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
}

void merge(int arr[], size_t left, size_t middle, size_t right) {
    size_t len1 = middle - left + 1;
    size_t len2 = right - middle;

    int part1[len1];
    int part2[len2];

    for (size_t i = left; i <= middle; ++i) part1[i - left] = arr[i];
    for (size_t i = middle + 1; i <= right; ++i) part2[i - middle - 1] = arr[i];

    size_t cur1 = 0, cur2 = 0, nextIndex = left;

    // take smallest element from heads of two parts
    while (cur1 < len1 && cur2 < len2) {
        if (part1[cur1] < part2[cur2]) {
            arr[nextIndex] = part1[cur1];
            ++cur1;
        } else {
            arr[nextIndex] = part2[cur2];
            ++cur2;
        }
        ++nextIndex;
    }

    // move rest
    while (cur1 < len1) {
        arr[nextIndex] = part1[cur1];
        ++cur1;
        ++nextIndex;
    }
    while (cur2 < len2) {
        arr[nextIndex] = part2[cur2];
        ++cur2;
        ++nextIndex;
    }
}

// Print the array
void printArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


#endif //LEARN_CPP_SORTING_MERGE_FUNCTIONS_H
