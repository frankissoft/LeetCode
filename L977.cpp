#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> shifts = {3,5};
    std::vector<int>::iterator pos_3 = std::find(nums.begin(), nums.end(), 3);
    std::cout << *pos_3 << std::endl;
    std::vector<int>::iterator pos_2 = pos_3 - 1;
    std::cout << *pos_2 << std::endl;
    nums[1] = 3;
    return 0;
}
