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

std::vector<int> subvec(std::vector<int> v, int m, int n) {
    std::vector<int>::const_iterator begin = v.begin() + m;
    std::vector<int>::const_iterator last = v.end() + n;
    std::vector<int> result;
    std::copy(begin, last, result.begin());
    return result;
}

void permuteHelper(std::vector<int> v, std::vector<int> chosen, std::vector<std::vector<int>>& ready) {
    if (v.empty()) {
        ready.push_back(chosen);
        return ;
    }
    for (int i = 0; i < v.size(); i++) {
        std::vector<int> a = chosen;
        a.push_back(v[0]);
        permuteHelper(subvec(v, 1, v.size()), a, ready);
        std::rotate(v.begin(), v.begin() + 1, v.end());
    }

}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> ready;
    permuteHelper(nums, {}, ready);
    return ready;
}

int main() {
    std::vector<int> nums = {1,2,3};
    std::cout << permute(nums) << std::endl;
    return 0;
}
