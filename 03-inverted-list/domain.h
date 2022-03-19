//
// Created by goforbroke on 16.03.2022.
//

#ifndef LEARN_CPP_DOMAIN_H
#define LEARN_CPP_DOMAIN_H

template<typename T>
struct Node {
    struct Node *next;
    T value;

    explicit Node() = default;

    explicit Node(T value) : value(value) {}
};

template<typename T>
Node<T> *reverse(Node<T> *list);

#endif //LEARN_CPP_DOMAIN_H
