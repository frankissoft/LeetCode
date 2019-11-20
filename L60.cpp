#include <iostream>
#include <string>
#include <vector>

std::string res;
int count = 0;

void permutationHelper(int n, std::string chosen, int k) {
    if (n == 0) {
        count++;
        if (count == k) {
            res = chosen;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            permutationHelper (n - 1, chosen + std::to_string(i), k);
        }
    }
}

std::string getPermutation(int n, int k) {
    permutationHelper(n, "", k);
    return res;
}

int main() {
    std::cout << getPermutation(3, 3) << std::endl;
    return 0;
}
