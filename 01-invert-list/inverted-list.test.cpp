//
// Created by goforbroke on 03.12.2021.
//

#include <gtest/gtest.h>

#include "inverted-list.h"
#include "../mystd/Utils.h"

TEST(List_Invert, Negative) {
    InvertedList<int> list{};
    ASSERT_EQ("", mystd::to_string(list));

    list.invert();
    ASSERT_EQ("", mystd::to_string(list));
}

TEST(List_Invert, Positive) {
    InvertedList<int> list{};
    list.push(1);
    list.push(2);
    list.push(3);
    ASSERT_EQ("1, 2, 3", mystd::to_string(list));

    list.invert();
    ASSERT_EQ("3, 2, 1", mystd::to_string(list));
}