//
// Created by goforbroke on 25.11.2021.
//

#ifndef INVERT_LIST_LIST_H
#define INVERT_LIST_LIST_H

#include <iterator>
#include <sstream>

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

        bool operator==(ListIterator other) {
            return this->node == other.node;
        }

        bool operator!=(ListIterator other) {
            return this->node != other.node;
        }

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

    explicit List() : mHead(nullptr), mTail(nullptr), mSize(0) {}

    void push(T value) {
        auto *node = new Node<T>(value);
        if (nullptr == this->mHead) {
            this->mHead = node;
        }
        if (nullptr != this->mTail) {
            this->mTail->setNext(node);
        }
        this->mTail = node;

        ++this->mSize;
    }

    ListIterator begin() const {
        return ListIterator(this->mHead);
    }

    ListIterator end() const { return ListIterator(nullptr); }

    size_t size() const {
        return mSize;
    }

    void invert() {
        if (this->mHead == nullptr) { // empty list
            return;
        }

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
    size_t mSize;
};

template<typename T>
std::string to_string(const List<T> &list) {
    static std::string delimiter = ", ";

    std::ostringstream ss;
    for (const auto it: list) {
        ss << (*it) << delimiter;
    }
    std::string res = ss.str();
    if (list.size() > 0) {
        res = res.substr(0, res.length() - delimiter.length());
    }
    return res;
}

#endif //INVERT_LIST_LIST_H
