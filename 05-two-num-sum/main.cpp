//
// Created by goforbroke on 26.09.22.
//

#include <iostream>
#include <vector>

std::vector<int> twoNumSum(const std::vector<int> &nums, int k) {
    std::size_t idxL = 0, idxR = nums.size();
    while (idxL < idxR) {
        if (nums[idxL] + nums[idxR] == k) {
            return {nums[idxL], nums[idxR]};
        }

        if (nums[idxL] + nums[idxR] < k) {
            idxL++;
        } else {
            idxR--;
        }
    }
    return {};
}

std::ostream &operator<<(std::ostream &ostream, const std::vector<int>& vec) {
    ostream << "[ ";
    for (const auto &v: vec) {
        ostream << v << " ";
    }
    ostream << "]";
    return ostream;
}

int main() {
    std::vector<int> sample = {1, 3, 5, 8, 9, 19};
    std::cout << twoNumSum(sample, 8);
    return 0;
}
