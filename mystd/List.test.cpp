//
// Created by goforbroke on 01.12.2021.
//

#include <gtest/gtest.h>

#include "List.h"

TEST(List_to_string, Positive_Empty) {
        mystd::List<char> list{};
        ASSERT_EQ("", to_string(list));
}

TEST(List_Push, Positive_Full) {
    mystd::List<char> list{};
        list.push('h');
        list.push('e');
        list.push('l');
        list.push('l');
        list.push('o');
        ASSERT_EQ("h, e, l, l, o", to_string(list));
}

TEST(List_Size, Positive_Empty) {
    mystd::List<int> list{};
    ASSERT_EQ(0, list.size());
}

TEST(List_Size, Positive_Full) {
    mystd::List<int> list{};
    list.push(0);
    ASSERT_EQ(1, list.size());
}

TEST(List_Pop, Positive_OneElement) {
    mystd::List<char> list{};
    list.push('a');
    ASSERT_EQ(1, list.size());
    ASSERT_EQ('a', list.pop());
    ASSERT_EQ(0, list.size());
}

TEST(List_Pop, Positive_MultipleElements) {
    mystd::List<char> list{};
    list.push('a');
    list.push('b');
    list.push('c');
    ASSERT_EQ(3, list.size());
    ASSERT_EQ('c', list.pop());
    ASSERT_EQ(2, list.size());
    ASSERT_EQ('b', list.pop());
    ASSERT_EQ(1, list.size());
    ASSERT_EQ('a', list.pop());
    ASSERT_EQ(0, list.size());
}