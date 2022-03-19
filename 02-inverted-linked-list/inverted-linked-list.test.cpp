//
// Created by goforbroke on 05.12.2021.
//

#include <gtest/gtest.h>

#include "inverted-linked-list.h"
#include "../mystd/Utils.h"

TEST(InvertedLinkedList_Invert, Empty) {
    InvertedLinkedList<char> list{};

    ASSERT_EQ("[]", my_std::to_string(list));

    list.invert();
    ASSERT_EQ("[]", my_std::to_string(list));
}

TEST(InvertedLinkedList_Invert, Full) {
    InvertedLinkedList<char> list{};
    list.push_back('1');
    list.push_back('2');
    list.push_back('3');

    ASSERT_EQ("[1, 2, 3]", my_std::to_string(list));

    list.invert();
    ASSERT_EQ("[3, 2, 1]", my_std::to_string(list));
}

TEST(InvertedLinkedList_Invert, Full_Devastate_Full) {
    InvertedLinkedList<char> list{};
    list.push_back('1');
    list.push_back('2');
    list.push_back('3');
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.push_front('1');
    list.push_front('2');
    list.push_front('3');

    ASSERT_EQ("[3, 2, 1]", my_std::to_string(list));

    list.invert();
    ASSERT_EQ("[1, 2, 3]", my_std::to_string(list));
}

TEST(InvertedLinkedList_Invert, Triple) {
    InvertedLinkedList<char> list{};
    list.push_back('1');
    list.push_back('2');
    list.push_back('3');

    ASSERT_EQ("[1, 2, 3]", my_std::to_string(list));

    list.invert(); // 1-st
    ASSERT_EQ("[3, 2, 1]", my_std::to_string(list));

    list.invert(); // 2-nd
    ASSERT_EQ("[1, 2, 3]", my_std::to_string(list));

    list.invert(); // 3-rd
    ASSERT_EQ("[3, 2, 1]", my_std::to_string(list));
}
