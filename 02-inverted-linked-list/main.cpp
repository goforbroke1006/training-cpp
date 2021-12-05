//
// Created by goforbroke on 05.12.2021.
//

#include <iostream>

#include "../mystd/LinkedList.h"
#include "../mystd/Utils.h"

int main() {
//    {
//        my_std::LinkedList<char> list{};
//        list.push_back('H');
//        list.push_back('e');
//        list.push_back('l');
//        list.push_back('l');
//        list.push_back('o');
//        list.push_back('!');
//
//        std::cout << "Linked list:" << std::endl;
//        std::cout << "  " << my_std::to_string(list) << std::endl;
//    }

    {
        my_std::LinkedList<char> list{};
        list.push_back('a');
        list.push_back('b');
        list.push_back('c');
        list.push_back('d');
        list.push_back('e');
        list.pop_front();
        list.pop_front();

        std::cout << "Linked list:" << std::endl;
        std::cout << "  " << my_std::to_string(list) << std::endl;
    }

    return 0;
}
