//
// Created by goforbroke on 25.11.2021.
//

#ifndef INVERT_LIST_LIST_H
#define INVERT_LIST_LIST_H

#include <iterator>

template<typename T>
class Node {
public:
    explicit Node(T value) : mValue(value) {}

    Node *getNext() const {
        return mNext;
    }

    void setNext(Node<T> *next) {
        Node::mNext = next;
    }

    T operator*() const {
        return mValue;
    }

private:
    T mValue;
    Node *mNext;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Node<T> node) {
    os << &node;
    return os;
}

template<typename T>
class List {
public:
    class ListIterator : std::iterator<
            std::input_iterator_tag, // iterator_category
            T,                       // value_type
            T,                       // difference_type
            const T *,               // pointer
            T> {
    public:
        explicit ListIterator(Node<T> *node) : node(node) {}

        bool operator!=(ListIterator other) { return this->node != other.node; }

        ListIterator &operator++() {
            this->node = this->node->getNext();
            return *this;
        }

        Node<T> operator*() const {
            return *this->node;
        }

    private:
        Node<T> *node;
    };

    explicit List() = default;

    void push(T value) {
        auto *node = new Node<T>(value);
        if (nullptr == this->mHead) {
            this->mHead = node;
        }
        if (nullptr != this->mTail) {
            this->mTail->setNext(node);
        }
        this->mTail = node;
    }

    ListIterator begin() { return ListIterator(this->mHead); }

    ListIterator end() { return ListIterator(nullptr); }

    void invert() {
        Node<T> *prev = nullptr;
        Node<T> *current = this->mHead;

        while (true) {
            Node<T> *nextCurrent = current->getNext(); // remember next before erasing
            current->setNext(prev);                    // erase next, write prev as next

            if (!nextCurrent) {
                break;
            }

            // shift
            prev = current;
            current = nextCurrent;
        }

        this->mHead = current;
    }

private:
    Node<T> *mHead;
    Node<T> *mTail;
};

#endif //INVERT_LIST_LIST_H
