//
// Created by goforbroke on 01.12.2021.
//

#include <gtest/gtest.h>

#include "list.h"

TEST(List_to_string, Positive) {
    {
        List<char> list{};
        ASSERT_EQ("", to_string(list));
    }
}

TEST(List_Size, Positive) {
    List<int> list{};
    ASSERT_EQ(0, list.size());
    list.invert();
    ASSERT_EQ(0, list.size());

    list.push(0);
    ASSERT_EQ(1, list.size());
}

TEST(List_Invert, Negative) {
    List<int> list{};
    ASSERT_EQ("", to_string(list));

    list.invert();
    ASSERT_EQ("", to_string(list));
}

TEST(List_Invert, Positive) {
    List<int> list{};
    list.push(1);
    list.push(2);
    list.push(3);
    ASSERT_EQ("1, 2, 3", to_string(list));

    list.invert();
    ASSERT_EQ("3, 2, 1", to_string(list));
}
