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
        if (this->empty() || this->one()) {
            return;
        }

        typename my_std::LinkedList<T>::Node *prev = nullptr;
        typename my_std::LinkedList<T>::Node *curr = this->mHead;
        typename my_std::LinkedList<T>::Node *next = nullptr;
        typename my_std::LinkedList<T>::Node *tail = this->mHead;

        while (true) {
            // remember before erasing
            next = curr->getNext();

            curr->setNext(prev);
            curr->setPrev(next);

            if (nullptr == next) {
                break;
            }

            prev = curr;
            curr = next;
        }

        this->mTail = tail;
        this->mHead = curr;
    }
};

#endif //LEARN_CPP_INVERTED_LINKED_LIST_H
