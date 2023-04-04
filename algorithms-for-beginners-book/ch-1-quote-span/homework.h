//
// Created by gofor on 04.04.2023.
//

#ifndef CODEFORCES_TRAINING_HOMEWORK_H
#define CODEFORCES_TRAINING_HOMEWORK_H

const size_t STACK_ON_ARRAY_MAX_SIZE = 256;

template<typename T>
class StackOnArray {
public:
    explicit StackOnArray() : mLen(0) {}

    void push(T value) {
        this->mArray[this->mLen] = value;
        ++this->mLen;
    }

    void pop() {
        if (0 == this->mLen)
            throw std::logic_error("StackOnArray: pop on empty");

        --this->mLen;
    }

    T &top() { return this->mArray[this->mLen - 1]; }

    [[nodiscard]] bool empty() const { return 0 == this->mLen; }

    [[nodiscard]] size_t size() const { return this->mLen; }

private:
    T mArray[STACK_ON_ARRAY_MAX_SIZE];
    size_t mLen = 0;
};

#endif //CODEFORCES_TRAINING_HOMEWORK_H
