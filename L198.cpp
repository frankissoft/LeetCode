#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

void permuteHelper(int length, std::vector<int> chosen, std::vector<std::vector<int>>& alreadyPrinted) {
    std::cout << "(permuteHelper: " << length << ", " << chosen << ")" << std::endl;
    std::vector<int> tmp = chosen;
    if (length == 0) {
        alreadyPrinted.push_back(chosen);
    } else if (chosen.size() == 0) {
        tmp.push_back(0);
        permuteHelper(length - 1, tmp, alreadyPrinted);
        tmp = chosen;
        tmp.push_back(1);
        permuteHelper(length - 1, tmp, alreadyPrinted);
    } else {
        if (chosen[chosen.size() - 1] == 1) {
            tmp = chosen;
            tmp.push_back(0);
            permuteHelper(length - 1, tmp, alreadyPrinted);
        } else {
            tmp = chosen;
            tmp.push_back(0);
            permuteHelper(length - 1, tmp, alreadyPrinted);
            tmp = chosen;
            tmp.push_back(1);
            permuteHelper(length - 1, tmp, alreadyPrinted);
        }
    }
}

int rob(std::vector<int>& nums) {
    std::vector<std::vector<int>> alreadyPrinted;
    std::vector<int> sums;
    int size = nums.size();
    permuteHelper(size, {}, alreadyPrinted);
    int sum = 0;
    for (int i = 0; i < alreadyPrinted.size(); i++) {
        sum = 0;
        for (int j = 0; j < size; j++) {
            sum += alreadyPrinted[i][j] * nums[j];
        }
        sums.push_back(sum);
    }
    std::cout << alreadyPrinted << std::endl;
    return *std::max_element(sums.begin(), sums.end());
}

int main() {
    std::vector<int> nums = {2,7,9,3,1};
    std::cout << rob(nums) << std::endl;
    return 0;
}
