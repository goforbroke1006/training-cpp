//
// Created by goforbroke on 16.03.2022.
//

#include <iostream>

#include "domain.h"
#include "solution.h"

template<typename T>
void print(Node<T> *const list) {
    Node<T> *current = list;
    while (true) {
        std::cout << current->value << " ";
        current = current->next;

        if (nullptr == current) {
            break;
        }
    }
    std::cout << std::endl;
}

int main() {
    auto *list = new Node<int>(0);
    list->next = new Node<int>(1);
    list->next->next = new Node<int>(2);
    list->next->next->next = new Node<int>(3);
    list->next->next->next->next = new Node<int>(4);
    list->next->next->next->next->next = new Node<int>(5);
    list->next->next->next->next->next->next = new Node<int>(6);

    print(list);
    auto *rl = reverse(list);
    print(rl);

    return 0;
}
