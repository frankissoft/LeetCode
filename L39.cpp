#include <iostream>
#include <string>
#include <vector>
#include <numeric>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

std::vector<int> v;

std::vector<int>& operator+(std::vector<int>& s, int t) {
    v = s;
    // for (std::size_t i = 0; i < t.size(); i++) {
    v.push_back(t);
    return v;
}

void indent(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "    ";
    }
}

std::vector<std::vector<int>> good;

int sumAll(std::vector<int> v) {
    int sum = 0;
    for (int i; i < v.size(); i++) {
        sum += v[i];
        std::cout << v[i] << std::endl;
    }
    return sum;
}

int target = 7;
std::vector<int> candidates {2, 3, 6, 7};
int comSize = target / candidates[0];


void sumHelper(int digits, std::vector<int> alreadyThere, int target) {
    indent(alreadyThere.size());
    int sum = std::accumulate(alreadyThere.begin(), alreadyThere.end(), 0);
    std::cout << "digits: " << digits << std::endl;
    if (sum == target) {
        good.push_back(alreadyThere);
    }
    if (digits == 0) {
        return ;
    } else {
        for (int i = 0; i < candidates.size(); i++) {
            // alreadyThere.push_back(candidates[i]);
            std::cout << "Candidate[" << i << "]: " << candidates[i] << std::endl;
            std::cout << "alreadyThere: " << alreadyThere << std::endl;
            sumHelper(digits - 1, alreadyThere + candidates[i], target);
        }
    }
}


std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    sumHelper(comSize, {}, target);
    return good;
}

int main() {
    std::cout << combinationSum(candidates, target) << std::endl;
    std::cout << "comSize: " << comSize << std::endl;
    return 0;
}
