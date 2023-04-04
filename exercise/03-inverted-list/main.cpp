//
// Created by goforbroke on 16.03.2022.
//

#include <iostream>
#include <vector>

#include "domain.h"
#include "solution.h"

template<typename T>
void print(Node<T> *const list) {
    Node<T> *current = list;
    while (nullptr != current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T, typename ... Ts>
Node<T> *create_list(Ts ... args) {
    auto *list = new Node<T>();
    Node<T> *last = list;

    std::vector<T> vec = {args...};
    for (int i = 0; i < vec.size() - 1; ++i) {
        last->value = vec[i];
        last->next = new Node<T>();
        last = last->next;
    }

    last->value = vec[vec.size() - 1];

    return list;
}

template<typename T>
void delete_list(Node<T> *list) {
    Node<T> *curr = list, *next;
    while (nullptr != curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

int main() {
    auto *list = create_list<int>(0, 1, 2, 3, 4, 5, 6);

    print(list);
    auto *reversed = reverse(list);
    print(reversed);

    delete_list(reversed);

    return 0;
}
