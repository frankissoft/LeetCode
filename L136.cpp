#include <iostream>
#include <vector>
#include <set>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

int singleNumber(std::vector<int>& nums) {
    std::vector<int>::iterator p;
    while (nums.size() >= 0) {
        int num = nums[0];
        std::cout << "nums: " << nums << std::endl;
        p = std::find(nums.begin() + 1, nums.end(), num);
        if (p != nums.end()) {
            std::cout << "erase-p: " << *p << std::endl;
            std::cout << "begin: " << *nums.begin() << std::endl;
            std::cout << "erase-begin: " << *(nums.begin()) << std::endl;
            nums.erase(nums.begin());
            nums.erase(p);
            p = std::find(nums.begin(), nums.end(), num);
            std::cout << "erase-p: " << *p << std::endl;
            nums.erase(p);
        }
        else {
            std::cout << "*p: ";
            return nums[0];
        }
    }
    return nums[0];
}

int singleNumber2(std::vector<int>& nums) {
    std::set<int> alreadyExisted;
    // std::cout << alreadyExisted << std::endl;

    // std::set<int>::iterator ;
    for (int i = 0; i < nums.size(); i++) {
        if (alreadyExisted.find(nums[i]) != alreadyExisted.end()) {
            std::cout << "if-nums[i]: " << nums[i] << std::endl;
            alreadyExisted.erase(nums[i]);
        }
        else {
            alreadyExisted.insert(nums[i]);
            std::cout << "else-nums[i]: " << nums[i] << std::endl;

        }
    }
    // for (int i = 0; i < num.size();)
    return *(alreadyExisted.begin());
}

int main() {
    std::vector<int> nums = {2, 2, 1};
    std::vector<int> nums_ = {};
    std::vector<int> nums__ = {1, 1, 2, 2, 3, 3, 5, 5, 6, 6, 7, 7, 4};
    std::vector<int> nums___ = {0,1,0,1,0,1,99};
    std::vector<int> nums2 = {0,1,0,1,0,1,99, 99, 99, -1, 2, 3, 3, 3, 2, -1, -1, 10, 10, 10, 20, 2};
    std::vector<int> nums3 = {2, 2, 3, 2};
    std::cout << singleNumber(nums3) << std::endl;
    return 0;
}
