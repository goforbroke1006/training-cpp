//
// Created by goforbroke on 21.03.2022.
//

#include <gtest/gtest.h>

#include "solution.h"

void print_array(int *arr, int len);

void assert_array(int *arr1, int *arr2, int length);

void assert_array_sorted_asc(int *arr1, int length);

TEST(Swap_fn, Positive_StandardBehavior_1) {
    swap_calls = 0;
    const int length = 4;
    int *expected = new int[length]{1, 2, 3, 4};
    int *actual = new int[length]{1, 2, 4, 3};
    swap(actual[2], actual[3]);
    assert_array(expected, actual, length);
    ASSERT_EQ(1, swap_calls);
}

TEST(Swap_fn, Positive_StandardBehavior_2) {
    const int length = 4;
    int *expected = new int[length]{1, 2, 3, 4};
    int *actual = new int[length]{1, 2, 4, 3};
    swap(actual[3], actual[2]);
    assert_array(expected, actual, length);
}

TEST(Partition_fn, Positive_) {
    const int length = 10;

    int *target = new int[length]{3, 8, 4, 0, 7, 2, 6, 5, 1, 9};
    print_array(target, length);
    int actual_pi = partition(target, 0, length - 1);

    print_array(target, length);

    for (int i = 0; i < actual_pi; i++) {
        ASSERT_LT(target[i], target[actual_pi]);
    }
    for (int i = actual_pi + 1; i < length; i++) {
        ASSERT_GT(target[i], target[actual_pi]);
    }
}

TEST(QuickSort_fn, SortedArrayShouldNotBeModified) {
    const int length = 10;
    int *expected = new int[length]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *actual = new int[length]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    quick_sort(actual, 0, length - 1);
    assert_array(expected, actual, length);
}

TEST(QuickSort_fn, SingleElementArrayShouldNotBeModified) {
    swap_calls = 0;
    const int length = 1;

    int *actual = new int[length]{0};
    quick_sort(actual, 0, length - 1);
    //assert_array(expected, actual, length);
    ASSERT_EQ(0, swap_calls);
}

TEST(QuickSort_fn, PositiveMinimal) {
    swap_calls = 0;
    const int length = 2;

    int *actual = new int[length]{1, 0};
    quick_sort(actual, 0, length - 1);
    assert_array_sorted_asc(actual, length);
//    ASSERT_EQ(1, swap_calls);
}

TEST(QuickSort_fn, Positive) {
    const int length = 10;

    int *actual = new int[length]{3, 8, 4, 0, 7, 2, 6, 5, 1, 9};
    print_array(actual, length);
    quick_sort(actual, 0, length - 1);
    print_array(actual, length);
    assert_array_sorted_asc(actual, length);
}

void print_array(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void assert_array(int *arr1, int *arr2, int length) {
    for (int index = 0; index < length; ++index) {
        ASSERT_EQ(arr1[index], arr2[index]);
    }
}

void assert_array_sorted_asc(int *arr1, int length) {
    for (int index = 0; index <= length - 2; ++index) {
        ASSERT_LE(arr1[index], arr1[index + 1]);
    }
}
