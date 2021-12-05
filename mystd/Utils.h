//
// Created by goforbroke on 03.12.2021.
//

#ifndef LEARN_CPP_UTILS_H
#define LEARN_CPP_UTILS_H

#include <string>
#include <sstream>

#include "List.h"
#include "LinkedList.h"

namespace my_std {

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

    template<typename T>
    std::string to_string(const LinkedList<T> &list) {
        static std::string delimiter = ", ";

        std::ostringstream ss;
        for (const auto it: list) {
            ss << (*it) << delimiter;
        }
        std::string res = ss.str();
        if (list.size() > 0) {
            res = res.substr(0, res.length() - delimiter.length());
        }
        return "[" + res + "]";
    }

}

#endif //LEARN_CPP_UTILS_H
