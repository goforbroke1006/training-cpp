//
// Created by goforbroke on 05.12.2021.
//

#ifndef LEARN_CPP_INVERTED_LINKED_LIST_H
#define LEARN_CPP_INVERTED_LINKED_LIST_H

#include "../mystd/LinkedList.h"

template<typename T>
class InvertedLinkedList : public my_std::LinkedList<T> {
public:
    void invert() {
        typename my_std::LinkedList<T>::Node *prev = nullptr;
        typename my_std::LinkedList<T>::Node *curr = this->mHead;
        typename my_std::LinkedList<T>::Node *next = nullptr;

        while (true) {
            // remember before erasing
            next = curr->getNext();

            curr->setNext(prev);
            curr->setPrev(next);

            if (nullptr == next) {
                return;
            }

            prev = curr;
            curr = next;
        }

        // TODO:
    }
};

#endif //LEARN_CPP_INVERTED_LINKED_LIST_H
