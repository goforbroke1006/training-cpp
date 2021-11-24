#include <iostream>
#include "list.h"

int main() {
    List<int> ints{};
    ints.push(1);
    ints.push(2);
    ints.push(3);

    for (const auto it: ints) {
        std::cout << it << " = " << (*it) << std::endl;
    }

    ints.invert();
    std::cout << "inverted..." << std::endl;

    for (const auto it: ints) {
        std::cout << it << " = " << (*it) << std::endl;
    }

    return 0;
}
