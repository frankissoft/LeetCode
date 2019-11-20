#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max = 0;
    int i = 0;
    while (i < nums.size()) {
        std::cout << "i: " << i << std::endl;
        if (nums[0] == 0) {
            continue;
        } else {
            int j = i + 1;
            std::cout << "j: " << j << std::endl;
            while (j < nums.size() and nums[j]== 1) {
                j++;
                std::cout << "j: " << j << std::endl;
            }

            std::cout << "i: " << i << std::endl;
            std::cout << "j: " << j << std::endl;
            if (j >= nums.size()) {
                j--;
            }
            max = std::max(max, j - i);
            i += j;
            std::cout << "max: " << max << std::endl;
        }
    }
    return max;
}

int main() {
    std::vector<int> nums = {1, 1, 0, 1, 1, 1};
    std::cout << findMaxConsecutiveOnes(nums) << std::endl;
}
