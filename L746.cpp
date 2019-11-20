#include <iostream>
#include <vector>

std::set<std::pair<int, int>, int> cost_dict;
int c = 0;

std::vector<int> subvec(std::vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v.pop_back();
    }
    return v;
}

int minCostClimbingStairs(vector<int>& cost) {
    int step1 = 0, step2 = 0, result = 0;
    if (cost.size() == 1) {
        return cost[0];
    }
    step1 = cost[0];
    step2 = cost[1];
    for (int i = 2; i < cost.size(); i++){
        int tmp = step2;
        step2 = min(step1 + cost[i], step2 + cost[i]);
        step1 = tmp;
    }
    result = std::min(step1, step2);
    return result;
}
