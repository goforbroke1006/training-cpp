//
// Created by goforbroke on 5/21/23.
//

#include "gtest/gtest.h"

#include "functions.h"

TEST(merge, Negative_singleElement) {
    int arr[1] = {123};
    merge(arr, 0, 1, 1);
    ASSERT_EQ(123, arr[0]);
}

TEST(merge, Positive_usualCaseAfterLastSplittingLen2_1) {
    int arr[2] = {1, 3};
    merge(arr, 0, 0, 1);
    ASSERT_EQ(1, arr[0]);
    ASSERT_EQ(3, arr[1]);
}

TEST(merge, Positive_usualCaseAfterLastSplittingLen2_2) {
    int arr[2] = {3, 1};
    merge(arr, 0, 0, 1);
    ASSERT_EQ(1, arr[0]);
    ASSERT_EQ(3, arr[1]);
}

TEST(merge, Positive_usualCaseFinal) {
    int arr[6] = {1, 3, 5, 2, 4, 6};
    merge(arr, 0, 2, 5); // 0 + (5 - 0) / 2;
    ASSERT_EQ(1, arr[0]);
    ASSERT_EQ(2, arr[1]);
    ASSERT_EQ(3, arr[2]);
    ASSERT_EQ(4, arr[3]);
    ASSERT_EQ(5, arr[4]);
    ASSERT_EQ(6, arr[5]);
}

TEST(mergeSort, Negative_singleElement) {
    int arr[1] = {234};
    mergeSort(arr, 0, 0);
    ASSERT_EQ(234, arr[0]);
}

TEST(mergeSort, Negative_sameElement) {
    int arr[4] = {7, 7, 7, 7};
    mergeSort(arr, 0, 3);
    ASSERT_EQ(7, arr[0]);
    ASSERT_EQ(7, arr[1]);
    ASSERT_EQ(7, arr[2]);
    ASSERT_EQ(7, arr[3]);
}

TEST(mergeSort, Negative_alreadSorted) {
    int arr[4] = {1, 2, 3, 4};
    mergeSort(arr, 0, 3);
    ASSERT_EQ(1, arr[0]);
    ASSERT_EQ(2, arr[1]);
    ASSERT_EQ(3, arr[2]);
    ASSERT_EQ(4, arr[3]);
}

TEST(mergeSort, Positive_usualCase) {
    int arr[5] = {9, 7, 5, 3, 0};
    mergeSort(arr, 0, 4);
    ASSERT_EQ(0, arr[0]);
    ASSERT_EQ(3, arr[1]);
    ASSERT_EQ(5, arr[2]);
    ASSERT_EQ(7, arr[3]);
    ASSERT_EQ(9, arr[4]);
}