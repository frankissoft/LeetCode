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

// std::vector<int> singleNumber(std::vector<int>& nums) {
//     while (nums.size() >= 0) {
//         // std::cout << "nums: " << nums << std::endl;
//         std::vector<int>::iterator p = std::find(nums.begin() + 1, nums.end(), nums[0]);
//         if (p != nums.end()) {
//             // std::cout << "*p: " << *p << std::endl;
//             // std::cout << "begin: " << *nums.begin() << std::endl;
//             nums.erase(p);
//             nums.erase(nums.begin());
//         }
//         else {
//             // std::cout << "*p: ";
//             return nums[0];
//         }
//     }
//     return nums[0];
// }

std::vector<int> result;
std::vector<int> singleNumber(std::vector<int>& nums) {
    while (nums.size() > 0) {
        std::cout << "nums: " << nums << std::endl;
        std::vector<int>::iterator p = std::find(nums.begin() + 1, nums.end(), nums[0]);
        if (p != nums.end()) {
            std::cout << "erase: " << *p << std::endl;
            std::cout << "erase_begin: " << *nums.begin() << std::endl;
            nums.erase(p);
            nums.erase(nums.begin());
        }
        else {
            // std::cout << "*p: ";
            result.push_back(nums[0]);
            std::cout << "push_back: " << nums[0] << std::endl;
            nums.erase(nums.begin());
            std::cout << "erase: " << *(nums.begin()) << std::endl;
        }
        std::cout << "result: " << result << std::endl;
    }
    // result.push_back(nums[0]);
    return result;
}



int main() {
    std::vector<int> nums = {2, 2, 1, 3};
    std::vector<int> nums4 = {1,2,1,3,2,5};
    std::vector<int> nums_ = {};
    std::vector<int> nums__ = {1, 1, 2, 2, 3, 3, 5, 5, 6, 6, 7, 7, 4};
    std::vector<int> nums___ = {0,1,0,1,0,1,99};
    std::vector<int> nums2 = {0,1,0,1,0,1,99, 99, 99, -1, 2, 3, 3, 3, 2, -1, -1, 10, 10, 10, 20, 2};
    std::vector<int> nums3 = {2, 2, 3, 2};
    std::cout << singleNumber(nums4) << std::endl;
    return 0;
}
