//
// Created by goforbroke on 19.03.2022.
//

#include "domain.h"

template<typename T>
Node<T> *reverse(Node<T> *list) {
    // SOLUTION
    Node<T> *reversed = nullptr;
    for (Node<T> *node = list, *next = nullptr; nullptr != node; node = next) {
        next = node->next;
        node->next = reversed;
        reversed = node;
    }
    return reversed;
    // ~SOLUTION
}
