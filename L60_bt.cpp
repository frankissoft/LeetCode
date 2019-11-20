#include <iostream>
#include <string>
#include <vector>

int count = 0;
std::string result;
int flag = 0;
std::vector<int> v;
for (int i = 0; i < n; i++) {
    v.push_back(i + 1);
}

void permutationHelper(std::vector<int> v, std::string chosen, int k) {
    if (v.empty()) {
        count++; {
            if (count == k) {
                result = chosen;
                return ;
            }
        }
    } else {
        for (int i = 0; i < v.size(); i++) {
            int hey = v[i];
            // int j = i;
            // std::cout << "v[i]: " << v[i] << std::endl;
            // std::vector::iterator hi = v.begin() + i;
            // choose
            chosen += v[i] - '0';
            v.erase(v.begin() + i);
            // std::cout << "i: " << i << std::endl;
            // std::cout << "chosen: " << chosen << std::endl;
            // explore
            permutationHelper(v, chosen, k);
            // unchoose
            v.insert(v.begin() + i, hey);
            chosen.pop_back();
        }
    }
}

std::string getPermutation(int n, int k) {
    permutationHelper(v, "", k);
    return result;
}

int main() {
    std::cout << getPermutation(3, 3) << std::endl;
    return 0;
}
