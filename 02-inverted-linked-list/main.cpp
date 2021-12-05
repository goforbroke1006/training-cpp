//
// Created by goforbroke on 05.12.2021.
//

#include <iostream>

#include "inverted-linked-list.h"
#include "../mystd/Utils.h"

int main() {
    InvertedLinkedList<char> list{};
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('e');

    std::cout << "Linked list:" << std::endl;
    std::cout << "  " << my_std::to_string(list) << std::endl;

    list.invert();
    std::cout << "inverting..." << std::endl;

    std::cout << "Linked list:" << std::endl;
    std::cout << "  " << my_std::to_string(list) << std::endl;


    return 0;
}
