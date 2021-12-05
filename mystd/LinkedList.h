//
// Created by goforbroke on 05.12.2021.
//
// https://en.wikipedia.org/wiki/Linked_list#Doubly_linked_list

#ifndef LEARN_CPP_LINKED_LIST_H
#define LEARN_CPP_LINKED_LIST_H

namespace my_std {

    template<typename T>
    class LinkedList {
    protected:
        class Node {
        public:
            Node()
                    : mPrev(nullptr),
                      mNext(nullptr),
                      mValue(T{}) {}

            Node *getPrev() const {
                return mPrev;
            }

            void setPrev(Node *prev) {
                Node::mPrev = prev;
            }

            Node *getNext() const {
                return mNext;
            }

            void setNext(Node *next) {
                Node::mNext = next;
            }

            void setValue(T value) {
                Node::mValue = value;
            }

            T operator*() const {
                return this->mValue;
            }

        private:
            Node *mPrev;
            Node *mNext;
            T mValue;
        };

    public:
        LinkedList() :
                mHead(nullptr),
                mTail(nullptr),
                mSize(0) {}

        void push_back(T value) {
            Node *node = new Node();
            node->setValue(value);

            ++this->mSize;

            if (this->empty()) {
                this->mHead = node;
                this->mTail = node;
                return;
            }

            node->setPrev(this->mTail);
            this->mTail->setNext(node);
            this->mTail = node;
        }

        void push_front(T value) {
            Node *node = new Node();
            node->setValue(value);

            ++this->mSize;

            if (this->empty()) {
                this->mHead = node;
                this->mTail = node;
                return;
            }

            node->setNext(this->mHead);
            this->mHead->setPrev(node);
            this->mHead = node;
        }

        T pop_back() {
            if (this->empty()) {
                throw std::runtime_error("empty list");
            }
            if (this->one()) {
                T value = this->mTail->operator*();
                --this->mSize;
                delete this->mTail;
                this->mHead = nullptr;
                this->mTail = nullptr;
                return value;
            }

            T value = this->mTail->operator*();
            Node *prev = this->mTail->getPrev();
            delete this->mTail;
            if (nullptr != prev) {
                prev->setNext(nullptr);
                this->mTail = prev;
            }
            --this->mSize;

            return value;
        }

        T pop_front() {
            if (this->empty()) {
                throw std::runtime_error("empty list");
            }
            if (this->one()) {
                T value = this->mHead->operator*();
                --this->mSize;
                delete this->mHead;
                this->mHead = nullptr;
                this->mTail = nullptr;
                return value;
            }

            T value = this->mHead->operator*();
            Node *next = this->mHead->getNext();
            delete this->mHead;
            if (nullptr != next) {
                next->setPrev(nullptr);
                this->mHead = next;
            }
            --this->mSize;

            return value;
        }

        size_t size() const {
            return mSize;
        }

        bool empty() const {
            return nullptr == this->mHead && nullptr == this->mTail;
        }

        bool one() const {
            return nullptr != this->mHead && this->mHead == this->mTail;
        }

    protected:
        Node *mHead;
        Node *mTail;
        size_t mSize;

    public:
        class Iterator : std::iterator<std::input_iterator_tag, T, T, const T *, T> {
        public:
            explicit Iterator(Node *node) : mNode(node) {}

            bool operator==(Iterator other) {
                return this->mNode == other.mNode;
            }

            bool operator!=(Iterator other) {
                return this->mNode != other.mNode;
            }

            Iterator &operator++() {
                this->mNode = this->mNode->getNext();
                return *this;
            }

            Node operator*() const {
                return *this->mNode;
            }

        private:
            Node *mNode;
        };

        Iterator begin() const {
            return Iterator(this->mHead);
        }

        Iterator end() const {
            return Iterator(nullptr);
        }

    };

}

#endif //LEARN_CPP_LINKED_LIST_H
