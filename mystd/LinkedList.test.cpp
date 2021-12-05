//
// Created by goforbroke on 05.12.2021.
//

#include <gtest/gtest.h>

#include "LinkedList.h"
#include "Utils.h"

TEST(LinkedList_Size, Positive_Empty) {
    my_std::LinkedList<int> list{};
    ASSERT_EQ(0, list.size());
}

TEST(LinkedList_Size, Positive_AfterPush) {
    my_std::LinkedList<int> list{};
    list.push_back(100);
    list.push_back(200);

    ASSERT_EQ(2, list.size());
}

TEST(LinkedList_Size, Positive_AfterPushPop) {
    my_std::LinkedList<int> list{};
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    ASSERT_EQ(3, list.size());

    list.pop_back();
    ASSERT_EQ(2, list.size());

    list.pop_front();
    ASSERT_EQ(1, list.size());
}

TEST(LinkedList_Pop, Positive_PopFront_OnEmptyList) {
    my_std::LinkedList<char> list{};
    ASSERT_ANY_THROW(list.pop_front());
}

TEST(LinkedList_Pop, Negative_PopFront_OnNonEmptyList) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    ASSERT_NO_THROW(list.pop_front());
}

TEST(LinkedList_Pop, Positive_PopBack_OnEmptyList) {
    my_std::LinkedList<char> list{};
    ASSERT_ANY_THROW(list.pop_back());
}

TEST(LinkedList_Pop, Negative_PopBack_OnNonEmptyList) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    ASSERT_NO_THROW(list.pop_back());
}

TEST(LinkedList_PushBack, Positive_PushBack_Multiple) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');

    ASSERT_EQ("[a, b, c]", my_std::to_string(list));
}

TEST(LinkedList_Push_Pop, Positive_PushFront_Multiple) {
    my_std::LinkedList<char> list{};
    list.push_front('c');
    list.push_front('b');
    list.push_front('a');

    ASSERT_EQ("[a, b, c]", my_std::to_string(list));
}

TEST(LinkedList_Push_Pop, Positive_PushBack_PopBack_Regular) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('e');
    list.pop_back();
    list.pop_back();

    ASSERT_EQ("[a, b, c]", my_std::to_string(list));
}

TEST(LinkedList_Push_Pop, Positiv_PushBack_PopFronte_Regular) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('e');
    list.pop_front();
    list.pop_front();

    ASSERT_EQ("[c, d, e]", my_std::to_string(list));
}

TEST(LinkedList_Push_Pop, Positive_PushBack_PopBack_Devastate_Fill) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');

    ASSERT_EQ("[a, b, c]", my_std::to_string(list));
}

TEST(LinkedList_Push_Pop, Positive_PushBack_PopFront_Devastate_Fill) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');

    ASSERT_EQ("[a, b, c]", my_std::to_string(list));
}

TEST(LinkedList_Push_Pop, Positive_Devastate_Fill_AllMethodsUsage) {
    my_std::LinkedList<char> list{};
    list.push_back('a');
    list.pop_front();
    list.push_front('a');
    list.pop_back();

    ASSERT_EQ("[]", my_std::to_string(list));

    ASSERT_ANY_THROW(list.pop_front());
    ASSERT_ANY_THROW(list.pop_back());
}
