#include <iostream>
#include <vector>
#include <set>

int singleNumber(std::vector<int>& nums) {
    std::vector<int>::iterator p;
    while (nums.size() >= 0) {
        int num = nums[0];
        // std::cout << "nums: " << nums << std::endl;
        p = std::find(nums.begin() + 1, nums.end(), num);
        if (p != nums.end()) {
            // std::cout << "erase-p: " << *p << std::endl;
            // std::cout << "begin: " << *nums.begin() << std::endl;
            // std::cout << "erase-begin: " << *(nums.begin()) << std::endl;
            nums.erase(p);
            p = std::find(nums.begin() + 1, nums.end(), num);
            // std::cout << "erase-p: " << *p << std::endl;
            nums.erase(p);
            nums.erase(nums.begin());
        }
        else {
            // std::cout << "*p: ";
            return num;
        }
    }
    return nums[0];
}

int main() {
    std::vector<int> nums = {2, 2, 1};
    std::vector<int> nums_ = {};
    std::vector<int> nums__ = {1, 1, 2, 2, 3, 3, 5, 5, 6, 6, 7, 7, 4};
    std::vector<int> nums___ = {0,1,0,1,0,1,99};
    std::vector<int> nums2 = {0,1,0,1,0,1,99, 99, 99, -1, 2, 3, 3, 3, 2, -1, -1, 10, 10, 10, 20, 2};
    std::vector<int> nums3 = {2, 2, 3, 2};
    std::cout << singleNumber(nums2) << std::endl;
    return 0;
}
