//
// Created by goforbroke on 19.03.2022.
//

#include "gtest/gtest.h"

#include "domain.h"
#include "solution.h"

TEST(List_Reverse, Negative_Empty) {
    Node<int> *list = nullptr;
    auto *reversed = reverse(list);
    ASSERT_EQ(list, reversed);
}

TEST(List_Reverse, Negative_SingleElement) {
    Node<int> *list = new Node<int>(0);
    auto *reversed = reverse(list);
    ASSERT_EQ(list, reversed);
}

TEST(List_Reverse, Positive_UsualList) {
    auto *list = new Node<int>(0);
    list->next = new Node<int>(1);
    list->next->next = new Node<int>(2);
    list->next->next->next = new Node<int>(3);
    list->next->next->next->next = new Node<int>(4);
    list->next->next->next->next->next = new Node<int>(5);
    list->next->next->next->next->next->next = new Node<int>(6);

    auto *expected = new Node<int>(6);
    expected->next = new Node<int>(5);
    expected->next->next = new Node<int>(4);
    expected->next->next->next = new Node<int>(3);
    expected->next->next->next->next = new Node<int>(2);
    expected->next->next->next->next->next = new Node<int>(1);
    expected->next->next->next->next->next->next = new Node<int>(0);

    auto *actual = reverse(list);
    ASSERT_EQ(expected->value, actual->value);
    ASSERT_EQ(expected->next->value, actual->next->value);
    ASSERT_EQ(expected->next->next->value, actual->next->next->value);
    ASSERT_EQ(expected->next->next->next->next->next->next->value, actual->next->next->next->next->next->next->value);
}