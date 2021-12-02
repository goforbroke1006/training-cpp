//
// Created by goforbroke on 03.12.2021.
//

#ifndef LEARN_CPP_INVERTED_LIST_H
#define LEARN_CPP_INVERTED_LIST_H

#include "../mystd/List.h"

template<typename T>
class InvertedList : public mystd::List<T> {
public:
    void invert() {
        if (this->mHead == nullptr) { // empty list
            return;
        }

        mystd::Node<T> *prev = nullptr;
        mystd::Node<T> *current = this->mHead;

        while (true) {
            // remember next before erasing
            mystd::Node<T> *nextCurrent = current->getNext();

            // erase next, write prev as next
            current->setNext(prev);

            if (!nextCurrent) {
                break;
            }

            // shift
            prev = current;
            current = nextCurrent;
        }

        this->mHead = current;
    }
};

#endif //LEARN_CPP_INVERTED_LIST_H
