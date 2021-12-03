//
// Created by goforbroke on 25.11.2021.
//

#ifndef INVERT_LIST_LIST_H
#define INVERT_LIST_LIST_H

#include <iterator>

namespace mystd {

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
            } else {
                Node<T>* last = this->mHead;
                while (nullptr != last->getNext()) {
                    last = last->getNext();
                }
                last->setNext(node);
            }

            ++this->mSize;
        }

        T pop() {
            if (nullptr == this->mHead) {
                throw std::logic_error("empty list");
            }

            Node<T> *preLast = nullptr;
            Node<T> *last = this->mHead;
            while (nullptr != last->getNext()) {
                preLast = last;
                last = last->getNext();
            }

            --this->mSize;
            if (nullptr != preLast)
                preLast->setNext(nullptr);
            T value = last->operator*();
            delete last;
            return value;
        }

        ListIterator begin() const {
            return ListIterator(this->mHead);
        }

        ListIterator end() const { return ListIterator(nullptr); }

        size_t size() const {
            return mSize;
        }

    protected:
        Node<T> *mHead;
        Node<T> *mTail;
        size_t mSize;
    };

}

#endif //INVERT_LIST_LIST_H
