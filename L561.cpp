#include <iostream>
#include <vector>

int arrayPairSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> pairs;
    int sum = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() / 2; i++) {
        sum += nums[2 * i];
        std::cout << "sum: " << sum << std::endl;
    }
    return sum;
}

int main() {
    std::vector<int> nums = {2, 3, 1, 4};
    std::cout << arrayPairSum(nums) << std::endl;
    return 0;
}
