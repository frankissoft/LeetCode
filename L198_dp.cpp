#include <iostream>
#include <vector>

int rob(std::vector<int>& nums) {
    int size = nums.size();
    int dp[size + 1];
    if (size == 0) {
        return 0;
    }
    dp [0] = 0;
    dp [1] = nums[0];
    for (int i = 2; i < size + 1; i++) {
        dp[i] = std::max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp[size];
}
