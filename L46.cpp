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

void indent(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "    ";
    }
}

void permuteHelper(std::vector<int> v, std::vector<int> chosen, std::set<std::vector<int>>& alreadyPrinted) {
    // indent(chosen.size());
    // std::cout << "permuteHelper(" << v << ", " << chosen << ")" << std::endl;
    if (v.empty()) {
        // std::cout << "Here!" << std::endl;
        // auto search = alreadyPrinted.find(chosen);
        // if (search == alreadyPrinted.end()) {
            // std::cout << "chosen: " << chosen << std::endl;
            alreadyPrinted.insert(chosen);
        // }
    } else {
        for (int i = 0; i < v.size(); i++) {
            int hey = v[i];
            // int j = i;
            // std::cout << "v[i]: " << v[i] << std::endl;
            // std::vector::iterator hi = v.begin() + i;
            // choose
            chosen.push_back(hey);
            v.erase(v.begin() + i);
            // std::cout << "i: " << i << std::endl;
            // std::cout << "chosen: " << chosen << std::endl;
            // explore
            permuteHelper(v, chosen, alreadyPrinted);
            // unchoose
            v.insert(v.begin() + i, hey);
            chosen.pop_back();
        }
    }
    // std::cout << "aP.size(): " << alreadyPrinted.size() << std::endl;
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::set<std::vector<int>> alreadyPrinted;
    // std::vector<int> empty;
    permuteHelper(nums, {}, alreadyPrinted);
    std::vector<std::vector<int>> result(alreadyPrinted.begin(), alreadyPrinted.end());
    return result;
}

int main() {
    std::vector<int> nums = {1,2,3};
    std::cout << permute(nums) << std::endl;
    return 0;
}
