//
// Created by goforbroke on 02.04.2023.
//

#ifndef CODEFORCES_TRAINING_COMPLEXITY_H
#define CODEFORCES_TRAINING_COMPLEXITY_H

#include <iostream>
#include <string>
#include <ostream>
#include <map>

class ComplexityStat {
public:
    void init(uint64_t n) {
#ifdef DEBUG
        this->count = n;

        auto it = this->complexityTime.begin();
        while (!this->complexityTime.empty())
            it = this->complexityTime.erase(it);
#endif
    }

    void addTime(const std::string &label, int time = 1) {
#ifdef DEBUG
        if (this->complexityTime.find(label) == this->complexityTime.end()) {
            this->complexityTime[label] = time;
            return;
        }

        this->complexityTime[label] += time;
#endif
    }

    void print() {
#ifdef DEBUG
        for (const auto &p: this->complexityTime) {
            std::cout << p.first << " = " << p.second << std::endl;
        }
        std::cout << std::endl;
#endif
    }

    static ComplexityStat *get() {
        if (nullptr == ComplexityStat::instance) {
            ComplexityStat::instance = new ComplexityStat();
        }

        return ComplexityStat::instance;
    }

private:
    ComplexityStat() : count(0), complexityTime({}) {}

    uint64_t count;
    std::map<std::string, int> complexityTime;

    static ComplexityStat *instance;
};

ComplexityStat *ComplexityStat::instance = nullptr;

#endif //CODEFORCES_TRAINING_COMPLEXITY_H
