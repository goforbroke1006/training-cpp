//
// Created by goforbroke on 26.09.22.
//

#include <iostream>
#include <vector>

std::vector<int> twoNumNearestSum(const std::vector<int> &nums, int k) {
    std::size_t idxL = 0, idxR = nums.size();
    std::vector<int> tmpResult = {nums[idxL], nums[idxR]};

    while (idxL < idxR) {
        int sum = nums[idxL] + nums[idxR];

        if (abs(k - sum) < abs(tmpResult[0] + tmpResult[1] - sum)) {
            tmpResult = {nums[idxL], nums[idxR]};
        }

        if (nums[idxL] + nums[idxR] < k) {
            idxL++;
        } else {
            idxR--;
        }
    }

    return tmpResult;
}

std::ostream &operator<<(std::ostream &ostream, const std::vector<int> &vec) {
    ostream << "[ ";
    for (const auto &v: vec) {
        ostream << v << " ";
    }
    ostream << "]";
    return ostream;
}

int main() {
    std::vector<int> sample = {1, 3, 5, 8, 9, 19};
    std::cout << twoNumNearestSum(sample, 7);
    return 0;
}
